# THM - Passive Reconnaissance

<br>

## Task 1

https://dnsdumpster.com/

https://www.shodan.io/

## Task 2

https://www.unifiedkillchain.com/

### Task 2.1

> P

### Task 2.2

> A

### Task 2.3

> A

<br>

## Task 3

https://www.ietf.org/rfc/rfc3912.txt

<br>


```bash
whois tryhackme.com | tee whois_tryhackme.txt
```

### Task 3.1

> 20180705

### Task 3.2

> namecheap.com

### Task 3.3

> cloudflare.com

<br>

## Task 4

https://duckduckgo.com/?q=public+dns

### Task 4.1

```bash
nslookup -type=txt thmlabs.com 1.1.1.1 | tee nslookup_thmlabs.txt

dig @1.1.1.1 thmlabs.com txt | tee dig_thmlabs.txt
```

> THM{a5b83929888ed36acb0272971e438d78}

<br>

## Task 5

https://dnsdumpster.com/

### Task 5.1

> remote

<br>

## Task 6

https://www.shodan.io/

https://help.shodan.io/the-basics/search-query-fundamentals

### Task 6.1

https://www.shodan.io/search?query=Apache

https://www.shodan.io/search/facet?query=Apache&facet=country

> Germany

### Task 6.2

https://www.shodan.io/search/facet?query=Apache&facet=port

> 8080

### Task 6.3

https://www.shodan.io/search/facet?query=nginx&facet=port

> 8888

<br>

