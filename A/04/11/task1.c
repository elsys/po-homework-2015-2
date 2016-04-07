#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_if_valid(char*);

int main()
{
    char input[41];

    scanf("%s", input);

    check_if_valid(input);

    return 0;
}

int check_if_valid(char *input)
{
    int i, j = 0;
    int valid = 0;
    int check;
    int remainder_from_check;
    int final;

    int even_cleaner[14] = {0};

    int first_three;
    char *first_three_ptr;

    char clean[14] = {0};

    for(i = 0; i < strlen(input); i++)
    {
        if((input[i] == '0') || (input[i] == '1') || (input[i] == '2') || (input[i] == '3') || (input[i] == '4') || (input[i] == '5') || (input[i] == '6') || (input[i] == '7') || (input[i] == '8') || (input[i] == '9'))
        {
            clean[j] = input[i];
            j++; 
        }
    }

    if(j != 13)
    {
    	valid = 0;
    	printf("0");
    	return 0;
    }
    else
    {
    	valid = 1;
    }

    first_three_ptr = strndup(clean, 3);
    first_three = atoi(first_three_ptr);

    if((first_three != 978) && (first_three != 979))
    {
    	valid = 0;
    	printf("0");
    	return 0;
    } 
    else
    {
    	valid = 1;
    }

    for(i = 0; i < 13; i++)
	{
		even_cleaner[i] = clean[i] - '0';
	}

	check = (even_cleaner[0] + even_cleaner[1]*3 + even_cleaner[2] + even_cleaner[3]*3 + even_cleaner[4] + even_cleaner[5]*3 + even_cleaner[6] + even_cleaner[7]*3 + even_cleaner[8] + even_cleaner[9]*3 + even_cleaner[10] + even_cleaner[11]*3);
	remainder_from_check = check % 10;

	if(remainder_from_check == 10)
	{
		final = 0;
	}
	else if(remainder_from_check == 0)
	{
		final = remainder_from_check;
	}
	else
	{
		final = 10 - remainder_from_check;
	}

	if(final != even_cleaner[12])
	{
		valid = 0;
		printf("0");
		return 0;
	}
	else
	{
		valid = 1;
	}

    if(valid == 1) printf("1");

    char *to_be_searched = clean;
	char *alyson = "55583";

	char *result1 = strstr(to_be_searched, alyson);

	if(result1)
	{
	    printf("\nAlyson Books");
	}

	char *bluebridge = "933346";

	char *result2 = strstr(to_be_searched, bluebridge);

	if(result2)
	{
	    printf("\nBluebridge");
	}

	char *funimation = "4210";

	char *result3 = strstr(to_be_searched, funimation);

	if(result3)
	{
	    printf("\nFUNimation Productions, Ltd.");
	}

	char *pyramid = "01";

	char *result4 = strstr(to_be_searched, pyramid);

	if(result4)
	{
	    printf("\nPyramid Books");
	}

    return 1;
}
