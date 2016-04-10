#include <stdio.h>
#include <string.h>

int check_ISBN(char *);
int check_phouse(char *);

int main(){

	char ISBN[20];
	
	scanf("%s", ISBN);

	printf("%d\n", check_ISBN(ISBN));
	
	if(check_ISBN(ISBN)){
	
		switch(check_phouse(ISBN)){
	
			case 1: printf("Bluebridge\n"); break;
			case 2: printf("Alyson Books\n"); break;
			case 3: printf("FUNimation Productions, Ltd.\n"); break;
			case 4: printf("Pyramid Books\n"); break;
			default: break;
		
		}

	}

	return 0;

}

int check_ISBN(char *ISBN){

	int i, j = 0, k = 0, check_digit = 0, ISBN_digit[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int ISBN_int[5] = {0, 0, 0, 0, 0};
	
	for(i = 0; i < strlen(ISBN); i++){
	
		while(ISBN[i] >= '0' && ISBN[i] <= '9'){
		
			ISBN_digit[k] = (ISBN[i] - '0');
			ISBN_int[j] = (ISBN_int[j]*10) + (ISBN[i] - '0');
			i++;
			k++;
			if(i > 17 || k >13){
			
				return 0;
			
			}
		
		}
		
		if(j == 0 && (ISBN_int[0] != 978 && ISBN_int[0] != 979)){
	
			return 0;
	
		}
		
		j++;
	
	}
	
	check_digit = (ISBN_digit[0]*1 + ISBN_digit[1]*3 + ISBN_digit[2]*1 + ISBN_digit[3]*3 + ISBN_digit[4]*1 + ISBN_digit[5]*3 + ISBN_digit[6]*1 + ISBN_digit[7]*3 + ISBN_digit[8]*1 + ISBN_digit[9]*3 + 					   ISBN_digit[10]*1 + ISBN_digit[11]*3 )%10;
	
	if( (10 - check_digit) == ISBN_int[i-1] ){
	
		return 1;
	
	}
	
	return 0;

}

int check_phouse(char *ISBN){

	int i, j = 0;
	int ISBN_int[5] = {0, 0, 0, 0, 0};
	
	for(i = 0; i < strlen(ISBN); i++){
	
		while(ISBN[i] >= '0' && ISBN[i] <= '9'){
		
			ISBN_int[j] = (ISBN_int[j]*10) + (ISBN[i] - '0');
			i++;
		
		}
		
		j++;
	
	}
	
	switch(ISBN_int[2]){
	
		case 933346: return 1; break;
		case 55583: return 2; break;
		case 4210: return 3; break;
		case 01: return 4; break;
		default: break;
	
	}
	
	return 0;

}
