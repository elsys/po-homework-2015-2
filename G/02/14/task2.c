#include <stdio.h>


char* find(char *haystack, char needle){
    while (*haystack != needle)
        if (!*haystack++)
            return NULL;
    return (char *)haystack;
}


int main(){

    char haystack[400];
    char needle;
    fgets(haystack, 400, stdin);
    scanf("%c", &needle);

    char* found = find(haystack, needle);
    int index = found ? found - haystack : -1;
    printf("%d", index);

    return 0;
}
