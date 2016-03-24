#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long hash(char* word);

int main()
{
    char word[201]={0};
    int m=0;
    scanf("%s",word);

    m=hash(word);
    printf("%d",m);
    return 0;
}

long hash(char *word)
{
    int m=42, i=0, x=0;
    int *n;
    int lenght=0;
    lenght=strlen(word);
    while (i<lenght)
    {
        x=word[i];
        m=m+(x*(i+1));
        i++;
    }
    n=&m;
    return *n;
}
