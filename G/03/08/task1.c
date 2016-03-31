#include <stdio.h>
#include <string.h>
#define max 10

int is_month_legit(int month);
int is_day_legit(int day, int month);
int last_dig(int *egn);
int main()
{
    char arr[12];
    int egn[max] = {0};

    int i,month=0,day=0;

    scanf("%s",arr);
    int l;
    l=strlen(arr);

    if(l != 10 )
    {
        printf("0");
        return 0;
    }

    for(i=0; i<max; i++)
    {

        egn[i] = arr[i] - 48;

    }

    month = (egn[2]*10)+egn[3];
    day = (egn[5]*10)+egn[6];

    if(!is_month_legit(month) && !is_day_legit(day,month))
    {
        printf("0");
        return 0;
    }
    if(egn[9] == last_dig(egn))
    {

        printf("1");

    }
    else
    {

        printf("0");

    }


    return 0;
}

int is_month_legit(int month)
{

    if(month%20<=12 && month<=52 ) return 1;

    return 0;
}

int is_day_legit(int day, int month)
{
    if(month == 2 && day<=28) return 1;
    if(month%2 == 1 && day<=31) return 1;
    if(month%2 == 0 && day<=30) return 1;

    return 0;
}

int last_dig(int *egn)
{

    int eq = 0;

    eq = ((2 * egn[0]) + (4 * egn[1]) + (8 * egn[2]) + (5* egn[3]) + (10*egn[4]) + (9 * egn[5]) + (7 * egn[6]) + (3 * egn[7]) +(6 * egn[8])) % 11;
    if (eq == 10) return 0;
    return eq;
}

