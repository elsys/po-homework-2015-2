#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int power(int, int);
int main()
{
    int nums[10];
    char input[11];
    int wantSum = 7;

    int countOfResults = 0;
    scanf("%s", input);
    scanf("%d", &wantSum);
    int len = strlen(input);
    int i, z, c, f;

    for(i = 0; i < len; i++)
    {
        nums[i] = input[i] - '0';
    }

    int end = power(2, len - 1);
    char result[end][26];
    int opers[len - 1];



    for(i = end - 1; i >= 0;i--)
    {

        for(f = 0; f < len - 1;f++)
        {
            opers[f] = 0;
        }

        int operNum = i;
        z = 0;

        while(operNum != 0)
        {
            int r = operNum % 2;
            operNum /= 2;
            opers[z] = r;
            z++;
        }

        int sum = nums[0];
        for(z = 1; z < len; z++)
        {
            if(opers[z - 1] != 0)
            {
                sum += nums[z];
            }
            else
            {
                sum -= nums[z];
            }
        }

        if(sum == wantSum)
        {
            char arr[len * 2 + 100];
            z = 1;
            arr[0] = nums[0] + '0';
            for(c = 1; c < len * 2 - 1;c+=2, z++)
            {
                if(opers[z - 1] != 0)
                {
                    arr[c] = '+';
                }
                else
                {
                    arr[c] = '-';
                }

                arr[c+1] = nums[z] + '0';

            }

            arr[c] = '=';
            arr[c+1] = '\0';
            strcpy(result[countOfResults], arr);
            countOfResults++;
            //printf("%s", a}rr);
            //printf("%d\n", wantSum);
        }
}

    char temp[25];

    for(i=0; i < countOfResults ; i++){
        for(c=i+1; c< countOfResults; c++)
        {
            if(strcmp(result[i],result[c]) < 0)
            {
                strcpy(temp,result[i]);
                strcpy(result[i],result[c]);
                strcpy(result[c],temp);
            }
        }
    }

    for(i = 0; i < countOfResults;i++)
    {
        printf("%s%d\n", result[i], wantSum);
    }

    if(!countOfResults)
    {
        printf("-1");
    }

    return 0;

}

int power(int x, int y)
{
    if(y == 1)
    {
        return x;
    }

    return x * power(x, y-1);
}


