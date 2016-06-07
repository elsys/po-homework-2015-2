#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAXINPLEN 11
#define SORTLEN 22

void combination_sort(char combinations[512][22]  , int variation_number);

int main(){
	
	int i = 0;                           //counters
	
	char combinations[512][SORTLEN] = {{-1}};	    // sort string
	
	char input_values[MAXINPLEN];				// input
	
	int searched_for,operation_cycler = 0,variation_number = 0,len = 0;
	
	int int_numbers[MAXINPLEN];


	fgets(input_values, MAXINPLEN, stdin);
	scanf("%d", &searched_for);
	
	len = strlen(input_values);

	for(i = 0 ; i < strlen(input_values); i++)
	{
		int_numbers[i] = input_values[i] - '0';
	}

	
	int sum = int_numbers[0];
	
	

	while(!(operation_cycler >> (len - 2) & 1))  
	{
		for( i = 0; i < len - 2; i++)		////summation while statement
		{
			if((operation_cycler >> i) & 1)
			{
				sum = sum - int_numbers[i + 1];
			}
			if(!((operation_cycler >> i) & 1))
			{
				sum = sum + int_numbers[i + 1];
			}
		}
		if(sum == searched_for)					//operation placer 
		{
			for(i = 0; i < len - 1; i++)
			{
				combinations[variation_number] [i*2] =  input_values[i];
				if(i < len - 2)
				{

					if((operation_cycler >> i) & 1)
					{
						combinations[variation_number][i*2 + 1] =  '-';
					}
					if(!((operation_cycler >> i) & 1))
					{
						combinations[variation_number][i*2 + 1] =  '+';
					}
				}
			}

			variation_number ++;
		}
		sum = int_numbers[0];
		operation_cycler ++;
	}
	




	combination_sort(combinations,variation_number);


	

	if(variation_number == 0)
	{
		printf("-1");
		return 0;
	}
	

	for( i = 0; i < variation_number ; i++)
	{
		printf("%s=%d", combinations[i], searched_for);
		printf("\n");
	}
	
	
	return 0;
}


void combination_sort(char combinations[512][SORTLEN],int variation_number)
{
	char temp[SORTLEN];
	int i,j;

	for( i = 0; i < variation_number ; i++)
	{
		for( j = 0; j < variation_number - j; j++)
		{
			if(strcmp(combinations[i], combinations[i + 1]) < 0)
			{
					strcpy(temp, combinations[i]);
					strcpy(combinations[i], combinations[i + 1]);
					strcpy(combinations[i + 1], temp);
			}
			
		}	
	}


}