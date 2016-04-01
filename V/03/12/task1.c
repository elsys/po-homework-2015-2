#include <stdio.h>
#include <string.h>


int ch_correct(char egn[]);
int main(){
	char egn[13];
	do{
		scanf("%s",egn);
//		printf("%d",strlen(egn));
	}while(strlen(egn) > 12);
	if(strlen(egn)!= 10){
		printf("0");
	}else{
		printf("%d",ch_correct(egn));
	}
	return 0;
}

int ch_correct(char egn[]){
	int count = 2;
	int teglo[9] = {2,4,8,5,10,9,7,3,6};
	int checkY = 0, checkM = 0, checkD = 0;
	for(int i = 0; i < count; i++){
		checkY += (egn[i] - '0') * 10 + (egn[i] - '0');
	}
	if(checkY > 99){
//		printf("Y");
		return 0;
	}
	count+=2;
	for(int i = count - 2; i < count; i++){
		checkM =(egn[i] - '0') * 10 + (egn[i] - '0');
	}
	if(!((checkM >= 1 && checkM <= 12) || (checkM >= 21 && checkM <= 32) ||
	(checkM >= 41 && checkM <= 52) )){
//		printf("M");
		return 0;
	}
	for(int i = 0; i < 10; i++){
		checkD += (egn[i] - '0') * teglo[i];
	}
	if(checkD % 11 != egn[9] - '0'){
//		printf("D");
		return 0;
	}
	return 1;
}

