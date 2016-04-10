#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char ISBN[20];
	int v=1,d=0,i=0,count=0,digit_check=0,pub_ptr=0;
	char pub1[6]="933346",pub2[5]="55583",pub3[4]="4210",pub4[2]="01";
	char ex1[4] = "978-", ex2[4] = "979-";
	int pub1_result,pub2_result,pub3_result,pub4_result;
	scanf("%s", ISBN);
	if(strlen(ISBN)!=17)
	v=0;	
	for(i=0;i<strlen(ISBN);i++)
	{
		if(ISBN[i]=='-')
		d++;
		if(d==2 && pub_ptr==0)
		pub_ptr=i+1;
		if((ISBN[i]<'0' || ISBN[i]>'9') && ISBN[i]!='-' && ISBN[i]!='\n' && ISBN[i]!=' ')
		v=0;
		else if(ISBN[i]>='0' && ISBN[i]<='9')
		{
			count++;
			if(count<=12)
			{
				if(count%2)
				digit_check=digit_check+(ISBN[i]-'0');
				else 
				digit_check=digit_check+(ISBN[i]-'0')*3;
			}
		}
	}
	if(d!=4)
	v=0;
	else
	{
		digit_check=digit_check%10;
		if(digit_check)
		digit_check=10-digit_check;
		if((ISBN[16]-'0')!=digit_check)
		v=0;
	}
	for(i=0;i<4;i++)
	{
		if(ISBN[i] != ex1[i] && ISBN[i] != ex2[i]) 
		v=0;
	}
	pub1_result=0;
	pub2_result=0;
	pub3_result=0;
	pub4_result=0;
	if(v)
	{
		printf("1");
		for(i=pub_ptr;ISBN[i]!='-';i++)
		{
			if(ISBN[i]==pub1[i-pub_ptr])
			{
				pub1_result++;
			}			
			else if(ISBN[i]==pub2[i-pub_ptr])
			{
				pub2_result++;
			}
			else if(ISBN[i]==pub3[i-pub_ptr])
			{
				pub3_result++;
			}
			else if(ISBN[i]==pub4[i-pub_ptr])
			{
				pub4_result++;
			}
		}
		if(i-pub_ptr==pub1_result)
		{
			printf("\nBluebridge");
		}
		else if(i-pub_ptr==pub2_result)
		{
			printf("\nAlyson Books");
		}
		else if(i-pub_ptr==pub3_result)
		{
			printf("\nFUNimation Productions, Ltd.");
		}
		else if(i-pub_ptr==pub4_result)
		{
			printf("\nPyramid Books");
		}
	}
	else printf("0");
}
