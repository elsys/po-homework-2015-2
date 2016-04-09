#include <stdio.h>
#include <string.h>

#define BLUEBRIDGE 933346
#define ALYSON 55583
#define FUNIMATION 4210
#define PYRAMID 01

void print_is_valid_isbn13(char isbn[]);
char* strdup();
char* strsep();

int main()
{
	char input[21];

	scanf("%s",input);

	print_is_valid_isbn13(input);

	return 0;
}

void print_is_valid_isbn13(char isbn[])
{
	int lenght = strlen(isbn)-4;

	if(lenght != 13)
	{
		printf("0\n");
	} 
	else
	{   
		char parts[5][10];

		char *str = strdup(isbn);
		char *token;
		int i = 0;

		while ((token = strsep(&str, "-")))
		{ 
			strcpy(parts[i++],token);
		}

	    int j = 1;
	    int check_digit = 0;
		int counter = 0;
		for(i = 0; i < 4; i++)
		{
			for(j = 0; j < strlen(parts[i]); j++)
			{
				if(counter % 2)
				{
					check_digit += (parts[i][j] - '0')*3; 
				}
				else
				{
					check_digit += (parts[i][j] - '0'); 
				}
				counter++;
			}
		}

		check_digit %= 10;
		check_digit = 10 - check_digit;

		if(!strcmp(parts[0],"978") || !strcmp(parts[0],"979"))
		{
			if(check_digit == parts[4][0]-'0')
			{
				printf("1\n");
				if (!strcmp(parts[2], "933346")) 
				{
	            	printf("Bluebridge");
		        }

		        else if (!strcmp(parts[2], "55583")) 
		        {
		            printf("Alyson Books");
		        }
		        
		        else if (!strcmp(parts[2], "4210"))
		        {
		            printf("FUNimation Productions, Ltd.");
		        }
		        
		        else if (!strcmp(parts[2], "01")) 
		        {
		            printf("Pyramid Books");
		        }
			}
		}
	}
}
