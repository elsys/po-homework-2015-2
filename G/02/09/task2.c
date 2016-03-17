#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
char* find(char *haystack, char needle){
    int i;
    for (i = 0; i < strlen(haystack); ++i){
        if(haystack[i] == needle){
            return &haystack[i];
        }
    }
    return NULL;
}
int main(){
    int const arr = 400;
    char haystack[arr],*f, needle;
   
    scanf("%[^\n]s",haystack);
    getchar();
    scanf("%c", &needle);
    f = find(haystack, needle);
   
    if(f == NULL){
        printf("-1");
    }
    else{
        printf("%d", (int)(f-haystack));
    }
    return 0;
}
