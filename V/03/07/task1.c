#include <stdio.h>
#include <string.h>

int dividable_4(char *inp);

int main()
{
	char input[12];
	short unsigned int i, l, n[10];
	scanf("%s",input);
	l=strlen(input);
	if(l!=10)
	{
		printf("0");
		return 0;
	}
	for(i=0; i<10; i++)
		if(input[i]<'0' || input[i]>'9')
		{
			printf("0");
			return 0;
		}
	if(input[2]>'5')
	{
		printf("0");
		return 0;
	}
	if((input[2]=='5' || input[2]=='3' || input[2]=='1') && input[3]>'2')
	{
		printf("0");
		return 0;
	}
	if(input[4]>'3')
	{
		printf("0");
		return 0;
	}
	if((input[2]=='0' || input[2]=='2' || input[2]=='4') && input[3]=='2')
	{
		if(input[4]>'2')
		{
			printf("0");
			return 0;
		}
		if(input[4]=='2' && input[5]=='9' && !((input[2]=='4' || input[2]=='5') || (dividable_4(input) && !(input[0]=='0' && input[1]=='0'))))
		{
			printf("0");
			return 0;
		}
	}
	if(input[4]=='3')
	{
		if(input[3]=='4' || input[3]=='6' || input[3]=='9' || (input[3]=='1' && ((int)input[2]-48)%2==1))
		{
			if(input[5]>'0')
			{
				printf("0");
				return 0;
			}
		}
		else if(input[5]>'1')
		{
			printf("0");
			return 0;
		}
	}
	for(i=0; i<10; i++)
		n[i]=(short unsigned int)input[i]-48;
	if(n[9]!=((n[0]*2 + n[1]*4 + n[2]*8 + n[3]*5 + n[4]*10 + n[5]*9 + n[6]*7 + n[7]*3 + n[8]*6 )%11 )%10)
	{
		printf("0");
		return 0;
	}
	printf("1");
	return 1;
}

int dividable_4(char *inp)
{
	short unsigned int year=1900;
	year+=((int)inp[0]-48)*10+(int)inp[1]-48;
	if(inp[2]=='4' || inp[2]=='5')
		year+=100;
	if(inp[2]=='2' || inp[2]=='3')
		year-=100;
	if(year%4==0)
		return 1;
	else
		return 0;
}