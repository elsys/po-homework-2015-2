#include <stdio.h>
#include <stdlib.h>

int main()
{
    char EGN[12];
    int sum,check_number = 0,temp = 0;
    int month = EGN[2]*10 + EGN[3];

    fgets(EGN, 12, stdin);

    if( (month <= 0) || (month > 12 && month < 21) || (month > 32 && month < 41) || month > 52)
    {
        temp=1;
    }

    sum = 0;

    sum = sum + ((EGN[0] - '0') *2);
    sum = sum + ((EGN[1] - '0') *4);
    sum = sum + ((EGN[2] - '0') *8);
    sum = sum + ((EGN[3] - '0') *5);
    sum = sum + ((EGN[4] - '0') *10);
    sum = sum + ((EGN[5] - '0') *9);
    sum = sum + ((EGN[6] - '0') *7);
    sum = sum + ((EGN[7] - '0') *3);
    sum = sum + ((EGN[8] - '0') *6);

    if(sum % 11 == 10)
    {
       check_number = 0;
    }

    if(sum %11 < 10)
    {
        check_number = sum % 11;
    }

    if(check_number != EGN[9] - '0')
    {
        temp = 0;
    }
        if(temp == 1)
        {
            printf("%d",temp);
        }
        else
        {
            printf("0");
        }

    return 0;
}
