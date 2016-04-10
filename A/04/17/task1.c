#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int holder[13];

int main()
{
    char ISBN[20];
    int j,i;
    int sum = 0,check_sum = 0;

    fgets(ISBN, 21, stdin);

    if(ISBN[0] != '9' || ISBN[1] != '7')
    {
        if(ISBN[2] != '9' || ISBN[2] != '8')
        {
            printf("0");
            return 0;
        }
        printf("0");
        return 0;
    }

    for(i = 0, j=0; i < 17; i++)
	{
		if (ISBN[i]!='-')
		{
			holder[j] = ISBN[i] - '0';
			j++;
		}
	}

	sum = sum + holder[0];
	sum = sum + holder[1]*3;
	sum = sum + holder[2];
	sum = sum + holder[3]*3;
	sum = sum + holder[4];
	sum = sum + holder[5]*3;
	sum = sum + holder[6];
	sum = sum + holder[7]*3;
	sum = sum + holder[8];
	sum = sum + holder[9]*3;
	sum = sum + holder[10];
	sum = sum + holder[11]*3;

    sum = sum % 10;
    check_sum = 10 - sum;

    if(check_sum != holder[12])
    {
        printf("0");
        return 0;
    }
    printf("1");
     if(ISBN[6] == '5')
            {
                if(ISBN[7] == '5')
                {
                    if(ISBN[8] == '5')
                    {
                        if(ISBN[9] == '8')
                        {
                            if(ISBN[10] == '3')
                            {
                                printf("\nAlyson Books");
                                return 0;
                            }
                        }
                    }
                }
            }
            if(ISBN[6] == '9')
            {
                if(ISBN[7] == '3')
                {
                    if(ISBN[8] == '3')
                    {
                        if(ISBN[9] == '3')
                        {
                            if(ISBN[10] == '4')
                            {
                                if(ISBN[11] == '6')
                                {
                                    printf("\nBluebridge");
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
            if(ISBN[6] == '4')
            {
                if(ISBN[7] == '2')
                {
                    if(ISBN[8] == '1')
                    {
                        if(ISBN[9] == '0')
                        {
                            printf("\nFUNimation Productions, Ltd.");
                            return 0;
                        }
                    }
                }
            }
            return 0;
}
