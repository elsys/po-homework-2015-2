#include <stdio.h>
#include <string.h>

long hash(char *);

int main()
{
    char input[200];
    
    fgets(input, 200, stdin);
    
    printf("%ld", hash(input));
    
    return 0;
}


long hash(char *word)
{
    int index = 0;
    int result = 42;
    int length = 0;
    
    length = strlen(word) - 1;

    for (index = 0; index < length; index++)
    {
        result += (index + 1) * word[index]; 
    }
    
    return result;
}
