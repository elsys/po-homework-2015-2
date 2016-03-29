#include <stdio.h>
#include <string.h>

int main(){

    char arr[12];
    int egn[10];
    int counter;
    int month = 0;
    int days = 0;
    int helper;


    scanf("%s", arr);

    if(strlen(arr) != 10){
        printf("0");
        return 0;
    }

    counter = 0;

    for(; counter < 10; counter++){
        egn[counter] = (arr[counter] - 48);
    }

    month = egn[2]*10 + egn[3];
    days = egn[4]*10 + egn[5];

    if(month%20 <= 12 && month/20 >=0 && month/20 <= 2){
        if((month%20 == 4 || month%20 == 6 || month%20 == 9 || month%20 == 11) && days > 30){
                printf("0");
                return 0;
            }
        if((month%20 == 1 || month%20 == 3 || month%20 == 5 || month%20 == 7 || month%20 == 8 || month%20 == 10 || month%20 == 12) && days > 31){
                printf("0");
                return 0;
            }
        if(month%20 == 2 &&  days > 29){
                printf("0");
                return 0;
            }
    }else{
        printf("0");
        return 0;
        }

    helper = ((egn[0]*2) + (egn[1]*4) + (egn[2]*8) + (egn[3]*5) + (egn[4]*10) + (egn[5]*9) + (egn[6]*7) + (egn [7]*3) + (egn[8]*6))%11;

    if(egn[9] != helper){
        printf("0"); return 0;
    }else{
        printf("1");
    }

return 0;
}
