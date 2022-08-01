# THM - SSRF

<br>

## Task 1

### Task 1.1

> Server-Side Request Forgery


### Task 1.2

> Blind 

<br>

## Task 2

### Task 2.1

https://website.thm/item/2?server=server.website.thm/flag?id=9&x=

> THM{SSRF_MASTER}

<br>

## Task 3

### Task 3.1

> requestbin.com

<br>

## Task 4

### Task 4.1

> Open Redirect

### Task 4.2

> 169.254.169.254

### Task 4.3

> Allow List

### Task 4.4

> Deny List

<br>

## Task 5

### Task 5.1

https://10-10-165-84.p.thmlabs.com

https://10-10-165-84.p.thmlabs.com/customers/new-account-page

value="x/../private"

```shell
echo "VEhNe1lPVV9XT1JLRURfT1VUX1RIRV9TU1JGfQ==" | base64 -d
```

> THM{YOU_WORKED_OUT_THE_SSRF}


