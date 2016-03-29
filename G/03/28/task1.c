#include <stdio.h>

int is_correct_input(char *);
int is_correct_length(char *);
int control_digit(char *);

int main()
{
	char egn[12] = {0};
	scanf("%s",egn);
	
	if(is_correct_input(egn) == 1 || is_correct_length(egn) == 1 || control_digit(egn) == 1)
	{
		printf("0 \n");
	}
	else
	{
		printf("1 \n");
	}
	return 0;
}

int is_correct_input(char *egn)
{
	int counter = 0;
	while(egn[counter] != '\0')
	{
		if(egn[counter] < 48 || egn[counter] > 57)
		{
			return 1;
		}
		counter++;
	}
	return 0;
}

int is_correct_length(char *egn)
{
	int digit_counter = 0;
	
	while(egn[digit_counter] != '\0')
	{
		digit_counter++;
	}
	if(digit_counter > 10)
	{
		return 1;
	}
	return 0;
}

int control_digit(char *egn)
{
	int egn_digit_holder[9] = {0};
	int counter = 0;
	while(counter < 10)
	{
		if(egn[counter] == 48)
		{
			egn_digit_holder[counter] = 0;
		}
		if(egn[counter] == 49)
		{
			egn_digit_holder[counter] = 1;
		}
		if(egn[counter] == 50)
		{
			egn_digit_holder[counter] = 2;
		}
		if(egn[counter] == 51)
		{
			egn_digit_holder[counter] = 3;
		}
		if(egn[counter] == 52)
		{
			egn_digit_holder[counter] = 4;
		}
		if(egn[counter] == 53)
		{
			egn_digit_holder[counter] = 5;
		}
		if(egn[counter] == 54)
		{
			egn_digit_holder[counter] = 6;
		}
		if(egn[counter] == 55)
		{
			egn_digit_holder[counter] = 7;
		}
		if(egn[counter] == 56)
		{
			egn_digit_holder[counter] = 8;
		}
		if(egn[counter] == 57)
		{
			egn_digit_holder[counter] = 9;
		}
		counter++;
	}
	counter = 0;
	int control_number = ((egn_digit_holder[0] * 2) + (egn_digit_holder[1] * 4) + (egn_digit_holder[2] * 8) + (egn_digit_holder[3] * 5) +
						 (egn_digit_holder[4] * 10) + (egn_digit_holder[5] * 9) + (egn_digit_holder[6] * 7) + (egn_digit_holder[7] * 3) +
						 (egn_digit_holder[8] * 6)) % 11;	
	if(control_number == egn_digit_holder[9])
	{
		return 0;
	}									
	return 1;
}
