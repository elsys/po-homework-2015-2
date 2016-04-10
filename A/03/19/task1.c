#include <stdio.h>
#include <string.h>

#define MAX 20

int valid_id(char*);
int check_year(char*);
int check_date(int, int, int);
int check_number(char*);

int main(){
	char input[MAX];
	scanf("%[^\n]s", input);
	
	printf("%d", valid_id(input));
	
	return 0;
}

int valid_id(char* id){
	if (strlen(id) != 10)
		return 0;
	
	if(check_year(id) && check_number(id))
		return 1;
	else
		return 0;
}

int check_date(int year, int month, int day){	 
	 
	if(day > 31) return 0;
	 
 	if(month < 8){
 		if (month == 2){
 			if(year % 4 == 0)
 				if(day <= 29)
 					return 1;
 				else
 					return 0;
 			else
 				if(day < 29)
 					return 1;
 				else
 					return 0;
	 	}
	 	else
 		 	if((month % 2 == 0 && day <= 30) || (month % 2 == 1 && day <=31))
 		 		return 1;
 		 	else
 		 		return 0;
	}
 	else if(month >= 8 && month <= 12){
 		if((month % 2 == 0 && day <= 30) || (month % 2 == 1 && day <=31))
 			return 1;
 		else
 			return 0;
	 }
	 else
	 	return 0;
}

int check_year(char* id){
	int day = (id[5] + (id[4] - '0') * 10) - '0'; 
	int month = (id[3] + (id[2] - '0') * 10) - '0'; 
	int year = (id[1] + (id[0] - '0') * 10) - '0';
		
	if(id[2] <= '5'){
		if(id[2] >= '4'){
			return check_date(2000 + year, month - 40, day);
		}
		else if(id[2] >= '3'){
			return check_date(1800 + year, month - 20, day);
		}
		else{
			return check_date(1900 + year, month, day);
		}
	}
	else{
		return 0;
	}
}

int check_number(char* id){
	int sum = (id[0] - '0') * 2 + (id[1] - '0') * 4 + (id[2] - '0') * 8 + (id[3] - '0') * 5
	 + (id[4] - '0') * 10 + (id[5] - '0') * 9 + (id[6] - '0') * 7 + (id[7] - '0') * 3 + (id[8] - '0') * 6;
	sum %= 11;
	
	if(sum == 10){
		sum = 0;
	}
	
	if(id[9] == sum + '0'){
		return 1;
	}
	else{
		return 0;
	}
}
