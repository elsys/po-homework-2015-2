#include <stdio.h>

int main () 
{
    char egn[10];
    int counter = 1 ;
    int check_tot = 0;

    fgets(egn , 12 , stdin);

    if (egn [2] < '0' || egn[2] > '5')
    {
        counter = 0;

    }   
    else if(  (egn[2] == '1' && egn[3] > '2') || (egn[2] == '3' && egn[3] > '2') || (egn[2] == '5' && egn[3] > '2' ))
    {
        counter = 0;

    }
    if( egn[4] > '3' || (egn[4] == '3' && egn[5] > '1') || (egn[4] == '0' && egn[5] == '0'))
    {

        counter = 0;
    }
check_tot = check_tot + ((egn[0] - '0') * 2);
check_tot = check_tot + ((egn[1] - '0') * 4);
check_tot = check_tot + ((egn[2] - '0') * 8);
check_tot = check_tot + ((egn[3] - '0') * 5);
check_tot = check_tot + ((egn[4] - '0') * 10);
check_tot = check_tot + ((egn[5] - '0') * 9);
check_tot = check_tot + ((egn[6] - '0') * 7);
check_tot = check_tot + ((egn[7] - '0') * 3);
check_tot = check_tot + ((egn[8] - '0') * 6);

if( check_tot % 11 < 10)
{    
    if(( egn[9] - '0') != (check_tot % 11))
    {
     counter  =  0;   
         }
}else 
    { 
        if( egn[9] != '0') 
        counter =  0;
    }
    printf("%d", counter);
    return 0;
}
