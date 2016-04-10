#include <stdio.h>
#include <string.h>

int main()
{
    char bookHouse[4][40] = {"Bluebridge", "Alyson Books", "FUNimation Productions, Ltd." ,"Pyramid Books"};
    char bookHouseId[4][10] = {"933346", "55583", "4210", "01"};
    int bookHouseCount = 4;

    char input[21];
    scanf("%s", input);
    int len = strlen(input);
    int digits[17];
    int i, sum, j, checkNum;

    if(len != 17)
    {
        printf("0");
        return 0;
    }

    if(input[0] != '9' || input[1] != '7' || (input[2] != '8' && input[2] != 9))
    {
        printf("0");
        return 0;
    }

    sum = 0;
    j = 0;
    for(i = 0; i < len;i++)
    {
        if(input[i] < '0' || input[i] > '9')
        {
            if(input[i] != '-')
            {
                printf("0");
                return 0;
            }

        }

        digits[i] = input[i] - '0';

        if(input[i] != '-' && i != len - 1)
        {
            if(j % 2 == 0)
            {
                sum += digits[i];
            }
            else
            {
                sum += 3 * digits[i];
            }

            j++;
        }
    }

    checkNum = 10 - (sum % 10);

    if(checkNum != digits[16])
    {
        printf("0");
        return 0;
    }

    printf("1");

    j = 0;
    for(i = 0; i < len; i++)
    {
        if(digits[i] == -3)
        {
            j++;
            if(j == 2)
            {
                j = i + 1;
                break;
            }
        }
    }

    for(i = 0; i < bookHouseCount;i++)
    {
        if(j == (strstr(input, bookHouseId[i]) - input ))
        {
            printf("\n%s", bookHouse[i]);
            break;
        }
    }

    return 0;

}


