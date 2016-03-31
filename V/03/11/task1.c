#include<stdio.h>

void correct_month(char* EGN, int *valid){

	int number=(EGN[3]-48)*10+EGN[4]-48;

	if(EGN[2]=='4' || EGN[2]=='0' || EGN[2]=='2'){
		switch(EGN[3]){
			case '1': if(number>31){
				*valid=0;
				break;
			}
			case '2': if(number>29){
				*valid=0;
				break;
				}
			case '3': if(number>31){
				*valid=0;
				break;
			}
			case '4': if(number>30){
				*valid=0;
				break;
			}
			case '5': if(number>31){
				*valid=0;
				break;
			}
			case '6': if(number>30){
				*valid=0;
				break;
			}
			case '7': if(number>31){
				*valid=0;
				break;
			}
			case '8': if(number>31){
				*valid=0;
				break;
			}
			case '9': if(number>30){
				*valid=0;
				break;
			}
		}
	}else{
		if(EGN[2]=='3' || EGN[2]=='5' ||EGN[2]=='1'){
			switch(EGN[3]){
				case '0': if(number>31){
					*valid=0;
					break;
				}
				case '1': if(number>30){
					*valid=0;
					break;
				}
				case '2': if(number>31){
					*valid=0;
					break;
				}
			}
		}
	}
}

int main(){
	char EGN[12];
	int valid=1;
	scanf("%s",EGN);	

	if(EGN[0]=='0' && EGN[1]=='0'){
		if(EGN[2]>53 || EGN[2]<50){
			valid=0;
		}
	}
	else {
		if(EGN[2]>53 || EGN[2]<48){
			valid=0;
		}
		if(EGN[3]>50){
			valid=0;
			correct_month(EGN, &valid);
		}
	}
	printf("%d",valid);
	return 0;
}

