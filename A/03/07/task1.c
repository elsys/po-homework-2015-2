#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int control = 0;
    int numbers[12];
    int weights[9] = {2, 4, 8, 5, 10, 9, 7, 3, 6};
    char EGN[12];

    scanf("%s", EGN);
    for(i = 0;i < 10;i++)
    {
        if(EGN[i] < '0' || EGN[i] > '9')
        {
            printf("0");
            return 0;
        }
    }
    if(EGN[4] == 3)
        if(EGN[5] > '1')
        {
            printf("0");
            return 0;
        }
    if(EGN[4] > '3')
    {
        printf("0");
        return 0;
    }
    if(i == 0)
    {
        printf("0");
        return 0;
    }
    if(EGN[2] >= '6')
    {
        printf("0");
        return 0;
    }
    if(EGN[2] == '1' || EGN[2] == '3' || EGN[2] == '5')
        if(EGN[3] > '2')
        {
            printf("0");
            return 0;
        }
    for(i = 0;i < 10; i++)
    {
        numbers[i] = EGN[i] - 48;
        if(i < 10)
            control = control + (weights[i]*numbers[i]);
    }
    control = control %  11;

    if(control < 10)
        if(numbers[9] != control)
        {
            printf("0");
            return 0;
        }
    if(control == 10)
        if(numbers[9] != 0)
        {
            printf("0");
            return 0;
        }

    printf("1");
    return 0;
}
