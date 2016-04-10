#include <stdio.h>
#include <string.h>

int checkISBN(char *);

int main() {

	char code[20];
	char *code_e[5];
	int i, l;
	char *elem;

	scanf("%s", code);
	l = strlen(code);

	if(l != 17) {
		printf("0"); 
		return 0;
	}

	elem = strtok(code, "-");

	for(i = 0; elem != NULL; i++) {
		code_e[i] = elem;
		elem = strtok(NULL, "-");
	}

	if((strcmp(code_e[0], "978") != 0) && (strcmp(code_e[0], "979") != 0)) {
		printf("0");
		return 0;
	}
	if(checkISBN(code) == *code_e[4] - '0') {
		printf("1");
		if(strcmp(code_e[2], "933346") == 0) {
			printf("\nBluebridge");
		}
		else if(strcmp(code_e[2], "55583") == 0) {
			printf("\nAlyson Books");
		}
		else if(strcmp(code_e[2], "4210") == 0) {
			printf("\nFUNimation Productions, Ltd.");
		}
		else if(strcmp(code_e[2], "01") == 0) {
			printf("\nPyramid Books");
		}
	}
	else {
		printf("0");
	}

	return 0;
}

int checkISBN(char *code) {
	int r, sum = 0;
	int i, k = 0;

	for(i = 0; i < 16; i++) {
		if(code[i] != 0) {
			if(k % 2 == 0) {
				sum += (code[i] - 48) * 1;
			}
			else{
				sum += (code[i] - 48) * 3;
			}
			k++;
		}
	}

	r = sum % 10;
	return 10 - r;
}
