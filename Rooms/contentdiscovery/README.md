# THM - Content Discovery

```shell
curl https://static-labs.tryhackme.cloud/sites/favicon/images/favicon.ico | md5sum
```

<br>

https://wiki.owasp.org/index.php/OWASP_favicon_database

<br>

```shell
curl http://10.10.107.92 -v
```

<br>

S3 Buckets
<br>
http(s)://{name}.s3.amazonaws.com

<br>

```shell
ffuf -w ../../Materiais/SecLists/Discovery/Web-Content/common.txt -u http://10.10.107.92/FUZZ

dirb http://10.10.107.92/ ../../Materiais/SecLists/Discovery/Web-Content/common.txt

gobuster dir --url http://10.10.107.92/ -w ../../Materiais/SecLists/Discovery/Web-Content/common.txt
```
