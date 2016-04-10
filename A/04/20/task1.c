#include <stdio.h>
#include <string.h>
#define MAX 20

int prefix(char*);
int control_number(char*);
void publisher(char*, int);
int integer[MAX];

int main()
{
	char input[MAX] = "\0";

	fgets(input, 21, stdin);

	int i=0;
	for(int count =0; count<strlen(input); count++)
	{
		if(input[count] >= '0' && input[count] <= '9')
		{
			integer[i+1] = input[count] - '0';
			i++;
		}
	}
	
	i=4;
	while(input[i]!='-')
	{
		i++;
	}

	if(strlen(input)-1 == 17)
	{
		if(prefix(input) == 1)
		{
			if(control_number(input) == 1)
			{
				printf("1\n");
				publisher(input, i);
			}
		}
	}

	return 0;
}

int prefix(char input[MAX])
{

	if(input[0] == '9' && input[1] == '7' && input[2] == '8')
	{
		return 1;
	}
	if(input[0] == '9' && input[1] == '7' && input[2] == '9')
	{
		return 1;
	}
	return 0;
}

int control_number(char input[MAX])
{
	int sum = 0;

	for(int count = 1; count<13; count++)
	{
		if(count%2 == 0)
		{
			sum += 3*integer[count];
		}
		else
		{
			sum += integer[count];
		}
	}

	sum %=10;
	sum = 10 - sum; 
	
	if(integer[13] == sum)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void publisher(char input[MAX], int i)
{
	if (input[i+1]=='9' && input[i+2]=='3' && input[i+3]=='3' && input[i+4]=='3' && input[i+5]=='4' && input[i+6]=='6')
	{
		printf("Bluebridge");
	}
	else
	{
		if (input[i+1]=='5' && input[i+2]=='5' && input[i+3]=='5' && input[i+4]=='8' && input[i+5]=='3')
		{
			printf("Alyson Books");
		}
		else
		{
			if (input[i+1]=='4' && input[i+2]=='2' && input[i+3]=='1' && input[i+4]=='0')
			{
				printf("FUNimation Productions, Ltd.");
			}
			else
			{
				if (input[i+1]=='0' && input[i+2]=='1')
				{
					printf("Pyramid Books");
				}
			}
		}
	}
} 