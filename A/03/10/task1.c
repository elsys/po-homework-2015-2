#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main ()
{
  	char c;
	int i=0,count_ch,k,ks,year,yearrest,month,day;
	int numbers[12];	
	int kontsum[9]={2, 4, 8, 5,10, 9, 7, 3, 6};
	int m1=0;
	k=0;
	count_ch=1;
	while (count_ch<=10)
	{ 
		c=getchar();
		if((c-47)>0  && (58-c)>0)
		{
			numbers[count_ch-1]=(c-48);
			count_ch++;
		}
		else 
		{
			printf("0");
		}
	}
	year=numbers[0]*10+numbers[1];
	yearrest=year%4;
	m1=numbers[2];
	if(numbers[2]>20)
	{
		m1=numbers[2]-20;
	}	
	if(numbers[2]>40)
	{
		m1=numbers[2]-40;	
	}
	month=m1*10+numbers[3];
	day=numbers[4]*10+numbers[5];
 	if(((month==2) || (month==22) || (month==42)) && (day==29) && (yearrest != 0))
	{ 
		printf("0");
		k++;
	}
	if( (month>40) && (year >16))
	{ 
		printf("0"); 
		k++;
	}
	ks=0;
	for (i=1;i<=9;i++)
     {
          ks=ks+numbers[i-1]*kontsum[i-1];
     }
	ks=ks%11;
	if(ks==10)
	{
		ks=0;
	}
	if(ks!= numbers[9])
	{ 
		printf("0");
		k++;
	}
	if(k>0)
	{
		printf("0");
	}
	else
	{
		printf("1");
	}
	return 0;
}
