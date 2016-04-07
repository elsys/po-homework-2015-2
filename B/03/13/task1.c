#include<stdio.h>
#include<string.h>

int if_all_digits(char *);
int make_integers(char *, int );
int if_lead_year(int );
int if_last_digit_right(char *);

int main(){

char EGN[12];

	scanf("%s", EGN);

	if(strlen(EGN) == 10){

		if(if_all_digits(&EGN[0]) == 1){

			int last_digit = make_integers(&EGN[9],1);
			int year = make_integers(&EGN[0],2);
			int month = make_integers(&EGN[2],2);
			int day = make_integers(&EGN[4],2);
				if(month > 12) month -= 40;

			switch(month){

				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:if(day > 31 || day < 1) printf("0");
					else{
					
					if(last_digit == if_last_digit_right(&EGN[0])) printf("1");
					else printf("0");
	
				}
					break;

				case 4:
				case 6:
				case 9:
				case 11:if(day > 30 || day < 1) printf("0");
					else{

					if(last_digit == if_last_digit_right(&EGN[0])) printf("1");
					else printf("0");
	
				}
					break;

				case 2: if(if_lead_year(year) == 1){

					if(day > 29 || day < 1) printf("0");
					else{

					if(last_digit == if_last_digit_right(&EGN[0])) printf("1");
					else printf("0");

					}

				}else{

					if(day > 28 || day < 1) printf("0");
					else{

					if(last_digit == if_last_digit_right(&EGN[0])) printf("1");
					else printf("0");

					}

				}
					break;

				default: printf("0");
					break;
				
			}

		}else{

		printf("0");

		}

	}else{
	
	printf("0");

	} 

	return 0;
}


int if_all_digits(char *EGN){
	
	int counter = 0;

	for(; counter < 10; counter++){
		
		//printf("%c %d\n", *(EGN + counter), counter);
		if(*(EGN+counter) < 48  ||  *(EGN+counter) > 57) break;
	}

	if(counter == 10) return 1;
	else return 0;
}



int make_integers(char *number, int how_many){
	
	int counter = 0;
	int result = 0;
	for(; counter < how_many; counter++){
		
		result = result*10 + (*(number + counter) - 48);

	}

	return result;
}


int if_lead_year(int year){

	if(year % 4 == 0){

		if(year % 100 == 0){
			
			if(year % 400 == 0){
			
				return 1;			

			}else return 0;
		}else return 1;

	}else return 0;
}



int if_last_digit_right(char *EGN){

	int counter = 0;
	int result = 0;
	for(; counter < 9; counter++){

		switch(counter){
		
		case 0: result += (*(EGN + counter) - 48) * 2;
			break;
		case 1: result += (*(EGN + counter) - 48) * 4;
			break;
		case 2: result += (*(EGN + counter) - 48) * 8;
			break;
		case 3: result += (*(EGN + counter) - 48) * 5;
			break;
		case 4: result += (*(EGN + counter) - 48) * 10;
			break;
		case 5: result += (*(EGN + counter) - 48) * 9;
			break;
		case 6: result += (*(EGN + counter) - 48) * 7;
			break;
		case 7: result += (*(EGN + counter) - 48) * 3;
			break;
		default:result += (*(EGN + counter) - 48) * 6;
			break;
		}

	}

	if(result % 11 == 10) return 0;
	else return result % 11; 

}


