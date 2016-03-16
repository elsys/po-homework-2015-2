#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* find(char *, char );

int main()
{
    char text[500];
    fgets(text, 500, stdin);
    char needle;
    scanf("%c", &needle);
    if(!find( text, needle )) {
        printf("-1");
    } else {
        printf("%d", find( text, needle) - text);
    }
    return 0;
}

char* find(char *haystack, char needle) {
    int i;
    for ( i = 0; i < strlen( haystack ) ; i++ ) {
        if( haystack[i] == needle ) return &haystack[i];
    }
    return NULL;
}
