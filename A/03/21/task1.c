#include <stdio.h>
#include <string.h>
#define MAX_LENGHT 12

int check_symbols(char serial_number[MAX_LENGHT]);
int check_date(char serial_number[MAX_LENGHT]);
int check_control_number(char serial_number[MAX_LENGHT]);

int main(){
	
	char serial_number[MAX_LENGHT];
	
	scanf("%s", serial_number);
	
	if(check_symbols(serial_number) == 1){
		if(check_date(serial_number) == 1){
			if(check_control_number(serial_number) == 1){
				
				printf("1");
				
				return 0;
			}
		}
	}
	
	printf("0");
	
	return 0;
}

int check_symbols(char serial_number[MAX_LENGHT]){
	
	int lenght = 0;
	
	for(int i = 0; i < strlen(serial_number); i++, lenght ++){
		if((serial_number[i] < '0') || (serial_number[i] > '9')){
			return 0;
		}
	}
	if(lenght != 10){
		return 0;
	}
	
	return 1;
}

int check_date(char serial_number[MAX_LENGHT]){
	
	int date;
	int month;
	int year;
	int max_date = 31;
	
	date = (serial_number[4] - '0') * 10 + (serial_number[5] -'0');
	month = (serial_number[2] - '0') * 10 + (serial_number[3] -'0');
	year = (serial_number[0] - '0') * 10 + (serial_number[1] -'0');
	
	
	if(!((month >= 1 && month <= 12) || (month >= 21 && month <= 32) || (month >= 41 && month <= 52))){
		return 0;
	}
	
	switch(month){
		case 1: max_date = 31; break;
		case 2: if(year % 4 == 0){
			 max_date = 29;
		}
		else{
			max_date = 28;
		} break;
		case 3: max_date = 31; break;
		case 4: max_date = 30; break;
		case 5: max_date = 31; break;
		case 6: max_date = 30; break;
		case 7: max_date = 31; break;
		case 8: max_date = 31; break;
		case 9: max_date = 30; break;
		case 10: max_date = 31; break;
		case 11: max_date = 30; break;
		case 12: max_date = 31; break;
		case 21: max_date = 31; break;
		case 22: if(year % 4 == 0){
			 max_date = 29;
		}
		else{
			max_date = 28;
		} break;
		case 23: max_date = 31; break;
		case 24: max_date = 30; break;
		case 25: max_date = 31; break;
		case 26: max_date = 30; break;
		case 27: max_date = 31; break;
		case 28: max_date = 31; break;
		case 29: max_date = 30; break;
		case 30: max_date = 31; break;
		case 31: max_date = 30; break;
		case 32: max_date = 31; break;
		case 41: max_date = 31; break;
		case 42: if(year % 4 == 0){
			 max_date = 29;
		}
		else{
			max_date = 28;
		} break;
		case 43: max_date = 31; break;
		case 44: max_date = 30; break;
		case 45: max_date = 31; break;
		case 46: max_date = 30; break;
		case 47: max_date = 31; break;
		case 48: max_date = 31; break;
		case 49: max_date = 30; break;
		case 50: max_date = 31; break;
		case 51: max_date = 30; break;
		case 52: max_date = 31; break;
	}
	
	if((1 <= date) && (date <= max_date)){
		return 1;
	}
	return 0;
}

int check_control_number(char serial_number[MAX_LENGHT]){
	
	int control_number = 0;
	char weight[10] = {2, 4, 8, 5, 10, 9, 7, 3, 6};
	
	for(int i = 0; i < 9; i++){
		control_number = ((serial_number[i] - '0') * weight[i]) + control_number;
	}
	
	control_number = control_number % 11; 
	
	if((serial_number[9] - '0') == control_number){
		return 1;
	}
	
	return 0;
	
}


