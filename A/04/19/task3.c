#include <stdio.h>
#include <string.h>

int digits(char*, long);
char* sort_string(char*, long);

int main(){
	char numbers[15];
	long answer;

	scanf("%s", numbers);
	scanf("%ld", &answer);

	if(digits(numbers, answer))
		printf("-1");;

	return 0;
}

int digits(char* numbers, long answer){
	int sum = 0;
	int l = strlen(numbers);

	for(int i = 0; i < l; i++){
		sum += (numbers[i] - '0');
	}

	if(sum == answer){
		for (int i = 0; i < l; i++){
			if(i != l - 1)
				printf("%c+", numbers[i]);
			else
				printf("%c=%ld", numbers[i], answer);
		}
		return 0;
	}

	sum = numbers[0] - '0';
	for(int i = 1; i < l; i++){
		sum -= (numbers[i] - '0');
	}

	if(sum == answer){
		for (int i = 0; i < l; i++){
			if(i != l - 1)
				printf("%c-", numbers[i]);
			else
				printf("%c=%ld", numbers[i], answer);
		}
		return 0;
	}

	return 1;
	
}