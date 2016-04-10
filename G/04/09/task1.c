#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int numbers[20];
    int i, j = 0, count = 0, checkdigit = 0;
    char ISBN[20];
 
    scanf("%s", ISBN);
 
    if(ISBN[0] == '9' && ISBN[1] == '7')
    {
        if(ISBN[2] == '9' || ISBN[2] == '8')
        {
 
            for(i = 0; i < 20; i++)
            {
                if(ISBN[i] >= '0' && ISBN[i] <= '9')
                {
                    numbers[j] = (ISBN[i] - 48);
                    count++;
                    j++;
                }
            }
           
            if(count != 13)
            {
                printf("0\n");
                return 0;
            }
           
            for(i = 0; i < 12; i++)
            {
                if(i % 2 == 1)
                    checkdigit = checkdigit + numbers[i]*3;
                else
                    checkdigit = checkdigit + numbers[i];
            }
           
            checkdigit = checkdigit % 10;
            checkdigit = 10 - checkdigit;
           
            if(numbers[12] != checkdigit)
            {
                printf("0\n");
                return 0;
            }
           
            printf("1\n");
            if(ISBN[6] == '9' && ISBN[7] == '3' && ISBN[8] == '3' && ISBN[9] == '3' && ISBN[10] == '4' && ISBN[11] == '6')
                printf("Bluebridge");
            if(ISBN[6] == '5' && ISBN[7] == '5' && ISBN[8] == '5' && ISBN[9] == '8' && ISBN[10] == '3')
                printf("Alyson Books");
            if(ISBN[6] == '4' && ISBN[7] == '2' && ISBN[8] == '1' && ISBN[9] == '0')
                printf("FUNimation Productions, Ltd.");
            if(ISBN[6] == '0' && ISBN[7] == '1')
                printf("Pyramid Books");
        }
        else
        {
            printf("0\n");
        }
    }
    else
    {
        printf("0\n");
    }
 
    return 0;
}
