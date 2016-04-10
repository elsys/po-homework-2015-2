#include <stdio.h>
#include <string.h>
#include <math.h>

typedef enum { minus = 1, plus = 2 } operator;
char arr[10][25];

int size = 0;

int func(char*, int);
void swap(char** s1, char** s2);
void print(char*, char*, int);

int main() {
	char str[10] = {0};
	int res;
	scanf("%s", str);
	scanf("%d", &res);

	for(int i = 0; i < strlen(str); i++) {
		str[i] -= 48;
	}

	if(func(str, res) == 0) {
		printf("-1");
	}
	else {
		for(int i = 0; i < size; i++)
			for(int j = 0; j < size; j++)
				if(strcmp(arr[i], arr[j]) > 0) {
					char tmp[25] = "";
					strcpy(tmp, arr[i]);
					strcpy(arr[i], arr[j]);
					strcpy(arr[j], tmp);
				}
		for(int i = 0; i < size; i++)
			printf("%s", arr[i]);
	}

	return 0;
}

void print(char* num, char* ops, int res) {

	char string[25] = "";

	for(int i = 0; i < strlen(num); i++) {
		//printf("%d", num[i]);
		sprintf(string + strlen(string), "%d", num[i]);
		if(i < strlen(ops))
			//printf("%c", (ops[i] == minus)? '-' : '+');
			sprintf(string + strlen(string), "%c", (ops[i] == minus)? '-' : '+');
	}
	//printf("=%d\n", res);
	sprintf(string + strlen(string), "=%d\n", res);
	strcpy(arr[size], string);
}

void check(char* num, char* ops, int res) {
	int sum = num[0];


	for(int k = 0; k < strlen(ops); k++) {
		switch(ops[k]) {
			case plus:	sum += num[k+1];	break;
			case minus:	sum -= num[k+1];	break;
		}
	}
	if(sum == res) {
		print(num, ops, res);
		size++;
	}
}


int func(char* num, int res) {
	char ops[strlen(num)-1];
	for(int i = 0; i < strlen(num)-1; i++)
		ops[i] = minus;
	ops[sizeof(ops)] = '\0';

	check(num, ops, res);

	for(int i = 0; i < pow(2, sizeof(ops)); i++) {
		for(int j = 0; j < sizeof(ops); j++)
			if(ops[j] == minus) {
				ops[j] = plus;
				break;
			}
			else {
				ops[j] = minus;
			}
		check(num, ops, res);
	}
	return size;
}

