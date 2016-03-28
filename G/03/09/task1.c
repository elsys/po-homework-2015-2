#include <stdio.h>
#include <string.h>

int main(){

char EGN[12];


scanf("%s", &EGN);




if(EGN[2]<48 && EGN[2] >53 ){
	printf("0");
	return 1;
}



if(EGN[3]<48 && EGN[3] >53 ){
	printf("0");
	return 1;
}


if(EGN[2]==48 && EGN[3] == 50 ){
	if(EGN[4] > 50 && EGN[4] < 48){
		printf("0");
		return 1;
	}
}

if((EGN[2]== 48 && EGN[3] == 52) || (EGN[2] == 48 && EGN[3] == 54) || (EGN[2] == 48 && EGN[3] == 57) || (EGN[2] == 49 && EGN[3] == 49) ){
	if(EGN[4] == 51 && EGN[5] != 48 ){
		printf("0");
		return 1;
	}
}

if((EGN[2]== 48 && EGN[3] == 49) || (EGN[2] == 48 && EGN[3] == 51) || (EGN[2] == 48 && EGN[3] == 53) || (EGN[2] == 48 && EGN[3] == 55) || (EGN[2] == 48 && EGN[3] == 56) || (EGN[2] == 49 && EGN[3] == 48) || (EGN[2] == 49 && EGN[3] == 50) ){
	if(EGN[4] == 51 && (EGN[5] != 48 || EGN[5] !=49) ){
		printf("0");
		return 1;
	}
}



printf("1");




return 0;
}
