#include <stdio.h>
#include <string.h>

char* find(char *haystack, char needle);

int main()
{
    char haystack[401], needle;

    fgets(haystack, 401, stdin);
    needle = getchar();

    if(find(haystack, needle) == NULL)
        printf("-1");
    else
        printf("%d", (int)(find(haystack, needle) - haystack));

    return 0;
}

char* find(char *haystack, char needle){
    char* returnVal = NULL;
    int i;

    for(i = 0; i < strlen(haystack); i++){
        if(needle == haystack[i]){
            returnVal = &haystack[i];
            break;
        }
    }
    return returnVal;
}
