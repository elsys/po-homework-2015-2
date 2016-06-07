#include <stdio.h>
#include <string.h>

void calculation(int, int, int);

int expected , length , ok = 0;
char entered_digits[10] , result[22];

int main(){

    scanf("%s", entered_digits);

    length = strlen(entered_digits);

    scanf("%d", &expected);

    result[0] = entered_digits[0];

    calculation(1, entered_digits[0] - '0', 0);

    if (ok == 0){

        printf("%d\n", -1);

    }

    return 0;
}

void calculation(int number, int current_sum, int level){

	int help;

    if (number == length){
        if (current_sum == expected){
            ok = 1;

            help = number*2;

            result[help-1] = '=';

            printf("%s", result);

            printf("%d\n", current_sum);

        }
    return;
    }

    int sum = 0;

    if (number > 0){

		help = number*2;

		result[help-1] = '-';

    	result[help] = entered_digits[number];
    }
    	sum = current_sum - (entered_digits[number] - '0');

    	calculation(number + 1, sum , level + 1);


    	if (number > 0){

        	result[help - 1] = '+';

        	result[help] = entered_digits[number];
    	}

    	sum = current_sum + (entered_digits[number] - '0');

    	calculation(number + 1 , sum , level + 1);
}
