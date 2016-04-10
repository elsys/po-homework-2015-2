#include <stdio.h>
#include <string.h>

int length_check(char*);
int first_number_check(char*);
int check_sum(char*);

void house(char*);

int main(){
	char input[20];

	scanf("%[^\n]s", input);

	char save[20];
	strcpy(save, input);

	if(length_check(input) == 0){
		printf("0");
		return 0;
	}

	char *token;
	token = strtok(input, "-");
	
	if(first_number_check(token) == 0){
		printf("0");
		return 0;
	}

	if(check_sum(save) == 0){
		printf("0");
		return 0;
	}
	else{
		printf("1");
	}


	for (int i = 0; token != NULL; i++)
	{
		token = strtok(NULL, "-");
		if(i == 1){
			house(token);
			break;
		}
		else if(i > 1){
			break;
		}
	}

	return 0;
}

int length_check(char* input){
	if(strlen(input) > 17){
		return 0;
	}

	return 1;
}

int first_number_check(char* number){
	if(strcmp(number, "978") == 0 || strcmp(number, "979") == 0){
		return 1;
	}
	else
		return 0;
}

int check_sum(char* str){
	int counter = 1;
	int sum = 0;

	for (int j = 0; j < strlen(str); j++){
		if(str[j] == '-')
			continue;

		if(j != strlen(str) - 1){
				sum += (str[j] - '0') * counter;
				
				if(counter == 1){
					counter = 3;
				}
				else if(counter == 3){
					counter = 1;
				}
		}
		else{
			sum = 10 - (sum % 10);

			if(sum == str[j] - '0'){
				return 1;
			}
			else{
				return 0;
			}
		}
	}

	return 0;
}

void house(char* token){
		if(strcmp(token, "933346") == 0)
			printf("\nBluebridge");
		else if(strcmp(token, "55583") == 0)
			printf("\nAlyson Books");
		else if(strcmp(token, "4210") == 0)
			printf("\nFUNimation Productions, Ltd.");
		else if(strcmp(token, "01") == 0)
			printf("\nPyramid Books");
}