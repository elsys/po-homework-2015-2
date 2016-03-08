#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long hash(char *word)
{
    int i;
    int num=42;

    for(i=0;i<strlen(word);i++)
    {
        num = num+word[i]*(i+1);
    }
    return num;
}

int main()
{

    char word[200];
    scanf("%s",word);

    printf("%ld",hash(word));
    return 0;
}
