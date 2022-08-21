# THM - Active Directory Basics

<br>

## Task 2

### Task 2.1

> NTDS.dit

### Task 2.2

> %SystemRoot%\NTDS

### Task 2.3

> Windows Server

<br>

## Task 3

### Task 3.1

> Tree

### Task 3.2

> Domain Schema

### Task 3.3

> Organizational Units

<br>

## Task 4

### Task 4.1

> Security Groups

### Task 4.2

> Domain Computers

### Task 4.3

> Cert Publishers

### Task 4.4

> Local Administrators

### Task 4.5

> Allowed RODC Password Replication Group

<br>

## Task 5

### Task 5.1

> Directional

### Task 5.2

> Transitive

<br>

## Task 6

### Task 6.1

> Kerberos

### Task 6.2

> Certificate Services

<br>

## Task 7

### Task 7.1

> Rest APIs

### Task 7.2

> Tenants

### Task 7.3

> Trusts

<br>

## Task 8

```shell
ssh Administrator:CONTROLLER.local@10.10.171.137
	yes
	password123@
	
	cd Downloads
	powershell -ep bypass
	. .\PowerView.ps1
	
	Get-NetComputer -fulldata | select operatingsystem
```

🧰 https://gist.github.com/HarmJ0y/184f9822b195c52dd50c379ed3117993

### Task 8.2

```shell
	Get-NetComputer -fulldata | select operatingsystem
```

> Windows 10 Enterprise Evaluation

### Task 8.3

```shell
	Get-NetUser | select cn
```

> Admin2

### Task 8.4

```shell
	Get-NetGroup -GroupName *
```

> Hyper-V Administrators

### Task 8.5

```shell
	Get-NetUser -SPN | ?{$_.memberof -match 'Domain Admins'}
```

> 5/13/2020 8:26:58 PM

<br>

