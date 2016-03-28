#include <stdio.h>
#include <string.h>

int check_UCN_validity(int*);
int check_month(int*);
int check_digit(int*);

int main()
{
	char string[12];
	int UCN[12];

	scanf("%s", string);
	if(strlen(string) != 10)
	{
		printf("0");
		return 0;
	}

	for(int i = 0; i < 10; i++)
		UCN[i] = string[i] - '0';

	printf("%d", check_UCN_validity(UCN));

	return 0;
}
int check_UCN_validity(int* UCN)
{
	if(check_month(UCN)) return 0;
	
	if(check_digit(UCN) != UCN[9]) return 0;
	return 1;
}
int check_month(int* UCN)
{
	int month = UCN[2]*10 + UCN[3];
	if( (month <= 0) || (month > 12 && month < 21) || (month > 32 && month < 41) || month > 52)
		return 1;
	else return 0;
}
int check_digit(int* UCN)
{
	int value = 0;
	int multiplier[9] = {2, 4, 8, 5, 10, 9, 7, 3, 6};
	for(int i = 0; i < 9; i++)
		value += UCN[i]*multiplier[i];
	value %= 11;
	if(value == 10) value = 0;
	return value;
}
