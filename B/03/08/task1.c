#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int is_valid(char *, int);

int main() {
    char egn[12];
    char temp;
    int i;

    for( i = 0; i < 12; i++) {
        temp = getchar();
        if(temp == '\n') break;
        egn[i] = temp;
    }

    printf("%d", is_valid(egn, i));
    
    return 0;
}

int is_valid(char *egn, int l) {
    int month;
    int day;
    int year;
    int control_number = 0;
    
    year = egn[0] - 48;
    year = year * 10 + (egn[1] - 48);
    
    month = egn[2] - 48;
    month = month * 10 + (egn[3] - 48);
    
    day = egn[4] - 48;
    day = day * 10 + (egn[5] - 48);
    
    if(l != 10) return 0;
    
    if(isdigit(*egn)) {  
        if((month >= 13 && month <= 33) || (month >= 13 && month <= 53)) return 0;
       
        if(day >= 32) return 0;
        switch(month) {
            case 1:
            case 21:
            case 23:
            case 25:
            case 27:
            case 28:
            case 30:
            case 32:
            case 41:
            case 43:
            case 45:
            case 47:
            case 48:
            case 50:
            case 52:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12: if(day > 31) return 0;
            
            case 22:
            case 42:
            case 2: if(year % 4 == 0){
                        if(day > 29) return 0;
                    }
                    else
                        if(day > 28) return 0;
                    
            default: if(day > 30) return 0; 
        }
        control_number =(egn[0] - 48) * 2;
        control_number += (egn[1] - 48) * 4;
        control_number += (egn[2] - 48) * 8;
        control_number += (egn[3] - 48) * 5;
        control_number += (egn[4] - 48) * 10;
        control_number += (egn[5] - 48) * 9;
        control_number += (egn[6] - 48) * 7;
        control_number += (egn[7] - 48) * 3;
        control_number += (egn[8] - 48) * 6;

        if(control_number % 11 < 10) control_number = control_number % 11;
        else control_number = 0;

        if(egn[9] - 48 != control_number) return 0;
    }
    
   
    
    return 1;
}
