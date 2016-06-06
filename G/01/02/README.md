# Assignment report
```
Points earned: 2
Maximum points: 19
```

## Task 1: Hash [2/5 points]
https://github.com/elsys/po-homework/tree/master/B/01#%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0-1

Compiled with warning(s)
```
task1.c: In function 'main':
task1.c:27:7: warning: format '%s' expects argument of type 'char *', but argument 2 has type 'char (*)[200]' [-Wformat=]
 scanf("%s",&word);
       ^

```
### Testcase 1 passed
### Testcase 2 passed
### Testcase 3 failed

## Task 2: Occurances [0/7 points]
https://github.com/elsys/po-homework/tree/master/B/01#%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0-2

Failed compiling

Exit code: 1

Error
```
task2.c: In function 'hash':
task2.c:14:5: error: 'i' undeclared (first use in this function)
     i=0;
     ^
task2.c:14:5: note: each undeclared identifier is reported only once for each function it appears in
task2.c:19:1: error: 'hash_of_word' undeclared (first use in this function)
 hash_of_word +=word[i]*(i+1);
 ^
task2.c:12:10: warning: unused variable 'hash' [-Wunused-variable]
     long hash = 42;
          ^
task2.c: At top level:
task2.c:24:5: error: expected identifier or '(' before 'return'
     return hash;
     ^
task2.c:25:1: error: expected identifier or '(' before '}' token
 }
 ^
task2.c: In function 'main':
task2.c:35:18: warning: passing argument 1 of 'scanf' from incompatible pointer type [-Wincompatible-pointer-types]
     while (scanf(stdin, "%s", word)){
                  ^
In file included from /usr/include/features.h:361:0,
                 from /usr/include/stdio.h:27,
                 from task2.c:2:
/usr/include/stdio.h:446:12: note: expected 'const char * restrict' but argument is of type 'struct _IO_FILE *'
 extern int __REDIRECT (scanf, (const char *__restrict __format, ...),
            ^
task2.c: In function 'hash':
task2.c:23:5: warning: control reaches end of non-void function [-Wreturn-type]
     }
     ^

```

## Task 3: Collisions [0/7 points]
https://github.com/elsys/po-homework/tree/master/B/01#%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0-3

### Not submitted
