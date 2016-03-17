#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* find(char *haystack, char needle);

int main()
{
    char *result;
    char haystack[401], needle;

    fgets(haystack, 401, stdin);
    needle = getchar();

    result = find(haystack, needle);

    if(result != NULL)
        printf("%d",(int)(result - haystack));
    else
        printf("-1");

    return 0;
}

char* find(char *haystack, char needle)
{
    int i, length;

    length = strlen(haystack);
    for(i = 0; i < length; i++)
    {
        if (haystack[i] == needle)
        {
            return &haystack[i];
        }
    }

    return NULL;
}
