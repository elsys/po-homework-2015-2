#include <stdio.h>
#include <string.h>

#define UCN_MAX_LENGHT 13
#define MAGIC_NUMBERS 	{2,4,8,5,10,9,7,3,6}

int check_ucn(char ucn[], char country[]);
int check_bg_ucn(char ucn[]);
int is_string_equals(char *first, char *second);

int main()
{
	char ucn[UCN_MAX_LENGHT]= {0};

	scanf("%s",ucn);

	int is_valid_ucn = check_ucn(ucn, "bg");
	
	printf("%d\n", is_valid_ucn);

	return 0;
}

int check_ucn(char ucn[], char country[])
{
	if(is_string_equals(country,"bg"))
	{
		return check_bg_ucn(ucn);
	}

	return 0;
}

int check_bg_ucn(char ucn[])
{
	int lenght = strlen(ucn);
	if(lenght != 10)
	{
		return 0;
	}

	int day = ((ucn[4]-'0')*10)+(ucn[5] - '0');
	int month = ((ucn[2]-'0')*10)+(ucn[3]-'0');
	int magic_numbers[] = MAGIC_NUMBERS;

	if(month >= 21 && month <= 32)
	{
		month -= 20;
	}
	else if(month >= 41 && month <= 52)
	{
		month -= 40;
	}

	if (!(month >= 1 && month <= 12))
	{
		return 0;
	}

	if(!(day >= 1 && day <= 31))
	{
		return 0;
	}

	int sum_of_numbers = 0;
	int i = 0;

	for(;i < lenght-1; i++)
	{
		sum_of_numbers += (ucn[i]-'0') * magic_numbers[i];  
	}

	sum_of_numbers = sum_of_numbers % 11 == 10 ? 0 : sum_of_numbers % 11;

	if(sum_of_numbers != ucn[9]-'0')
	{
		return 0;
	}

	return 1;
}

int is_string_equals(char *first, char *second)
{
	int counter = 0;

	while(first[counter] != '\0' && second[counter] != '\0')
	{
		if(first[counter] != second[counter])
		{
			return 0;
		}

		counter++;
	}

	if(first[counter] != second[counter])
	{
		return 0;
	}

	return 1;
}