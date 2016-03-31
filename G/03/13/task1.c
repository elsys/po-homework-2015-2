#include <stdio.h>
#include <stdlib.h>

int check(char* data){
	char month[2] = {data[2], data[3]};
	char day[2] = {data[4], data[5]};
	int int_month = atoi(month);
	int int_day = atoi(day);

	if (int_day > 31){
		return 0;
	}

	if (!( (int_month <= 12) || ((int_month >= 20) && (int_month <= 32)) || ((int_month >= 40) && (int_month <= 52)) )){
		return 0;
	}

	int full = 0;
	full += (data[0] - '0') * 2;
	full += (data[1] - '0') * 4;
	full += (data[2] - '0') * 8;
	full += (data[3] - '0') * 5;
	full += (data[4] - '0') * 10;
	full += (data[5] - '0') * 9;
	full += (data[6] - '0') * 7;
	full += (data[7] - '0') * 3;
	full += (data[8] - '0') * 6;
	full %= 11;
	if (full == 10){
		full = 0;
	}

	if ( (data[9] - '0') != full){
		return 0;
	}


	return 1;
}

int main(){
	char* string = malloc(12);
	int data;

	scanf("%s", string);
	
	data = check(string);

	printf("%d\n", data);

	free(string);
	return 0;
}
