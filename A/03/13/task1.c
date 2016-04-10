#include <stdio.h>
#include <string.h>

int last_number(char number[]);
int check_month(int month, int day, int year);

int main()
{
   char egn[12];
   int month = 0, year = 0, day = 0, result = 0;
   int p = 0;
   scanf("%s", egn);

   year = (egn[0]-48)*10 + (egn[1]-48);
   month = (egn[2]-48)*10 + (egn[3]-48);
   day = (egn[4]-48)*10 + (egn[5]-48);

   result = check_month(month, day, year);
   if(result == 1)
   {
       p = last_number(egn);

   }
   else
   {
       printf("0");
       return 0;
   }

   if(p == (egn[9]-48))
   {
       printf("1");
   }
   else
   {
       printf("0");
   }

    return 0;

}

int check_month(int month, int day, int year)
{
   int m = 0;
   int d;

   if(month >= 1 && month <= 12)
   {
       m = month;
   }
   else if(month >= 21 && month <= 32)
   {
       m = month - 20;
   }
   else if(month >= 41 && month <= 52)
   {
       m = month - 40;
   }
   else
   {
       return 0;
   }

   switch(m)
   {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(day >= 1 && day <= 31)
            {
                return 1;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(day >= 1 && day <= 30)
            {

                return 1;
            }
            break;
        case 2:
            d = (year % 4 == 0) ? 29 : 28;
            if(day >= 1 && day <= d)
            {
                return 1;
            }
            break;
        default:
            return 0;
   }

   return 0;


}

int last_number(char number[])
{
    int temp = 0;
    int sum = 0;

    sum = (number[0] - 48)*2 + (number[1] - 48)*4 + (number[2] - 48)*8 + (number[3] - 48)*5 + (number[4] - 48)*10 + (number[5] - 48)*9 + (number[6] - 48)*7 + (number[7] - 48)*3 + (number[8] - 48)*6;
    temp = sum % 11;

    if(temp < 10)
    {
        return temp;

    }
    else
    {
        return 0;
    }
}

