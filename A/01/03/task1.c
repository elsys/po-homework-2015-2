#include<stdio.h>
#include<string.h>

long hash(char *word)
{ long hesh=42;
int i,l,kod;
l=strlen(word);

for(i=0;i<l;i++)
{
kod = *(word+i);
hesh=hesh+kod*(i+1);
}

return hesh;
}

int main()
{

char c[201];
scanf("%s",c);
char *word;
word=c;

printf("%ld", hash(word));
return 0;}


