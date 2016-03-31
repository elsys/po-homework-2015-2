#include <stdio.h>

int valid_Date(char*);
int control_digit(char*, int*);

int main(){
    char egn[12];
    int multiplier[9] = {2, 4, 8, 5, 10, 9, 7, 3, 6};
    int ctrdigit, valmonth;

    scanf("%s", egn);

    /*for(i = 0; i < 10; i++){
        if(egn[i] < '0' || egn[i] > '9')
            return 0;
    }
*/
    valmonth = valid_Date(egn);
    ctrdigit = control_digit(egn, multiplier);

    if((ctrdigit == (egn[9] - '0')) && (valmonth == 1))
        printf("1");

    else printf("0");

return 0;
}

int valid_Date(char* egn){
    int month;

    month = (egn[2] - '0') * 10 + (egn[3] - '0');

    if((month > 0 && month < 13) || (month > 20 || month < 33) || (month > 40 || month < 53) )
        return 1;

    return 0;
}

int control_digit(char* egn, int* multiplier){
    int sum = 0, i;

    for(i = 0; i < 9; i++){
        sum += (egn[i] - '0') * multiplier[i];
    }

    sum = sum % 11;

    if(sum == 10)
        return 0;

    else
        return sum;
}
