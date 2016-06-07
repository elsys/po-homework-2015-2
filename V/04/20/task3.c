#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXIMUM_INPUT_DIGITS_NUMBER 10 // will have problems with number larger than 64

int convert_digit_to_int(char);
int evaluate(int, int [], long long, int);
char * get_solution(int [], long long, int);
int __cmpfunc(const void *, const void *);

int main(int argc, const char * argv[]) {
    char input[MAXIMUM_INPUT_DIGITS_NUMBER + 1];
    fgets(input, MAXIMUM_INPUT_DIGITS_NUMBER + 1, stdin);
    
    int expexted_result;
    scanf(" %d",&expexted_result);
    
    int digits[MAXIMUM_INPUT_DIGITS_NUMBER];
    int i = 0;
    char ch = input[i++];
    while (ch >= '0' && ch <= '9') {
        digits[i - 1] = convert_digit_to_int(ch);
        ch = input[i++];
    }
    
    int signs = i - 2;
    int size = 2;
    int solution_index = 0;
    long long *solutions = (long long *)malloc(size * sizeof(long long));
    long long int possible_solution = pow(2, signs) - 1;
    
    while (possible_solution >= 0 ) {
        if (evaluate(expexted_result, digits, possible_solution, signs)) {
            if (solution_index == size) {
                size *= 2;
                solutions = (long long *)realloc(solutions, size * sizeof(long long));
            }
            solutions[solution_index++] = possible_solution;
        }
        possible_solution--;
    }
    
    if (solution_index == 0) {
        printf("-1\n");
        return 0;
    }
    
    char **strings = (char **)malloc(solution_index * sizeof(char *));
    for (int i = 0; i < solution_index; ++i) {
        strings[i] = get_solution(digits, solutions[i], signs);
    }
    
    qsort(strings, solution_index, sizeof(char *), __cmpfunc);
    
    for (int i = 0; i < solution_index; ++i) {
        printf("%s\n", strings[i]);
        free(strings[i]);
    }
    free(strings);
    return 0;
}

inline int convert_digit_to_int(char input) {
    return input - '0';
}

int evaluate(int result, int digits[], long long signs, int signs_count) {
    int sum = digits[0];
    for (int i = 0; i < signs_count; ++i) {
        int sign = (signs & (1 << i)) >> i;
        if (sign == 1) { // +
            sum += digits[i + 1];
        } else if (sign == 0) { // -
            sum -= digits[i + 1];
        }
    }
    return sum == result ? 1 : 0;
}

char * get_solution(int digits[], long long solution, int signs_count) {
    char *str = (char *)malloc(100 * sizeof(char));
    str[0] = '\0';
    int sum = digits[0];
    char *tmp;
    asprintf(&tmp, "%d", digits[0]);
    strcat(str, tmp);
    free(tmp);
    for (int i = 0; i < signs_count; ++i) {
        int sign = (solution & (1 << i)) >> i;
        if (sign == 1) { // +
            sum += digits[i + 1];
            asprintf(&tmp, "+%d", digits[i + 1]);
            strcat(str, tmp);
            free(tmp);
        } else if (sign == 0) { // -
            sum -= digits[i + 1];
            asprintf(&tmp, "-%d", digits[i + 1]);
            strcat(str, tmp);
            free(tmp);
        }
    }
    asprintf(&tmp, "=%d", sum);
    strcat(str, tmp);
    free(tmp);
    return str;
}

int __cmpfunc(const void * first, const void *second) {
    return -strcmp(*(const char **)first, *(const char **)second);
}
