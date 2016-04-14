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
task3.c:47:19: warning: passing argument 1 of 'combination_sort' makes integer from pointer without a cast [-Wint-conversion]
  combination_sort(combinations, variation_number);
                   ^
task3.c:7:6: note: expected 'char' but argument is of type 'char (*)[22]'
 void combination_sort(char, int);
      ^
task3.c: At top level:
task3.c:59:6: error: conflicting types for 'combination_sort'
 void combination_sort(char combinations[512][SORTLEN], int variation_number){
      ^
task3.c:7:6: note: previous declaration of 'combination_sort' was here
 void combination_sort(char, int);
      ^

```
