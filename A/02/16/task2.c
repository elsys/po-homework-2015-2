#include <stdio.h>
#include <stdlib.h>

char* find(char *haystack, char needle);

int main()
{
    char haystack[400] = {0};
    char needle;
    char *pointer = 0;
    fgets(haystack, 399, stdin);
    scanf("%c", &needle);
    pointer = find(haystack, needle);
    if(pointer==NULL)
    {
        printf("\n-1");
    }
    else
    {
        printf("%d", pointer - haystack);
    }
    return 0;
}
char *find(char *haystack, char needle)
{
    int counter = 0;
    char *pointer = NULL;
    while(counter<400)
    {
        if(haystack[counter]==needle)
        {
            pointer = &haystack[counter];
            break;
        }
        counter++;
    }
        return pointer;
}
