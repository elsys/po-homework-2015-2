#include <stdio.h>
#include <string.h>
char* find(char *s, char c);
int main()
{
    int i;
    char s[500],c,*c1;
    for(i=0;i<500;i++)
    {scanf("%c",&s[i]);
        if(s[i]=='\n')
            break;
    }
    scanf("%c",&c);
    c1=find(s,c);
    if(c1==NULL)
        printf("-1");
    else
    printf("%d",(int)(c1-s));
  return 0;
}
char* find(char *s, char c)
{   int i,n;
    n=strlen(s);
    for(i=0;i<n;i++)
        if(s[i]==c)
            return &s[i];

    return NULL;
}
