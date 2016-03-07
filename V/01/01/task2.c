#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 typedef struct{
 long hs;
 unsigned short count;
 char dumi[4][200];
}occurance_t;

long hash(char*);

int main()
{
 char duma[200];
 unsigned short i,j,k=0;
 long hw;
 occurance_t h[3000];
 for(i=0;i<3000;i++)
 {
  h[i].hs=0;
  h[i].count=0;
 }
 do
 {
  i++;
  scanf("%s",duma);
  hw=hash(duma);
  for(j=0;j<3000;j++)
  {
   if(h[j].hs==hw)
   {
    h[j].count++;
    break;
   }
   else if(h[j].hs==0)
   {
    h[j].hs=hw;
    h[j].count=1;
    break;
   }
   }
  }while(strcmp(duma,"vsmisal")!=0);
 i=0;
 while(h[i].count!=0)
 {
  if(h[i].count>k)
     k=i;
  i++;
 }
 printf("%d %ld",h[k].count, h[k].hs);
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
