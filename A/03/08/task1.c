#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void GetStringPart(const char * src, char* dest, int beginning, int size);
int GetMaxDateForMonth(int month, int year);
int ControlNum(const char* id);

int main(){
	char id[12], temp[12], valid = 1;
	int i;

	scanf("%s", id);
	for(i = 0; i < strlen(id); i++)
		if(!isdigit(id[i])){
			valid = 0;
			break;
		}
	if(i > 10)
		valid = 0;

	if(valid == 1){
		GetStringPart(id, temp, 0, 2);
		int year = atoi(temp);
		GetStringPart(id, temp, 2, 2);
		int month = atoi(temp);
		if(!((month >= 1 && month <= 12) ||
			(month >= 1+20 && month <= 12+20) ||
			(month >= 1+40 && month <= 12+40))){
				valid = 0;
			}

			GetStringPart(id, temp, 4, 2);
			if(atoi(temp) > GetMaxDateForMonth(month, year)){
				valid = 0;
			}

			int ctrlNum = ControlNum(id);
			if(atoi(&id[9]) != ctrlNum)
				valid = 0;

	}

	printf("%d", valid);

	return 0;
}

void GetStringPart(const char * src, char* dest, int beginning, int size){
	int i;

	for(i = 0; i < size; i++){
		dest[i] = src[i+beginning];
	}
	dest[i] = 0;
}

int GetMaxDateForMonth(int month, int year){
	switch(month){
		case 1:case 21: case 41:
			return 31;
		case 2:case 22: case 42:
			return (year != 0 && year%4 == 0)? 29:28;
		case 3:case 23: case 43:
			return 31;
		case 4:case 24: case 44:
			return 30;
		case 5:case 25: case 45:
			return 31;
		case 6:case 26: case 46:
			return 30;
		case 7:case 27: case 47:
			return 31;
		case 8:case 28: case 48:
			return 31;
		case 9:case 29: case 49:
			return 30;
		case 10:case 30: case 50:
			return 31;
		case 11:case 31: case 51:
			return 30;
		case 12:case 32: case 52:
			return 31;
		default:
			return -1;
	}
}

int ControlNum(const char* id){
	int digitWeight[10] = {2, 4, 8, 5, 10, 9, 7, 3, 6}, sum = 0, i;
	
	for(i = 0; i < 10; i++)
		sum += (id[i] - '0')*digitWeight[i];
	sum %= 11;
	return(sum < 10)? sum:0;
}