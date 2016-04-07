#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numbers[20];
    int i, j = 0, count = 0, checkdigit = 0, flag = 1;
    char ISBN[20];

    scanf("%s", ISBN);

    if(ISBN[0] != '9' && ISBN[1] != '7' && ISBN[2] != '8')
        flag = 0;
    if(ISBN[0] != '9' && ISBN[1] != '7' && ISBN[2] != '9')
        flag = 0;

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
        flag = 0;

    for(i = 0; i < 12; i = i + 2)
    {
        if(i == 12)
            checkdigit = checkdigit + numbers[i];
        else
            checkdigit = checkdigit + numbers[i] + numbers[i+1] * 3;
    }
    checkdigit = checkdigit % 10;
    checkdigit = 10 - checkdigit;
    if(checkdigit == 10)
        checkdigit = 0;

    if(numbers[12] != checkdigit)
        flag = 0;
    printf("%d", flag);

    if(flag == 1)
    {
        if(ISBN[6] == '9' && ISBN[7] == '3' && ISBN[8] == '3' && ISBN[9] == '3' && ISBN[10] == '4' && ISBN[11] == '6')
            printf("\nBluebridge");
        if(ISBN[6] == '5' && ISBN[7] == '5' && ISBN[8] == '5' && ISBN[9] == '8' && ISBN[10] == '3')
            printf("\nAlyson Books");
        if(ISBN[6] == '4' && ISBN[7] == '2' && ISBN[8] == '1' && ISBN[9] == '0')
            printf("\nFUNimation Productions, Ltd.");
        if(ISBN[6] == '0' && ISBN[7] == '1')
            printf("\nPyramid Books");
    }

    return 0;
}
