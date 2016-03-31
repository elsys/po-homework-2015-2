#include <stdio.h>
#include <string.h>
 
int main()
{
    char EGN[13];
    int month,ld;
    scanf("%s", EGN);
   
    if(strlen(EGN) < 10 || strlen(EGN) > 10)
    {
        printf("0");
        return 0;
    }
   
    month = (EGN[2]-'0') * 10 + (EGN[3]-'0');
   
    if((month >= 1 && month <= 12)||(month >= 21 && month <= 32)||(month >= 41 && month <= 52))
    {
        ld = ((EGN[0]-'0')*2 +(EGN[1]-'0')*4
        + (EGN[2]-'0')*8 + (EGN[3]-'0')*5
        + (EGN[4]-'0')*10 + (EGN[5]-'0')*9
        +(EGN[6]-'0')*7 + (EGN[7]-'0')*3 +(EGN[8]-'0')*6);
       
        if(ld%11 == 10)
        {
            ld = 0;
        }
       
        if(ld%11 != EGN[9]-'0')
        {
            printf("0");
            return 0;
        }
       
        printf("1");
        return 0;
    }
   
    printf("0");
 
    return 0;
}
