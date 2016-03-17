#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long hash(char *word);

int main()
{
    long result;
    char word[200];

    scanf("%s", word);

    result = hash(word);
    printf("%li", result);

    return 0;
}

long hash(char *word)
{
    int sum = 42, i;
    for(i = 0; i < strlen(word); i++)
    {
        sum = sum + ((i + 1)*word[i]);
    }

    return sum;
}
