#include <stdio.h>
#include <stdlib.h>

char* find(char *haystack, char needle);

int main()
{
    int *result, i = 0, length;
    char str[400];
    char c;
    while(c != '\n')
    {
        if(c != '\n') {
            c = getchar();
            str[i] = c;
            i++;
        }
    }

    scanf("%c", &c);

    result = find(str, c);
    length = strlen(str);

    if(result == NULL)
    {
        printf("-1");
    }
    else
    {
        int p;
        for(p = 0; p < length; p++)
        {
            if(result == &str[p])
            {
                printf("%d", p);
            }
        }
    }


    return 0;
}

char* find(char *haystack, char needle)
{
    int i, length;

    length = strlen(haystack);

    for(i = 0; i < length; i ++)
    {
        if(haystack[i] == needle)
        {
            return &haystack[i];
        }
    }

    return NULL;
}

