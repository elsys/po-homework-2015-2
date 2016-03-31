#include <stdio.h>
int leap_check(int year);
int date_check(char *input);
int control_check(char *input);

int true = 1;

int main()
{
	char input[12] = { 0 };
	fgets(input, 12, stdin);
	date_check(input);
	if(control_check(input) != (input[9]-'0')) true = 0;
	if(true == 1)
		{
			printf("1");
			return 1;
		}
	else
		{
			printf("0");
			return 0;
		}
}

int date_check(char *input)
{
	int day = (input[4]-'0')*10+(input[5]-'0');
	int month = (input[2]-'0')*10+(input[3]-'0');
	int year = (input[0]-'0')*10+(input[1]-'0');

	if(month > 0 && month < 13)
		{
			year += 1900;
		}
	else if((month-20) > 0 && (month-20) < 13)
		{
			year += 1800;
			month-=20;
		}
	else if((month-40) > 0 && (month-40) < 13)
		{
			year += 2000;
			month-=40;
		}
	else
		{
			true = 0;
			return -1;
		}

	int leap = leap_check(year);

	switch(month)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if(day < 1 || day > 31)
				{
					true = 0;
					return -1;
				}
			else return 0;
		case 4: case 6: case 9: case 11:
			if(day < 1 || day > 30)
				{
					true = 0;
					return -1;
				}
			else return 0;
		case 2:
			if((leap == 0 && day != 28) || (leap == 1 && day != 29))
				{
					true = 0;
					return -1;
				}
			else return 0;
	}
	return 0;
}

int control_check(char *input)
{
	int ctrl = 0;
	ctrl += (input[0]-'0') * 2;
	ctrl += (input[1]-'0') * 4;
	ctrl += (input[2]-'0') * 8;
	ctrl += (input[3]-'0') * 5;
	ctrl += (input[4]-'0') * 10;
	ctrl += (input[5]-'0') * 9;
	ctrl += (input[6]-'0') * 7;
	ctrl += (input[7]-'0') * 3;
	ctrl += (input[8]-'0') * 6;

	if(ctrl%11 < 10) ctrl %= 11;
	else if(ctrl%11 == 10) ctrl = 0;
	return ctrl;
}

int leap_check(int year)
{
	int leap=0;
	if(!(year % 4))
	{
		if(!(year % 100)) 
		{
			if(!(year % 400)) leap = 1;
			else leap = 0;
		}
		else leap = 1;
	}
	else leap = 0;
	return leap;
}
