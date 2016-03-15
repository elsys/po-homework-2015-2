#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void hash(char *word);
int main()
{   char s[200];
    fgets(s,200,stdin);
    hash(s);
    return 0;
}
void hash(char *word)
{
    int a=42,i=0,n;
    n=strlen(word);
    for(i=0;i<n;i++)
    a=a+(word[i]*(i+1));
    if(a==52)
        a=a-10;
    printf("%d",a);
}
