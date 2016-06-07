# Assignment report
```
Points earned: 10
Maximum points: 17
```

## Task 1: ISBN [5/5 points]
https://github.com/elsys/po-homework/tree/master/A/04#%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0-1---isbn

### Testcase 1 passed
### Testcase 2 passed
### Testcase 3 passed

## Task 2: Doors [5/5 points]
https://github.com/elsys/po-homework/tree/master/A/04#%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0-2---doors

### Testcase 1 passed

## Task 3: Digits [0/7 points]
https://github.com/elsys/po-homework/tree/master/A/04#%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0-3---digits

Failed compiling

Exit code: 1

Error
```
task3.c: In function 'main':
task3.c:47:19: warning: passing argument 1 of 'combination_sort' from incompatible pointer type [-Wincompatible-pointer-types]
  combination_sort(combinations, variation_number);
                   ^
task3.c:7:6: note: expected 'char *' but argument is of type 'char (*)[22]'
 void combination_sort(char*, int);
      ^
task3.c: At top level:
task3.c:59:6: error: conflicting types for 'combination_sort'
 void combination_sort(char* combinations[512][SORTLEN], int variation_number){
      ^
task3.c:7:6: note: previous declaration of 'combination_sort' was here
 void combination_sort(char*, int);
      ^
task3.c: In function 'combination_sort':
task3.c:64:14: warning: passing argument 1 of 'strcmp' from incompatible pointer type [-Wincompatible-pointer-types]
    if(strcmp(combinations[i], combinations[i + 1]) < 0){
              ^
In file included from task3.c:3:0:
/usr/include/string.h:140:12: note: expected 'const char *' but argument is of type 'char **'
 extern int strcmp (const char *__s1, const char *__s2)
            ^
task3.c:64:31: warning: passing argument 2 of 'strcmp' from incompatible pointer type [-Wincompatible-pointer-types]
    if(strcmp(combinations[i], combinations[i + 1]) < 0){
                               ^
In file included from task3.c:3:0:
/usr/include/string.h:140:12: note: expected 'const char *' but argument is of type 'char **'
 extern int strcmp (const char *__s1, const char *__s2)
            ^
task3.c:65:19: warning: passing argument 2 of 'strcpy' from incompatible pointer type [-Wincompatible-pointer-types]
      strcpy(temp, combinations[i]);
                   ^
In file included from task3.c:3:0:
/usr/include/string.h:125:14: note: expected 'const char * restrict' but argument is of type 'char **'
 extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
              ^
task3.c:66:13: warning: passing argument 1 of 'strcpy' from incompatible pointer type [-Wincompatible-pointer-types]
      strcpy(combinations[i], combinations[i + 1]);
             ^
In file included from task3.c:3:0:
/usr/include/string.h:125:14: note: expected 'char * restrict' but argument is of type 'char **'
 extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
              ^
task3.c:66:30: warning: passing argument 2 of 'strcpy' from incompatible pointer type [-Wincompatible-pointer-types]
      strcpy(combinations[i], combinations[i + 1]);
                              ^
In file included from task3.c:3:0:
/usr/include/string.h:125:14: note: expected 'const char * restrict' but argument is of type 'char **'
 extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
              ^
task3.c:67:13: warning: passing argument 1 of 'strcpy' from incompatible pointer type [-Wincompatible-pointer-types]
      strcpy(combinations[i + 1], temp);
             ^
In file included from task3.c:3:0:
/usr/include/string.h:125:14: note: expected 'char * restrict' but argument is of type 'char **'
 extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
              ^

```
