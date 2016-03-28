#include <stdio.h>
#include <stdlib.h>
 
char *find(char *haystack, char needle)
{
    int counter;
    char *pointer=NULL;
    for(counter=0;counter<400;counter++)
    {
        if(haystack[counter]==needle)
        {
            pointer = &haystack[counter];
            break;
        }
    }
        return pointer;
}
int main()
{
    char string[401] = {0},search_char,*pointer = 0;
    fgets(string, 400, stdin);
    scanf("%c", &search_char);
    pointer = find(string, search_char);
    if(pointer==NULL)
        {
            printf("\n-1");
        }
    printf("%ld",pointer-string);
    return 0;
 
    }
