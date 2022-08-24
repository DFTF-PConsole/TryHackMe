# THM - John The Ripper

<br>

## Task 2

https://github.com/openwall/john

### Task 2.1

> Jumbo John

<br>

## Task 3

https://github.com/danielmiessler/SecLists

### Task 3.1

> rockyou.com

<br>

## Task 4

https://hashes.com/en/tools/hash_identifier

https://gitlab.com/kalilinux/packages/hash-identifier/-/tree/kali/master

### Task 4.1

```shell
cat first_task_hashes/hash1.txt

haiti '2e728dd31fb5949bc39cac5a9f066498'
```

> MD5

### Task 4.2

```shell
john --format=raw-md5 --wordlist=../../Tools/KaliWordlists/rockyou.txt first_task_hashes/hash1.txt
```

> biscuit

### Task 4.3

```shell
cat first_task_hashes/hash2.txt

haiti '1A732667F3917C0F4AA98BB13011B9090C6F8065'
```

> SHA1

### Task 4.4

```shell
john --format=raw-sha1 --wordlist=../../Tools/KaliWordlists/rockyou.txt first_task_hashes/hash2.txt
```

> kangeroo

### Task 4.5

```shell
cat first_task_hashes/hash3.txt

haiti 'D7F4D3CCEE7ACD3DD7FAD3AC2BE2AAE9C44F4E9B7FB802D73136D4C53920140A'
```

> SHA256

### Task 4.6

```shell
john --format=raw-sha256 --wordlist=../../Tools/KaliWordlists/rockyou.txt first_task_hashes/hash3.txt
```

> microphone

### Task 4.7

```shell
cat first_task_hashes/hash4.txt

haiti 'c5a60cc6bbba781c601c5402755ae1044bbf45b78d1183cbf2ca1c865b6c792cf3c6b87791344986c8a832a0f9ca8d0b4afd3d9421a149d57075e1b4e93f90bf'
```

> Whirlpool

### Task 4.8

```shell
john --format=whirlpool --wordlist=../../Tools/KaliWordlists/rockyou.txt first_task_hashes/hash4.txt
```

> colossal

<br>

## Task 5

### Task 5.1

```shell
cat ntlm.txt

haiti '5460C85BD858A11475115D2DD3A82333'
```

> nt

### Task 5.2

```shell
john --format=nt --wordlist=../../Tools/KaliWordlists/rockyou.txt ntlm.txt
```

> mushroom

<br>

## Task 6

### Task 6.1

```shell
cat etchashes.txt

echo 'root:x:0:0::/root:/bin/bash' > local_passwd
echo 'root:$6$Ha.d5nGupBm29pYr$yugXSk24ZljLTAZZagtGwpSQhb3F2DOJtnHrvk7HI2ma4GsuioHp8sm3LJiRJpKfIf7lZQ29qgtH17Q/JDpYM/:18576::::::' > local_shadow

unshadow local_passwd local_shadow > unshadowed.txt

cat unshadowed.txt
haiti '$6$Ha.d5nGupBm29pYr$yugXSk24ZljLTAZZagtGwpSQhb3F2DOJtnHrvk7HI2ma4GsuioHp8sm3LJiRJpKfIf7lZQ29qgtH17Q/JDpYM/'

john --format=sha512crypt --wordlist=../../Tools/KaliWordlists/rockyou.txt unshadowed.txt
```

> 1234

<br>

## Task 7

### Task 7.1

```shell
cat hash7.txt

haiti '7bf6d9bb82bed1302f331fc6b816aada'

echo 'Joker:7bf6d9bb82bed1302f331fc6b816aada' > hash7_joker.txt

john --single --format=raw-md5 hash7_joker.txt
```

> Jok3r

<br>

## Task 8

```shell
cat /etc/john/john.conf
cat /etc/john/john-local.conf
```

https://www.openwall.com/john/doc/RULES.shtml

### Task 8.1

> password complexity predictability

### Task 8.2

> Az"[A-Z]"

### Task 8.3

> --rule=THMRules

<br>

## Task 9

### Task 9.1

```shell
zip2john secure.zip > zip_hash.txt

cat zip_hash.txt

haiti '$pkzip$1*2*2*0*26*1a*849ab5a6*0*48*0*26*b689*964fa5a31f8cefe8e6b3456b578d66a08489def78128450ccf07c28dfa6c197fd148f696e3a2*$/pkzip$'

john --format=pkzip --wordlist=../../Tools/KaliWordlists/rockyou.txt zip_hash.txt

unzip secure.zip
	pass123
```

> pass123

### Task 9.2

```shell
cat zippy/flag.txt
```

> THM{w3ll_d0n3_h4sh_r0y4l}

<br>

## Task 10

### Task 10.1

```shell
rar2john secure.rar > rar_hash.txt

cat rar_hash.txt

haiti '$rar5$16$b7b0ffc959b2bc55ffb712fc0293159b$15$4f7de6eb8d17078f4b3c0ce650de32ff$8$ebd10bb79dbfb9f8'

john --format=rar5 --wordlist=../../Tools/KaliWordlists/rockyou.txt rar_hash.txt

unrar e secure.rar
	password
```

> password

### Task 10.2

```shell
cat flag.txt
```

> THM{r4r_4rch1ve5_th15_t1m3}

<br>

## Task 11

### Task 11.1

```shell
ssh2john idrsa.id_rsa > id_rsa_hash.txt

cat id_rsa_hash.txt

john --wordlist=../../Tools/KaliWordlists/rockyou.txt id_rsa_hash.txt
```

> mango

<br>

