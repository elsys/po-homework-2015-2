#include <stdio.h>
#include <string.h>

long hash(char *word);

int main()
{
    char word[200];
    scanf("%s",word);

    hash(word);
    return 0;
}

long hash(char *word)
{
    long hash = 42;
    int p = 0;
    int i;

    p = strlen(word);

    for(i = 0; i <= p; i++)
    {
        hash=hash + word[i]*(i+1);
    }

    printf("\n%ld",hash);

    return 0;
}
