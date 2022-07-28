# THM - Content Discovery

```shell
curl https://static-labs.tryhackme.cloud/sites/favicon/images/favicon.ico | md5sum
```

https://wiki.owasp.org/index.php/OWASP_favicon_database

```shell
curl http://10.10.107.92 -v
```

S3 Buckets

http(s)://{name}.s3.amazonaws.com

```shell
ffuf -w ../../Materials/SecLists/Discovery/Web-Content/common.txt -u http://10.10.107.92/FUZZ

dirb http://10.10.107.92/ ../../Materials/SecLists/Discovery/Web-Content/common.txt

gobuster dir --url http://10.10.107.92/ -w ../../Materials/SecLists/Discovery/Web-Content/common.txt
```
