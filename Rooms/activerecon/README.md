# THM - Active Reconnaissance

<br>

## Task 2

### Task 2.1

https://static-labs.tryhackme.cloud/sites/networking-tcp/

Inspect/Developer Tools on Firefox->Debugger->Source->script.js:
```javascript
	8   :   {
        'speaking'  :  'alice',
        'answer_1'  :  'SYN : Connected',
        'answer_2'  :  'ACK : Okay, Goodbye',
        'answer_3'  :  'SYN/ACK : Not Received',
        'answer'    :   2
    }
```

> 8

<br>

## Task 3

### Task 3.1

```bash
man ping | grep size
```

> -s

### Task 3.2

```bash
man ping | grep header
```

> 8

### Task 3.3

> Y

### Task 3.4

```bash
mkdir logs
ping -c 10 10.10.42.232 | tee logs/ping_1.txt
```

> 10

<br>

## Task 4

### Task 4.1

>  172.67.69.208

### Task 4.2

> 104.26.11.229

### Task 4.3

> 26

<br>

```bash
traceroute 10.10.42.232 | tee logs/traceroute_1.txt
```

<br>

## Task 5

### Task 5.1

```bash
telnet 10.10.42.232 80 | tee logs/telnet_1.txt
	GET / HTTP/1.1
	host: telnet
	
	^Enter
```

> Apache

### Task 5.2

> 2.4.10

<br>

## Task 6

### Task 6.1

```bash
nc 10.10.40.28 21 | tee logs/nc_1.txt
```

> 0.17

<br>

