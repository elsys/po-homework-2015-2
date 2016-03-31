#include <stdio.h>
#include <string.h>

int check(char*);

int main()
{
	char input[13];

	fgets(input, 13, stdin);

	check(input);

	return 0;
}
void ev(int);
void odd(int);

int check(char *input)
{
	int yy, mm, dd, c1, c2, c3;
	int temp;

	yy = (input[0] -  '0')*10 + (input[1] - '0');
	mm = (input[2] -  '0')*10 + (input[3] - '0');
	dd = (input[4] -  '0')*10 + (input[5] - '0');
	c1 = input[6] - '0';
	c2 = input[7] - '0';
	c3 = input[8] - '0';

	if(yy>=0 && yy<=16)
	{
		if((mm - 40)<=0)
		{
			printf("0");
			return 0;
		}
	}

	if(yy>=0 && yy<=16)
	{
		mm = mm-40;
	}	

	if(mm>=12)
	{
		printf("0");
		return 0;
	}
	if(mm == 2)
	{
		if((yy+4)%4==0)
		{
			if(dd>29 || dd<=0)
			{
				printf("0");
				return 0;
			}
		}
		else
		{
			if(dd>28 || dd<=0)		
			{
				printf("0\n");
			}
		}
	}

	if((mm==1)
	 ||(mm==3)
	 ||(mm==5)
	 ||(mm==7)
	 ||(mm==8)
	 ||(mm==10)
	 ||(mm==12)
	 ){
	
		if(dd>31 && dd<=0)
		{
			printf("\n0");
			return 0;
		}
	}
	if(mm==4
	 ||mm==6
	 ||mm==9
	 ||mm==11
	 )
	{
		if(dd>30 && dd<=0)
		{
			printf("0");
			return 0;
		}
	}

	temp = (yy/10)*2 + (yy%10)*4 + (mm/10)*8 + (mm%10)*5 + (dd/10)*10 + (dd%10)*9 + c1*7 + c2*3 + c3*6;

	if(temp%11 < 10)
	{
		printf("1");
	}
	else
	{
		printf("0");
	}

	return 0;
}
