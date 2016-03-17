# Assignment report
```
Points earned: 0
Maximum points: 19
```

## Task 1: Hash [0/5 points]
https://github.com/elsys/po-homework/tree/master/B/01#%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0-1

Failed compiling

Exit code: 0

Error
```
task1.c: In function âmainâ:
task1.c:27:1: warning: format â%sâ expects argument of type âchar *â, but argument 2 has type âchar (*)[200]â [-Wformat=]
 scanf("%s",&word);
 ^

```

## Task 2: Occurances [0/7 points]
https://github.com/elsys/po-homework/tree/master/B/01#%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0-2

Failed compiling

Exit code: 1

Error
```
task2.c: In function âhashâ:
task2.c:14:5: error: âiâ undeclared (first use in this function)
     i=0;
     ^
task2.c:14:5: note: each undeclared identifier is reported only once for each function it appears in
task2.c:19:1: error: âhash_of_wordâ undeclared (first use in this function)
 hash_of_word +=word[i]*(i+1);
 ^
task2.c:12:10: warning: unused variable âhashâ [-Wunused-variable]
     long hash = 42;
          ^
task2.c: At top level:
task2.c:24:5: error: expected identifier or â(â before âreturnâ
     return hash;
     ^
task2.c:25:1: error: expected identifier or â(â before â}â token
 }
 ^
task2.c: In function âmainâ:
task2.c:35:18: warning: passing argument 1 of âscanfâ from incompatible pointer type
     while (scanf(stdin, "%s", word)){
                  ^
In file included from /usr/include/features.h:374:0,
                 from /usr/include/stdio.h:27,
                 from task2.c:2:
/usr/include/stdio.h:446:12: note: expected âconst char * restrictâ but argument is of type âstruct _IO_FILE *â
 extern int __REDIRECT (scanf, (const char *__restrict __format, ...),
            ^
task2.c: In function âhashâ:
task2.c:23:5: warning: control reaches end of non-void function [-Wreturn-type]
     }
     ^

```

## Task 3: Collisions [0/7 points]
https://github.com/elsys/po-homework/tree/master/B/01#%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0-3

### Not submitted
