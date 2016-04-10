#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
 int pr=1,i,checksum,len,comp,cyka=1,shteviebamaikata=0,sum=0;
 char isbn[20];
 scanf("%s",isbn);
 len=strlen(isbn);
 if(isbn[0]!='9'&&isbn[1]!='7'&&(isbn[2]!='8'||isbn[2]!='9'))
 {
  cyka=0;
 }
 if(len!=17)
 {
  cyka=0;
 }
 for(i=0;i<len;i++)
 {
  if(isbn[i]<'0'&&isbn[i]>'9'&&isbn[i]!='-')
  {
   cyka=0;
  }
  if(isbn[i]>'0'&&isbn[i]<'9');
  {
   isbn[i]=isbn[i]-'0';
  }
 }
 for(i=0;i<len-1;i++)
 {
  if(isbn[i]<=9&&isbn[i]>=0)
  {
   sum=sum+isbn[i]*pr;
   shteviebamaikata++;
   if(shteviebamaikata%2==0)
         pr=1;
   else
         pr=3;
  }
 }
 if(isbn[len-1]!=10-(sum%10))
 {
  cyka=0;
 }
 if(cyka)
 {
  printf("1");
  if(isbn[6]==9&&isbn[7]==3&&isbn[8]==3&&isbn[9]==3&&isbn[10]==4&&isbn[11]==6)
       printf("\nBluebridge");
    if(isbn[6]==5&&isbn[7]==5&&isbn[8]==5&&isbn[9]==8&&isbn[10]==3)
       printf("\nAlyson Books");
    if(isbn[6]==4&&isbn[7]==2&&isbn[8]==1&&isbn[9]==0)
       printf("\nFUNimation Productions, Ltd.");
    if(isbn[6]==0&&isbn[7]==1)
       printf("\nPyramid Books");
 }
 else
     printf("0");
 return 0;
}
