# THM - Crack the hash

https://crackstation.net/

https://www.tunnelsup.com/hash-analyzer/


```shell
john -format=bcrypt hash.txt

john -format=bcrypt -length=4 --wordlist=rockyou.txt hash.txt

hashcat -m 3200 hash.txt rockyou.txt

john -length=6 --wordlist=rockyou.txt hash.txt

john -length=12 --wordlist=rockyou.txt hash.txt

echo "e5d8870e5bdd26602cab8dbe07a942c8669e56d6:tryhackme" > hash.txt
hashcat -a 3 -m 160 -i --increment-min=12 --increment-max=12 hash.txt rockyou.txt

hashcat -m 160 hash.txt rockyou.txt

john -format=hmac-sha1 -mask:tryhackme -length=12 hash.txt
```
