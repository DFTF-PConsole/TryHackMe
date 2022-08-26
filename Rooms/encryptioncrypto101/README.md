# THM - Encryption - Crypto 101

<br>

## Task 2

https://en.wikipedia.org/wiki/Alice_and_Bob

### Task 2.2

> passphrase

<br>

## Task 3

https://listings.pcisecuritystandards.org/documents/PCI_DSS_for_Large_Organizations_v1.pdf

### Task 3.1

🧰 https://en.wikipedia.org/wiki/Secure_Shell

> Secure Shell

### Task 3.2

> certificate

### Task 3.3

> PCI-DSS

<br>

## Task 4

### Task 4.1

> 0

### Task 4.2

> 4

### Task 4.3

🧰 https://www.google.com/search?q=118613842+%25+9091

> 3565

<br>

## Task 5

### Task 5.1

> Nay

### Task 5.2

🧰 https://en.wikipedia.org/wiki/Data_Encryption_Standard#:~:text=The%20algorithm%20is%20believed%20to%20be%20practically%20secure%20in%20the%20form%20of%20Triple%20DES%2C%20although%20there%20are%20theoretical%20attacks.

> Triple DES

### Task 5.3

> Yea

<br>

## Task 6

https://github.com/RsaCtfTool/RsaCtfTool

https://github.com/ius/rsatool

https://muirlandoracle.co.uk/2020/01/29/rsa-encryption/

### Task 6.1

🧰 https://www.google.com/search?q=4391+*+6659

> 29239669

<br>

## Task 7

https://robertheaton.com/2014/03/27/how-does-https-actually-work/

https://letsencrypt.org/

<br>

## Task 8

### Task 8.1

> E1

<br>

## Task 9

🧰 https://tryhackme.com/room/linuxfundamentalspart2

```shell
ssh-keygen
	my_key
	^Enter
	^Enter


ssh-copy-id -i my_key.pub tryhackme@10.10.226.98
	tryhackme


chmod 600 my_key
sudo ssh -i my_key tryhackme@10.10.226.98
	yes
	
	ls ~/.ssh
	cat ~/.ssh/authorized_keys
	
	exit
```

### Task 9.3

> RSA

### Task 9.4

```shell
ssh2john idrsa.id_rsa > id_rsa_hash.txt

cat id_rsa_hash.txt

john --wordlist=../../Tools/KaliWordlists/rockyou.txt id_rsa_hash.txt
```

> delicious

<br>

## Task 10

https://www.youtube.com/watch?v=NmM9HA2MQGI

<br>

## Task 11

https://gnupg.org/

https://www.gnupg.org/gph/de/manual/r1023.html

https://www.youtube.com/watch?v=O4xNJsjtN6E

### Task 11.2

```shell
gpg --import gpg/tryhackme.key

gpg -o message.gpg.txt -d gpg/message.gpg
```

> Pineapple

<br>

## Task 12

https://doi.org/10.6028/NIST.IR.8105

Book: "Cryptography Apocalypse" By Roger A. Grimes

<br>
