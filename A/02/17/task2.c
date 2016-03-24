#include <stdio.h>
#include <string.h>

char* find(char *, char);

int main()
{
    char haystack[400];
    char needle;
    char *temp = 0;

    fgets(haystack, 400, stdin);
    scanf("%c", &needle);

    temp = find(haystack,needle);

    if(temp == NULL)
    {
        printf("-1");
    }
    else
    {
        printf("%d", temp-haystack);
    }

    return 0;
}

char* find(char *haystack,char needle)
{
    int i;
    char*holder;
    int lenght;

    lenght = strlen(haystack);

    for(i = 0; i < lenght; i++)
    {
        if(needle == haystack[i])
        {
            holder = &haystack[i];
            break;
        }
        holder = NULL;
    }
    return holder;
}
