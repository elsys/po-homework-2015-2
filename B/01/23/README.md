# Assignment report
```
Points earned: 2
Maximum points: 19
```

## Task 1: Hash [2/5 points]
https://github.com/elsys/po-homework/tree/master/B/01#%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0-1

Compiled with warning(s)
```
task1.c: In function 'hash':
task1.c:8:5: warning: implicit declaration of function 'strlen' [-Wimplicit-function-declaration]
     int len = strlen(text), i;
     ^
task1.c:8:15: warning: incompatible implicit declaration of built-in function 'strlen'
     int len = strlen(text), i;
               ^
task1.c: In function 'main':
task1.c:20:18: warning: passing argument 1 of 'hash' makes integer from pointer without a cast
     value = hash(text);
                  ^
task1.c:5:6: note: expected 'char' but argument is of type 'char *'
 long hash(char word)
      ^

```
### Testcase 1 passed
### Testcase 2 passed
### Testcase 3 passed

## Task 2: Occurances [0/7 points]
https://github.com/elsys/po-homework/tree/master/B/01#%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0-2

Compiled with warning(s)
```
task2.c: In function 'hash':
task2.c:14:5: warning: implicit declaration of function 'strlen' [-Wimplicit-function-declaration]
     len = strlen(text);
     ^
task2.c:14:11: warning: incompatible implicit declaration of built-in function 'strlen'
     len = strlen(text);
           ^
task2.c: In function 'main':
task2.c:35:29: warning: passing argument 1 of 'hash' makes integer from pointer without a cast
         word[i].hash = hash(text);
                             ^
task2.c:10:6: note: expected 'char' but argument is of type 'char *'
 long hash(char word)
      ^
task2.c:46:5: warning: format '%d' expects argument of type 'int', but argument 3 has type 'long int' [-Wformat=]
     printf("%d %d",word[top].amount, word[top].hash);
     ^

```
### Testcase 1 failed
### Testcase 2 failed
### Testcase 3 failed

## Task 3: Collisions [0/7 points]
https://github.com/elsys/po-homework/tree/master/B/01#%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0-3

### Not submitted
