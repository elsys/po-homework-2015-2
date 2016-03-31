#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int checker(char *str);

int main() {

    char str[12];
    int valid_id = 0;
    
    fgets(str, 12, stdin);   

    if (strlen(str) - 1 == 10) {
        if (checker(str)) {
            valid_id = 1;
        }
    } 

    printf("%d", valid_id);
    
    return 0;
}

int checker(char *str) { 
    int sum = 0;
    
    if (isdigit(*str)) {              
        if (str[2] == '0' && str[2] > '5') {
            return 0;
        }
        
        if (str[2] == '1' && str[3] > '2') {
            return 0;
        }
        
        if (str[2] == '3' && str[3] > '2') {
            return 0;
        }
        
        if (str[2] == '5' && str[3] > '2') {
            return 0;
        }
        
        if (str[4] > '3' && (str[4] == '3' && str[5] > '1')) {
            return 0;   
        }
        
        if (str[4] == '0' && str[5] == '0') {
            return 0;
        }
        
        sum += (str[0] - '0') * 2;
        sum += (str[1] - '0') * 4;
        sum += (str[2] - '0') * 8;
        sum += (str[3] - '0') * 5;
        sum += (str[4] - '0') * 10;
        sum += (str[5] - '0') * 9;
        sum += (str[6] - '0') * 7;
        sum += (str[7] - '0') * 3;
        sum += (str[8] - '0') * 6; 
                
        if (sum % 11 < 10) {
            if (str[9] - '0' == sum % 11) {
                return 1;
            } else {
                return 0;
            }
        } else {
            if (str[9] == '0') {
                return 1;
            }
        }        
	}
    
    return 0;
}
