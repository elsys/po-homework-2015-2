#include <stdio.h>

const int multipliers[] = {2, 4, 8, 5, 10, 9, 7, 3, 6};

int check(char *);
int days_for_month(int, int);
int is_leap_year(int);


int main(int argc, const char * argv[]) {
    
    char input[12];
    int index = 0;
    
    int i;
    for (i = 0; i < 10; ++i) {
        char ch;
        if (scanf("%c", &ch) != EOF) {
            if (ch >= '0' && ch <= '9') {
                input[index++] = ch;
            } else {
                break;
            }
        } else {
            break;
        }
    }
    
    if (index != 10) {
        printf("0\n");
        return 0;
    }
    
    input[index] = '\0';
    
    int res = check(input);
    
	printf("%d", res);
    
    return 0;
}

int check(char *input_number) {
    long long num;
    sscanf(input_number, "%lld", &num);
    
    int digits[10];
    
    int i;
    for (i = 9; i >= 0; --i) {
        digits[i] = num % 10;
        num /= 10;
    }
    
    int year = digits[0] * 10 + digits[1];
    int month = digits[2] * 10 + digits[3];
    int day = digits[4] * 10 + digits[5];
    
	if(month >= 40 && month <= 52) {
		year += 2000;
		month -= 40;
	}
	else if(month >= 20 && month <= 32) {
		year += 1800;
		month -= 20;
	}
	else if(month >= 0 && month <= 12) {
            year += 1900;
    }
	else {
           return 0;
	}
    
    int days_in_month = days_for_month(month, year);
    if (day < 0 || day > days_in_month) {
        return 0;
    }
    
	int sum = 0;
    for (i = 0; i < 9; ++i) {
        sum += digits[i] * multipliers[i];
    }
    
    int control_digit = (sum % 11 == 10) ? 0 : (sum % 11);
    
    return (control_digit == digits[9]) ? 1 : 0;
}

int days_for_month(int month, int year) {
    switch (month) {
        case 1: // Jan
        case 3: // Mar
        case 5: // May
        case 7: // Jul
        case 8: // Aug
        case 10: // Oct
        case 12: // Dec
            return 31;
            
        case 4: // Apr
        case 6: // Jun
        case 9: // Sep
        case 11: // Nov
            return 30;
            
        case 2:
            return is_leap_year(year) ? 29 : 28;
            
        default:
            return -1;
    }
}

int is_leap_year(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            } else {
                return  0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}
