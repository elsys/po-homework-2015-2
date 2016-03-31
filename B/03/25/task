#include<stdio.h>
void correct_month(char*, int*);
int main(){
	char egn[12];
	int helper = 1;
	scanf("%s", egn);	

	if(egn[0]== '0' && egn[1]== '0'){
		if(egn[2] < 50 || egn[2] >53) helper = 0;
	}
	else {
		if(egn[2] < 48 || egn[2] > 53) helper = 0;
		if(egn[3] > 50) helper = 0;
		correct_month(egn, &helper);
	}
	printf("%d", helper);

return 0;
}

void correct_month(char* egn, int *helper){
	int number = (egn[3] - 48) * 10 + egn[4] - 48;
	if(egn[2] == '0' || egn[2] == '2'|| egn[2] == '4'){
		switch (egn[3]){
			case '1': if(number > 31) *helper =0; break;
			case '2': if(number > 29) *helper =0; break;
			case '3': if(number > 31) *helper =0; break;
			case '4': if(number > 30) *helper =0; break;
			case '5': if(number > 31) *helper =0; break;
			case '6': if(number > 30) *helper =0; break;
			case '7': if(number > 31) *helper =0; break;
			case '8': if(number > 31) *helper =0; break;
			case '9': if(number > 30) *helper =0; break;
		}
	}else if(egn[2] == '1' || egn[2] == '3' || egn[2] == '5'){
			switch(egn[3]){
				case '0': if(number > 31) *helper =0; break;
				case '1': if(number > 30) *helper =0; break;
				case '2': if(number > 31) *helper =0; break;
			}
		}
}
