#include<stdio.h>
int month(int *n)
{int month;
int flag=0;
month=n[2]*10+n[3];
if( (month<12) ||(month>=21 &&month<=32)||(month>=41 && month<=53))
{flag=1;}
return flag;
}
int digit_10(int *n)
{int j;
int sum=0;
int i=0;
int weight[9] = {2, 4, 8, 5, 10, 9, 7, 3, 6};
for(i=0;i<9;i++)
{j=n[i]*weight[i];
 sum=sum+j;}
sum=sum%11;

if(sum<10)
{return sum;}
else
{sum=0;return sum;}
}
int main()
{int n[13],i=0;
char s[13];
int flag=1,fg=1;

scanf("%s",s);
for(i=0;i<10;i++)
{n[i]=s[i]-'0';}

flag=month(n);
if(digit_10(n)!=n[9]){fg=0;}
if(flag==0 || fg==0)
{printf("0");}
else
{printf("1");}
return 0;
}
