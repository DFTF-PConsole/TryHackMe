# THM - Nmap

```shell
iptables -I INPUT -p tcp --dport <port> -j REJECT --reject-with tcp-reset

ping 10.10.118.57

sudo nmap -Pn -p1-999 -sX 10.10.118.57 -vv

sudo nmap -p1-10000 -sS 10.10.118.57 -vv -Pn

sudo nmap --script=ftp-anon -p21 10.10.118.57 -vv -Pn

ftp 10.10.118.57
	anonymous
```
