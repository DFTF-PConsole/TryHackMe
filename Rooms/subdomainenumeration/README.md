# THM - Subdomain Enumeration

https://crt.sh

-site:www.tryhackme.com  site:*.tryhackme.com

```shell
dnsrecon -t brt -d acmeitsupport.thm

./sublist3r.py -d acmeitsupport.thm

ffuf -w ../../Materiais/SecLists/Discovery/DNS/namelist.txt -H "Host: FUZZ.acmeitsupport.thm" -u http://10.10.244.228

ffuf -w ../../Materiais/SecLists/Discovery/DNS/namelist.txt -H "Host: FUZZ.acmeitsupport.thm" -u http://10.10.244.228 -fs 2395
```






