#include <stdio.h>

unsigned int date_part(unsigned int* egn, unsigned int part) {
    return egn[part] * 10 + egn[part + 1];
}

unsigned int not_valid_date(unsigned int month, unsigned int day) {
    unsigned int max_day[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int valid_month = (((month > 0) && (month < 13)) || ((month > 20) && (month < 33)) || ((month > 40) && (month < 53)));
    if(!valid_month || ((day == 0) || (day > max_day[month - 1]))) {
        return 1;
    }
    return 0;
}

unsigned int check(unsigned int* egn) {
    unsigned int mul_k[] = {2, 4, 8, 5, 10, 9, 7, 3, 6};
    unsigned int month = date_part(egn, 2);
    unsigned int day = date_part(egn, 4);
    unsigned int not_valid = not_valid_date(month, day);
    unsigned int sum = 0;
    unsigned int i;
    unsigned last = 0;
    if(not_valid) {
        return 0;
    }
    for(i = 0; i < 9; ++i) {
        sum += egn[i] * mul_k[i];
    }
    last = sum % 11;
    if(last == 10) {
        last =  0;
    }
    return (last == egn[9]);
}

int main(void) {
    const unsigned int max = 10;
    unsigned int egn[max];
    unsigned int i;
    for(i = 0; i < max; ++ i) {
        egn[i] = getchar() - '0';
    }
    printf("%d\n", check(egn));
    return 0;
}
