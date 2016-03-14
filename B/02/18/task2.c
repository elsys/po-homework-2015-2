#include <stdio.h>
#include <string.h>

char* find(char *haystack, char needle);

int main()
{
    char input[400];
    char ch;
    
    scanf("%[^\n]s", input);
    scanf(" %c", &ch);
    
    if (find(input, ch))
    {
        printf("%ld", find(input, ch) - input);
    }
    
    else 
    {
        printf("-1");
    }
    
    return 0;
}

char* find(char *haystack, char needle)
{
    int index = 0;
    int length = 0;
    
    length = strlen(haystack);

    for (index = 0; index < length; index++)
    {
        if (needle == *(haystack + index))
        {
            return &haystack[index];
        }
    } 
 
    return NULL;
}
