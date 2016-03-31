#include <stdio.h>
#include <stdlib.h>

int main()
{
    char EGN[11] = {0};
    int temp = 0;
    int temp2 = 0;
    int day = 0;
    int month = 0;
    int year = 0;
    int controlnum = 0;
    scanf("%12s", EGN);

    temp = (temp + EGN[0]) - 48;
    temp = temp * 10;
    temp = (temp + EGN[1]) - 48;
    year= temp;
    temp = 0;

    temp = (temp + EGN[2]) - 48;
    temp = temp * 10;
    temp = (temp + EGN[3]) - 48;
    month = temp;
    temp = 0;

    temp = (temp + EGN[4]) - 48;
    temp = temp * 10;
    temp = (temp + EGN[5]) - 48;
    day = temp;
    temp = 0;

    if(month>52)
    {
        printf("\n0");
        return 0;
    }
    if(month<1)
    {
        printf("\n0");
        return 0;
    }

    if(month>12 && month < 33)
    {
        month = month - 20;
    }
    if(month>32 && month < 53)
    {
        month = month - 40;
    }
    switch(month)
    {
        case 1:
            if(day>31)
            {
                printf("\n0");
                return 0;
            }
            break;
        case 2:
            if(year%4==0)
            {
                if(day>29)
                {
                    printf("\n0");
                    return 0;
                }
            }
            if(year%4!=0)
            {
                if(day>28)
                {
                    printf("\n0");
                    return 0;
                }
            }
            break;
        case 3:
            if(day>31)
            {
                printf("\n0");
                return 0;
            }
            break;
        case 4:
            if(day>30)
            {
                printf("\n0");
                return 0;
            }
            break;
        case 5:
            if(day>31)
            {
                printf("\n0");
                return 0;
            }
            break;
        case 6:
            if(day>30)
            {
                printf("\n0");
                return 0;
            }
            break;
        case 7:
            if(day>31)
            {
                printf("\n0");
                return 0;
            }
            break;
        case 8:
            if(day>31)
            {
                printf("\n0");
                return 0;
            }
            break;
        case 9:
            if(day>30)
            {
                printf("\n0");
                return 0;
            }
            break;
        case 10:
            if(day>31)
            {
                printf("\n0");
                return 0;
            }
            break;
        case 11:
            if(day>30)
            {
                printf("\n0");
                return 0;
            }
            break;
        case 12:
            if(day>31)
            {
                printf("\n0");
                return 0;
            }
            break;
    }

    temp = 0;
    while(temp<9)
    {
        temp2 = EGN[temp] - 48;
        switch(temp)
        {
            case 0:
                temp2 = temp2*2;
                break;
            case 1:
                temp2 = temp2*4;
                break;
            case 2:
                temp2 = temp2*8;
                break;
            case 3:
                temp2 = temp2*5;
                break;
            case 4:
                temp2 = temp2*10;
                break;
            case 5:
                temp2 = temp2*9;
                break;
            case 6:
                temp2 = temp2*7;
                break;
            case 7:
                temp2 = temp2*3;
                break;
            case 8:
                temp2 = temp2*6;
                break;
        }
        controlnum = controlnum + temp2;
        temp++;
    }
    temp = controlnum % 11;
    if(temp==10)
    {
        controlnum = 0;
    }
    if(temp<10)
    {
        controlnum = temp;
    }
    temp = EGN[9] - 48;
    if(controlnum != temp)
    {
        printf("0");
        return 0;
    }
    if(controlnum == temp)
    {
        printf("1");
        return 1;
    }
    return 0;
}
