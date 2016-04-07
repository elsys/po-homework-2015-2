#include <stdio.h>
#include <string.h>
#define MAX 20

int numerals[14];

int check_lenght_digits(char isbn[MAX]);
int check_starting_digits(char isbn[MAX]);
int check_check_sum(char isbn[MAX]);
int check_publisher(char isbn[MAX]);

int main(){
	
	char isbn[MAX];
	
	fgets(isbn, MAX + 1, stdin);

	if(check_lenght_digits(isbn) == 1){
		if(check_starting_digits(isbn) == 1){
				if(check_check_sum(isbn) == 1){
					printf("1");
					check_publisher(isbn);
					return 0;
				}
				else{
					printf("0");
					return 0;
				}	
		}
		else{
			printf("0");
			return 0;
		}
	}
	else{
		printf("0");
		return 0;
	}
	return 0;
}

int check_lenght_digits(char isbn[MAX]){
	
	int count = 0;
	
	for(int i = 0; i < strlen(isbn); i++){
		if(isbn[i] >= '0' && isbn[i] <= '9'){
			numerals[count + 1] = isbn[i] - '0';
			count ++;
		}
	}
	if(count != 13){
		return 0;
	}
	else{
		return 1;
	}
}

int check_starting_digits(char isbn[MAX]){
	
	if(isbn[0] == '9' && isbn[1] == '7'){
		if(isbn[2] == '9' || isbn[2] == '8'){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		return 0;
	}
	
}

int check_check_sum(char isbn[MAX]){
	
	int sum = 0;
	
	for(int i = 1; i < 13; i++){
		if(i % 2 == 0){
			sum += 3*numerals[i];
		}
		else{
			sum += numerals[i];
		}
	}
	
	sum %= 10;
	sum = 10 - sum;
	
	if(numerals[13] == sum){
		return 1;
	}
	else{
		return 0;
	}
}

int check_publisher(char isbn[MAX]){

	if(numerals[5] == 9 && numerals[6] == 3){
		if(numerals[7] == 3 && numerals[8] == 3){
			if(numerals[9] == 4 && numerals[10] == 6){
				if(isbn[12] == '-'){
					printf("\nBluebrigde");
					return 0;
				}
			}
		}
	}
	if(numerals[5] == 5 && numerals[6] == 5){
		if(numerals[7] == 5 && numerals[8] == 8){
			if(numerals[9] == 3){
				if(isbn[11] == '-'){
					printf("\nAlyson Books");
					return 0;
				}
			}
		}
	}
	if(numerals[5] == 4 && numerals[6] == 2){
		if(numerals[7] == 1 && numerals[8] == 0){
			if(isbn[10] == '-'){
				printf("\nFUNimation Productions, Ltd.");
				return 0;
			}
		}
	}
	if(numerals[5] == 9 && numerals[6] == 9){
		if(isbn[8] == '-'){
			printf("\nPyramid Books");
			return 0;
		}
	}
	return 0;
}
