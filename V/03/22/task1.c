#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main()
{
    unsigned long long int egn,temp,sum=0,a=0,b=0,c=0,day,mounth,year,n;
  	int i=0;
    scanf("%llu",&egn);
    temp=egn;
	  for(i=0;temp>0;i++)
		  temp=temp/10;
	  if(i != 10)
		  return -1;
	  temp=egn;
    n=temp%10;
    temp=temp/10;
    sum=(temp%10)*6+((temp/10)%10)*3+((temp/100)%10)*7+((temp/1000)%10)*9+((temp/10000)%10)*10+((temp/100000)%10)*5+((temp/1000000)%10)*8+((temp/10000000)%10)*4+((temp/100000000)%10)*2;
    sum=sum%11;
    if(sum==10)
        sum=0;
    if(n==sum)
        a=1;
    temp=egn/10000;
    day=temp%10+((temp/10)%10)*10;
    temp=temp/100;
    mounth=temp%10+((temp/10)%10)*10;
    temp=temp/100;
    year=temp%10+((temp/10)%10)*10;
    if(year>=0 && year<=16)
        mounth=mounth-40;
    if(mounth>0 && mounth<13)
        b=1;
    if(mounth==2){
        if(day>0 && day<30)
            c=1;
    }
    else{
        if(day>0 && day<32)
            c=1;
    }
    if(a==1 && b==1 && c==1)
        printf("1 \n");
    else
        printf("0 \n");

    return 0;
}
