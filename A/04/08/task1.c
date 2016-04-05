#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int CheckSum(char* num);


int main(){
	char isbn[20], token[5][10], dashlessISBN[14], publisherList[2][4][50] = {{"933346", "55583", "4210", "01"}, {"Bluebridge", "Alyson Books", "FUNimation Productions, Ltd.", "Pyramid Books"}};
	char* tempToken;
	int i;

	scanf("%s", isbn);

	if(strlen(isbn) != 17){
		printf("0");
		return 0;
	}

	tempToken = strtok(isbn, "-");
	for(i = 0;tempToken != NULL; i++){
		strcpy(token[i], tempToken);
		tempToken = strtok(NULL, "-");
	}

	if(tempToken != NULL ||(strcmp(token[0], "978") != 0 && strcmp(token[0], "979") != 0)){
		printf("0");
		return 0;
	}

	//----------------------------------Checked------------------------------------------

	i = 0;
	strcpy(dashlessISBN, token[i]);
	i++;
	for(; i < 4; i++){
		strcat(dashlessISBN, token[i]);
	}
	dashlessISBN[13] = 0;
	if(atoi(token[i]) != CheckSum(dashlessISBN)){
		printf("0");
		return 0;
	}

	printf("1");
	for(i = 0; i < 4; i++){
		if(strcmp(token[2], publisherList[0][i]) == 0){
			printf("\n%s", publisherList[1][i]);
			break;
		}
	}

	return 0;
}

int CheckSum(char* num){
	int checksum = 0, i = 0;

	for(i = 0; i < strlen(num); i++){
		checksum += (i % 2 == 1)? (num[i] - '0')*3 : (num[i] - '0');
	}
	return 10 - (checksum % 10);
}
