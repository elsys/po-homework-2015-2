#include <stdio.h>
#include <stdlib.h>

char* find(char *haystack, char needle);

int main()
{
    char haystack[400] = {0};
    char needle;
    int pointer = 0;
    fgets(haystack, 399, stdin);
    scanf("%c", &needle);
    pointer = find(haystack, needle);
    if(pointer==NULL)
    {
        printf("\n-1");
    }
    else
    {
        printf("%ld", pointer - haystack);
    }
}
char* find(char *haystack, char needle)
{
    int counter = 0;
    int flag = 0;
    int *pointer = NULL;
    while(counter<400)
    {
        if(haystack[counter]==needle)
        {
            *pointer = &haystack[counter];
            flag = 1;
        }
        counter++;
    }
        return pointer;
}
