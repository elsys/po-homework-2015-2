# Assignment report
```
Points earned: 5
Maximum points: 17
```

## Task 1: ISBN [5/5 points]
https://github.com/elsys/po-homework/tree/master/A/04#%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0-1---isbn

### Testcase 1 passed
### Testcase 2 passed
### Testcase 3 passed

## Task 2: Doors [0/5 points]
https://github.com/elsys/po-homework/tree/master/A/04#%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0-2---doors

Failed compiling

Exit code: 1

Error
```
task2.c:1:9: error: expected '=', ',', ';', 'asm' or '__attribute__' before '<' token
 include <stdio.h>
         ^
In file included from task2.c:2:0:
/usr/include/string.h:43:8: error: unknown type name 'size_t'
        size_t __n) __THROW __nonnull ((1, 2));
        ^
/usr/include/string.h:46:56: error: unknown type name 'size_t'
 extern void *memmove (void *__dest, const void *__src, size_t __n)
                                                        ^
/usr/include/string.h:62:42: error: unknown type name 'size_t'
 extern void *memset (void *__s, int __c, size_t __n) __THROW __nonnull ((1));
                                          ^
/usr/include/string.h:65:56: error: unknown type name 'size_t'
 extern int memcmp (const void *__s1, const void *__s2, size_t __n)
                                                        ^
/usr/include/string.h:92:48: error: unknown type name 'size_t'
 extern void *memchr (const void *__s, int __c, size_t __n)
                                                ^
/usr/include/string.h:129:39: error: unknown type name 'size_t'
         const char *__restrict __src, size_t __n)
                                       ^
/usr/include/string.h:137:9: error: unknown type name 'size_t'
         size_t __n) __THROW __nonnull ((1, 2));
         ^
/usr/include/string.h:143:57: error: unknown type name 'size_t'
 extern int strncmp (const char *__s1, const char *__s2, size_t __n)
                                                         ^
/usr/include/string.h:150:8: error: unknown type name 'size_t'
 extern size_t strxfrm (char *__restrict __dest,
        ^
/usr/include/string.h:151:40: error: unknown type name 'size_t'
          const char *__restrict __src, size_t __n)
                                        ^
/usr/include/string.h:280:8: error: unknown type name 'size_t'
 extern size_t strcspn (const char *__s, const char *__reject)
        ^
/usr/include/string.h:284:8: error: unknown type name 'size_t'
 extern size_t strspn (const char *__s, const char *__accept)
        ^
/usr/include/string.h:394:8: error: unknown type name 'size_t'
 extern size_t strlen (const char *__s)
        ^
/usr/include/string.h:446:33: error: unknown type name 'size_t'
 extern void __bzero (void *__s, size_t __n) __THROW __nonnull ((1));
                                 ^
task2.c: In function 'main':
task2.c:11:14: warning: implicit declaration of function 'getchar' [-Wimplicit-function-declaration]
         s[i]=getchar();
              ^
task2.c:12:18: error: 'EOF' undeclared (first use in this function)
         if(s[i]==EOF)
                  ^
task2.c:12:18: note: each undeclared identifier is reported only once for each function it appears in
task2.c:47:13: warning: implicit declaration of function 'printf' [-Wimplicit-function-declaration]
             printf("Door: CLOSED\n");
             ^
task2.c:47:13: warning: incompatible implicit declaration of built-in function 'printf'
task2.c:47:13: note: include '<stdio.h>' or provide a declaration of 'printf'
task2.c:49:13: warning: incompatible implicit declaration of built-in function 'printf'
             printf("Door: OPENING\n");
             ^
task2.c:49:13: note: include '<stdio.h>' or provide a declaration of 'printf'
task2.c:51:13: warning: incompatible implicit declaration of built-in function 'printf'
             printf("Door: OPEN\n");
             ^
task2.c:51:13: note: include '<stdio.h>' or provide a declaration of 'printf'
task2.c:53:13: warning: incompatible implicit declaration of built-in function 'printf'
             printf("Door: CLOSING\n");
             ^
task2.c:53:13: note: include '<stdio.h>' or provide a declaration of 'printf'
task2.c:55:13: warning: incompatible implicit declaration of built-in function 'printf'
             printf("Door: STOPPED_WHILE_CLOSING\n");
             ^
task2.c:55:13: note: include '<stdio.h>' or provide a declaration of 'printf'
task2.c:57:13: warning: incompatible implicit declaration of built-in function 'printf'
             printf("Door: STOPPED_WHILE_OPENING\n");
             ^
task2.c:57:13: note: include '<stdio.h>' or provide a declaration of 'printf'

```

## Task 3: Digits [0/7 points]
https://github.com/elsys/po-homework/tree/master/A/04#%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0-3---digits

Failed compiling

Exit code: 1

Error
```
task3.c: In function 'main':
task3.c:10:13: warning: unused variable 'check' [-Wunused-variable]
  int result,check = 0;
             ^
task3.c: In function 'check_result':
task3.c:30:2: warning: suggest parentheses around assignment used as truth value [-Wparentheses]
  if(result = check){
  ^
task3.c:33:3: error: too few arguments to function 'check_result'
   check_result();
   ^
task3.c:25:5: note: declared here
 int check_result(unsigned int len,int result, int nums[]){
     ^
task3.c: In function 'takeDigits':
task3.c:22:1: warning: control reaches end of non-void function [-Wreturn-type]
 }
 ^
task3.c: In function 'check_result':
task3.c:35:1: warning: control reaches end of non-void function [-Wreturn-type]
 }
 ^

```
