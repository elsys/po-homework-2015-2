#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* find(char*, char);

int main(){
    char* haystack = (char*)malloc(sizeof(char)*400);
    char needle, c;
    int i;
    for(i = 0; c != '\n'; i++){
        haystack[i] = getchar();
        c = haystack[i];
    }
    scanf("%c", &needle);
    if(find(haystack, needle) == NULL)
        printf("-1");
    else
        printf("%d", (find(haystack, needle) - haystack));
    free(haystack);
    return 0;
}

char* find(char *haystack, char needle){
    char *s;
    s = strchr(haystack, needle);
    if(s != NULL)
        return s;
    else
        return NULL;
}
