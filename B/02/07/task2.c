#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char* find(char *haystack, char needle);
int main(){
    char haystack[400], needle;
    fgets(haystack,400,stdin);
    scanf(" %c", &needle);
    if (find(haystack,needle)) printf("%d", find(haystack,needle) - haystack);
    else printf("-1");
    return 0;
}
char* find(char *haystack, char needle){
    int i;
    for(i=0;i<strlen(haystack);i++){
        if (needle == haystack[i]){
            return &haystack[i];
        }
    }
    return NULL;
}
