#include <stdio.h>
#include <string.h>

void check_ISBN_validity(char*);

int main()
{
	char ISBN[20];
	scanf("%s", ISBN);
	check_ISBN_validity(ISBN);
	return 0;
}
void check_ISBN_validity(char *ISBN)
{
	int valid = 1, dash = 0, i, counter = 0, check_digit = 0, publisher_ptr = 0;
	char publisher1[6] = "933346", 
	publisher2[5] = "55583", 
	publisher3[4] = "4210",
	publisher4[2] = "01";
	char ex1[4] = "978-", ex2[4] = "979-";

	if(strlen(ISBN) != 17) valid = 0;
	
	for(i = 0; i < strlen(ISBN); i++)
	{
		if(ISBN[i] == '-') dash++;
		if(dash == 2 && publisher_ptr == 0) publisher_ptr = i + 1;
		if
		(
		(ISBN[i] < '0' || ISBN[i] > '9') 
		&& ISBN[i] != '-' 
		&& ISBN[i] != '\n' 
		&& ISBN[i] != ' '
		) valid = 0;
		else if(ISBN[i] >= '0' && ISBN[i] <= '9')
		{
			counter++;
			if(counter <= 12)
			{
				if(counter%2) check_digit += ISBN[i]-'0';
				else check_digit += (ISBN[i]-'0') * 3;
			}
		}
	}
	if(dash != 4) valid = 0;
	else
	{
		check_digit %= 10;
		check_digit = 10 - check_digit;
		if(ISBN[16]-'0' != check_digit) valid = 0;
	}
	
	for(i = 0; i < 4; i++)
	{
		if(ISBN[i] != ex1[i] && ISBN[i] != ex2[i]) valid = 0;
	}
	int publisher1_result = 0;
	int publisher2_result = 0;
	int publisher3_result = 0;
	int publisher4_result = 0;
	if(valid)
	{
		printf("1");
		for(i = publisher_ptr; ISBN[i] != '-'; i++)
		{
			if(ISBN[i] == publisher1[i-publisher_ptr]) publisher1_result++;
			else if(ISBN[i] == publisher2[i-publisher_ptr]) publisher2_result++;
			else if(ISBN[i] == publisher3[i-publisher_ptr]) publisher3_result++;
			else if(ISBN[i] == publisher4[i-publisher_ptr]) publisher4_result++;
		}
		if(i-publisher_ptr == publisher1_result) printf("\nBluebridge");
		else if(i-publisher_ptr == publisher2_result) printf("\nAlyson Books");
		else if(i-publisher_ptr == publisher3_result) printf("\nFUNimation Productions, Ltd.");
		else if(i-publisher_ptr == publisher4_result) printf("\nPyramid Books");
	}
	else printf("0");
}
