#include <stdio.h>
#include <math.h>

void the_magic(int, int, int);

int main() {
	int input, temp;
	int l = 1, required_number;

	scanf("%d", &input);
	scanf("%d", &required_number);

	temp = input;

	while(temp > 1) {
		temp /= 10;
		l++;
	}

	the_magic(input, l, required_number);

	return 0;
}

void the_magic(int input, int length, int required_number) {

	int numbers[10];
	int i, temp = 0;

	for(i = length - 1; i >= 0; i--) {
		numbers[i] = input % 10;
		input /= 10;
	}

	for(i = 0; i < length; i++) {
		temp += numbers[i];
	}

	if(temp == required_number) {
		printf("%d", numbers[1]);
		for(i = 2; i < length; i++) {
			printf("+%d", numbers[i]);
		}
		printf("=%d", required_number);
	}


}