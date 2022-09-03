# THM - Active Directory Basics

<br>

## Task 2

### Task 2.1

> Active Directory

### Task 2.2

> Domain Controller

<br>

(Terminal 1:)
```bash
xfreerdp /dynamic-resolution +clipboard /cert:ignore /v:10.10.93.236 /d:'THM' /u:'Administrator' /p:'Password321'
```

<br>

## Task 3

https://docs.microsoft.com/en-us/windows-server/identity/ad-ds/manage/understand-security-groups

### Task 3.1

> Domain Admins

### Task 3.2

> TOM-PC$

### Task 3.3

> Organizational Units

<br>

## Task 4

(Terminal 2:)
```bash
xfreerdp /dynamic-resolution +clipboard /cert:ignore /v:10.10.93.236 /d:'THM' /u:'phillip' /p:'Claire2008'
```

(RDP 2/Powershell:)
```powershell
Set-ADAccountPassword sophie -Reset -NewPassword (Read-Host -AsSecureString -Prompt 'New Password') -Verbose
	Dftf2022
	
Set-ADUser -ChangePasswordAtLogon $true -Identity sophie -Verbose
```

### Task 4.1

(Terminal 2:)
```bash
	^C

xfreerdp /dynamic-resolution +clipboard /cert:ignore /v:10.10.93.236 /d:'THM' /u:'sophie' /p:'Dftf2022'
```

> THM{thanks_for_contacting_support}

### Task 4.2

> Delegation

<br>

## Task 5

### Task 5.1

> 7

### Task 5.2

> yay

<br>

## Task 6

(Terminal 2:)
```bash
	^C

xfreerdp /dynamic-resolution +clipboard /cert:ignore /v:10.10.93.236 /d:'THM' /u:'Mark' /p:'M4rk3t1ng.21'
```

### Task 6.1

> SYSVOL

### Task 6.2

> yay

<br>

## Task 7

### Task 7.1

> nay

### Task 7.2

> Ticket Granting Ticket

### Task 7.3

> nay

<br>

## Task 8

### Task 8.1

> tree

### Task 8.2

> A Trust Relationships


