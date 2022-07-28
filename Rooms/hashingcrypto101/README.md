# THM - Hashing - Crypto 101

```shell
cat ../../Materials/KaliWordlists/rockyou.txt | awk '{ print length, $0 }' | sort -n -s | cut -d" " -f2- > rockyou-sort.txt

nano hash.txt

john hash.txt --format=sha512crypt --wordlist=../../Materials/KaliWordlists/rockyou.txt

john hash.txt --wordlist=../../Materials/KaliWordlists/rockyou.txt
```
