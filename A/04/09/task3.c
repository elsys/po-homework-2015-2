#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_DIGITS 10

int number(const char);
int final_combo(char*);
void generate_signs(const int, const int, char*);
void sort_combos(char**, const int);
void print_combos(char**, const int, const int);

int main() {
    char digits[MAX_DIGITS], signs[MAX_DIGITS - 1], **combos_list, temp[2];
    int length, sum, result, *combos, combos_length;
    
    scanf("%s", digits);
    scanf("%d", &result);
    
    length = strlen(digits);
    combos_length = (int)(pow(2, length - 1));
    combos = (int*)malloc(combos_length * sizeof(int));
    combos_list = malloc(combos_length * sizeof(char*));
    for (int i = 0; i < combos_length; i++) {
        combos_list[i] = (char*)malloc(2 * MAX_DIGITS);
    }
    
    sum = number(digits[0]);
    
    combos_length = 0;
    for (int combo = 0; !final_combo(signs); combo++) {
        generate_signs(combo, length - 2, signs);
        for (int i = 1; i < length; i++) {
            if (signs[i - 1] == '+') {
                sum += number(digits[i]);
            } else if (signs[i - 1] == '-') {
                sum -= number(digits[i]);
            }
        }
        if (sum == result) {
            *(combos + combos_length) = combo;
            combos_length++;
        } else if (final_combo(signs) && combos_length == 0) {
            printf("-1");
            return 0;
        }
        sum = number(digits[0]);
    }
    
    for (int i = 0; i < combos_length; i++) {
        generate_signs(combos[i], length - 2, signs);
        for (int j = 0; j < length; j++) {
            sprintf(temp, "%c%c", digits[j], signs[j]);
            strcat(combos_list[i], temp);
        }
    }
    
    sort_combos(combos_list, combos_length);
    print_combos(combos_list, combos_length, result);

    free(combos);
    free(combos_list);
    
    return 0;
}

int number(const char c) {
    return c - '0';
}

int final_combo(char *signs) {
    int length = strlen(signs);
    for (int i = 0; i < length; i++) {
        if (signs[i] != '+') {
            return 0;
        }
    }
    return 1;
}

void generate_signs(const int number, const int length, char *string) {
    for (int i = length, j = 0; i >= 0; i--, j++) {
        if ((number >> i) & 1) {
            string[j] = '+';
        } else {
            string[j] = '-';
        }
    }
}

void sort_combos(char **combos, const int length) {
    char temp[(2 * MAX_DIGITS) - 1];
    int sorted = 0, j = 0;
    while (!sorted) {
        j++;
        sorted = 1;
        for (int i = 0; i < length - j; i++) {
              if (strcmp(combos[i], combos[i + 1]) < 0) {
                    strcpy(temp, combos[i]);
                    strcpy(combos[i], combos[i + 1]);
                    strcpy(combos[i + 1], temp);
                    sorted = 0;
              }
        }
    }
}

void print_combos(char **combos, const int length, const int result) {
    for (int i = 0; i < length; i++) {
        printf("%s=%d", combos[i], result);
        if (i != length - 1) {
            printf("\n");
        }
    }
}
