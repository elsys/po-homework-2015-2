#include <stdio.h>

int convert_digit_to_int(char);
int is_valid_isbn13(int []);

int main(int argc, const char * argv[]) {
    char line[21];
    fgets(line, 21, stdin);
    
    int ean_id;
    int group_id;
    int publisher_id;
    int title_id;
    int checksum_number;
    
    int digits[13], index = 0;
    for (int i = 0; i <= 20; ++i) {
        if (line[i] >= '0' && line[i] <= '9') {
            digits[index++] = convert_digit_to_int(line[i]);
        }
    }
    if (index != 13) {
        printf("0\n");
        return 0;
    }
    
    sscanf(line, "%d-%d-%d-%d-%d", &ean_id, &group_id, &publisher_id, &title_id, &checksum_number);
    if (ean_id != 978 && ean_id != 979) {
        printf("0\n");
        return 0;
    }
    if (is_valid_isbn13(digits)) {
        printf("1\n");
    } else {
        printf("0\n");
        return 0;
    }
    switch (publisher_id) {
        case 933346:
            printf("Bluebridge\n");
            break;
        case 55583:
            printf("Alyson Books\n");
            break;
        case 4210:
            printf("FUNimation Productions, Ltd.\n");
            break;
        case 1:
            printf("Pyramid Books\n");
            break;
    }
    
    return 0;
}

inline int convert_digit_to_int(char input) {
    return input - '0';
}

int is_valid_isbn13(int isbn[]) {
    int sum = 0;
    for (int i = 0; i < 12; ++i) {
        sum += ((i + 1) & 1) ? isbn[i] : isbn[i] * 3;
    }
    int check_digit = 10 - (sum % 10);
    return check_digit == isbn[12] ? 1 : 0;
}
