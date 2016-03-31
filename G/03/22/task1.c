#include <stdio.h>
#include <string.h>

int is_valid(int *);
int is_valid_int(char);

int main(){

	char egn[12];
	int egn_int[10], i;
	
	scanf("%s", egn);

	if(strlen(egn) != 10){
	
		printf("0\n");
	
	}else{
	
		for(i = 0; i < 10; i++){
		
			egn_int[i] = is_valid_int(egn[i]);
		
			if(egn_int[i] == -1){
			
				printf("0\n");
				return 0;
			
			}
		
		}
	
	}

	printf("%d\n", is_valid(egn_int) );

	return 0;

}

int is_valid(int *egn){

	int valid_d, valid_m, control;
	
	control = (egn[0]*2 + egn[1]*4 + egn[2]*8 + egn[3]*5 + egn[4]*10 + egn[5]*9 + egn[6]*7 + egn[7]*3 + egn[8]*6)%11;
	valid_d = egn[4]*10 + egn[5];
	valid_m = egn[2]*10 + egn[3];
	
	if( (valid_m > 12 && valid_m < 21) || (valid_m > 32 && valid_m < 41) || (valid_m > 52) || (valid_d > 31)){
	
		return 0;
	
	}else if( ((control == 10) ? 0 : control ) != egn[9] ){
	
		return 0;
	
	}

	return 1;

}

int is_valid_int(char c){

	switch(c){
	
			case '0': return 0;
			case '1': return 1;
			case '2': return 2;
			case '3': return 3;
			case '4': return 4;
			case '5': return 5;
			case '6': return 6;
			case '7': return 7;
			case '8': return 8;
			case '9': return 9;
			default : return -1;
	
	}	

}
