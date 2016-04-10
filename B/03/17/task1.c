#include <stdio.h>
#include <string.h>

int valid(char *);
int control_num(char *);
int main()
{
    int a;
    char str[12];

    scanf("%s",str);

    if((valid(str) && control_num(str))== 1)
    printf("1");
    else
        printf("0");

    return 0;

}
int valid(char *str){
    if(strlen(str)!=10)return 0;
    if(str[0] < '0' || str[1] < '0')return 0;
    if(str[2] < '0' || str[2] > '5')return 0;
    if(str[3] <= '0' || str[3] > '3')return 0;
    if(str[4] < '0' || str[4] > '3') return 0;
    if(str[5] < '0' || str[5] > '9')return 0;
    if (str[4] == '3' && str[5] > '1') return 0;


    return 1;

}
int control_num(char *str){
    int sum ,control;
    sum += (str[0]-48) * 2;
    sum += (str[1]-48) * 4 ;
    sum += (str[2]-48) * 8 ;
    sum += (str[3]-48) * 5 ;
    sum += (str[4]-48) * 10;
    sum += (str[5]-48) * 9 ;
    sum += (str[6]-48) * 7 ;
    sum += (str[7]-48) * 3 ;
    sum += (str[8]-48) * 6 ;
    if( sum % 11 == 10 ) control = 0;
    if( sum % 11 < 10  ) control = sum % 11;
    if( control == ( str[9]-48 ) )
       return 1;
    else
        return 0;

}


