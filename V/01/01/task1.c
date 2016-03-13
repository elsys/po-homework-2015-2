#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long hash(char*);

int main()
{
 long hesche;
 char duma[200];
 scanf("%s",duma);
 hesche = hash(duma);
 printf("%ld",hesche);
 return 0;
}

long hash(char *duma)
{
 int i,duljina;
 duljina=strlen(duma);
 long a=42;
 for(i=0;i<duljina;i++)
 {
  a=a+(duma[i]*(i+1));
 }
 return a;
}
