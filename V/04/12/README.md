# Assignment report
```
Points earned: 2
Maximum points: 17
```

## Task 1: ISBN [2/5 points]
https://github.com/elsys/po-homework/tree/master/A/04#%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0-1---isbn

Compiled with warning(s)
```
task1.c: In function 'valid_isbn':
task1.c:67:5: warning: the address of 'check_sum' will always evaluate as 'true' [-Waddress]
  if(check_sum){
     ^

```
### Testcase 1 failed
### Testcase 2 passed
### Testcase 3 passed

## Task 2: Doors [0/5 points]
https://github.com/elsys/po-homework/tree/master/A/04#%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0-2---doors

### Testcase 1 failed

## Task 3: Digits [0/7 points]
https://github.com/elsys/po-homework/tree/master/A/04#%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0-3---digits

Compiled with warning(s)
```
task3.c: In function 'main':
task3.c:16:2: warning: implicit declaration of function 'permute' [-Wimplicit-function-declaration]
  permute(nums,0,len);
  ^
task3.c: At top level:
task3.c:35:6: warning: conflicting types for 'permute'
 void permute(int array[],int i, int len){
      ^
task3.c:16:2: note: previous implicit declaration of 'permute' was here
  permute(nums,0,len);
  ^
task3.c: In function 'permute':
task3.c:37:10: warning: 'return' with a value, in function returning void
   return -1;
          ^
task3.c: In function 'check_result':
task3.c:70:4: warning: suggest parentheses around assignment used as truth value [-Wparentheses]
    if(i = 0 && nums[i] > 0){
    ^
task3.c:73:5: warning: 'return' with no value, in function returning non-void
     return;
     ^
task3.c: In function 'takeDigits':
task3.c:33:1: warning: control reaches end of non-void function [-Wreturn-type]
 }
 ^

```
### Testcase 1 failed
### Testcase 2 failed
Execution took more than 1 seconds
### Testcase 3 failed
