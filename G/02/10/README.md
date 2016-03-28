# Assignment report
```
Points earned: 0
Maximum points: 26
```

## Task 1: Minimax [0/7 points]
https://github.com/elsys/po-homework/tree/master/A/02#%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0-1---%D0%9C%D0%B8%D0%BD%D0%B8%D0%BC%D0%B0%D0%BA%D1%81

Failed compiling

Exit code: 1

Error
```
task1.c: In function 'main':
task1.c:9:1: warning: ISO C forbids nested functions [-Wpedantic]
 void minmax(int arr, int size, int min, int *max){
 ^
task1.c: In function 'minmax':
task1.c:12:17: error: subscripted value is neither array nor pointer nor vector
         if ( arr[c] < *min ) 
                 ^
task1.c:12:23: error: invalid type argument of unary '*' (have 'int')
         if ( arr[c] < *min ) 
                       ^
task1.c:14:12: error: invalid type argument of unary '*' (have 'int')
            *min = arr[c];
            ^
task1.c:14:22: error: subscripted value is neither array nor pointer nor vector
            *min = arr[c];
                      ^
task1.c:21:12: error: subscripted value is neither array nor pointer nor vector
     if (arr[c] > *max)
            ^
task1.c:23:18: error: subscripted value is neither array nor pointer nor vector
       *max  = arr[c];
                  ^
task1.c:28:16: error: invalid type argument of unary '*' (have 'int')
  target=*max + *min;
                ^
task1.c: In function 'main':
task1.c:48:8: warning: passing argument 1 of 'minmax' makes integer from pointer without a cast
 minmax(arr,size,&minimum,&maximum);
        ^
task1.c:9:6: note: expected 'int' but argument is of type 'int *'
 void minmax(int arr, int size, int min, int *max){
      ^
task1.c:48:17: warning: passing argument 3 of 'minmax' makes integer from pointer without a cast
 minmax(arr,size,&minimum,&maximum);
                 ^
task1.c:9:6: note: expected 'int' but argument is of type 'int *'
 void minmax(int arr, int size, int min, int *max){
      ^

```

## Task 2: Seek & !Destroy [0/7 points]
https://github.com/elsys/po-homework/tree/master/A/02#%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0-2---seek--destroy

Failed compiling

Exit code: 1

Error
```
task2.c: In function 'find':
task2.c:7:25: warning: passing argument 1 of 'strlen' makes pointer from integer without a cast
  for (i = 0; i < strlen(haystack); ++i)
                         ^
In file included from task2.c:2:0:
/usr/include/string.h:399:15: note: expected 'const char *' but argument is of type 'char'
 extern size_t strlen (const char *__s)
               ^
task2.c:9:14: error: subscripted value is neither array nor pointer nor vector
   if(haystack[i] == needle)
              ^
task2.c:11:20: error: subscripted value is neither array nor pointer nor vector
    return &haystack[i];
                    ^
task2.c: In function 'main':
task2.c:41:17: warning: passing argument 1 of 'find' makes integer from pointer without a cast
  needle1 = find(arr, needle);
                 ^
task2.c:4:6: note: expected 'char' but argument is of type 'char *'
 char find(char haystack, char needle)
      ^
task2.c:41:10: warning: assignment makes pointer from integer without a cast
  needle1 = find(arr, needle);
          ^
task2.c:36:8: warning: variable 'needle1' set but not used [-Wunused-but-set-variable]
  char *needle1;
        ^
task2.c: In function 'pos':
task2.c:31:1: warning: control reaches end of non-void function [-Wreturn-type]
 }
 ^

```

## Task 3: Za.io [0/12 points]
https://github.com/elsys/po-homework/tree/master/A/02#%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0-3---zaio

### Not submitted
