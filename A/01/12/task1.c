#include <stdio.h>
#include <string.h>

long hash(char *);

int main()
{
    char w[200];
    long h;
    scanf("%s",w);
    h=hash(w);
    printf("%ld",h);
    return 0;
}

long hash(char *word)
{
    long he;
    int num,i;
    num=strlen(word);
    he=42;
    for(i=0;i<num;i++)
    {
        he=he+word[i]*(i+1);
    }
    return he;
}
