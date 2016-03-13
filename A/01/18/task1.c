#include <stdio.h>
#include <stdlib.h>

long hash(char *word);
int main()
{
    int res;
    char word[200];

    scanf("%s", word);
    res = hash(word);
    printf("%li", res);
    return 0;
}

long hash(char *word)
{
    int summary = 42, i;
    for(i = 0; i < strlen(word); i++)
    {
        summary = summary + (word[i] * (i + 1));
    }
    return summary;
}
