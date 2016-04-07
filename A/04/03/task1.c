#include <stdio.h>
#include <string.h>
void swap(int *a, int *b)
{ int temp;
   temp= *a;
   *a=*b;
   *b=temp;
}
int main()
{int i,l,cur=1,next=3,dash=0,check_sum=10;
int res1,res2,res3,res4;
int sum=0,m=0,j=0;
int checker=0;
char s[20];

char publisher[7];
char publisher1[7]="933346";
char publisher2[6]="55583";
char publisher3[5]="4210";
char publisher4[3]="01";
scanf("%s",s);
l=strlen(s);
int flag=0,fg=0;
if(s[0]=='9' && s[1]=='7' && (s[2]=='8' ||s[2]=='9'))
{fg=1;}
else
{fg=0;}

for(i=0;i<l;i++)
{m=s[i]-'0';
if(s[i] != '-' && dash!=4)
  {
   sum=sum+(m*cur);swap(&cur,&next);}

else{ checker=i;dash++;}
if(s[i] != '-' && dash==2 && dash!=3 )
{publisher[j++]=s[i];}

}
sum=sum%10;
check_sum=check_sum-sum;
if(s[checker]-'0'==check_sum)
{flag=1;}
if(fg==1 &&flag ==1)
{printf("%d",flag);}
else
{printf("0");}
res1=strcmp(publisher, publisher1);
res2=strcmp(publisher, publisher2);
res3=strcmp(publisher, publisher3);
res4=strcmp(publisher, publisher4);
if(res1==0 && fg==1 &&flag ==1)
{printf("\nBluebridge");}
if(res2==0 && fg==1 &&flag ==1)
{printf("\nAlyson Books");}
if(res3==0 &&fg==1 &&flag ==1)
{printf("\nFUNimation Productions, Ltd.");}
if(res4==0 && fg==1 &&flag ==1)
{printf("\nPyramid Books");}

return 0;
}
