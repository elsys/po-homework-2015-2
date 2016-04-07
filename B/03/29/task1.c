#include<stdio.h>
#include<string.h>


int main(){

	char egn[12];
	int sumation[12];
	int index = 0;
	int breaker = 1;
	scanf("%s",egn);
	
	
	
	//check valid string length
	if (strlen(egn)!=10)breaker = 0;
	
	//check if they are only numbers
	for (;index < 10; index++){
	
		if(egn[index] < '0' || egn[index] > '9')
			breaker = 0;
	
	}
	
	
	//check valid year
	if (egn[0] < '0' || egn[0] > '9')breaker = 0;
	if (egn[1] < '0' || egn[1] > '9')breaker = 0;
	
	//check valid month
	if (egn[2] < '0' || egn[2] > '5')breaker = 0;
	else{
		if (egn[2] == '1' && egn[3] > '2')breaker = 0;
		if (egn[2] == '2' && egn[3] == '0')breaker = 0;
		if (egn[2] == '3' && egn[3] > '2')breaker = 0;
		if (egn[2] == '4' && egn[3] == '0')breaker = 0;
		if (egn[2] == '5' && egn[3] > '2')breaker = 0;
	
	}
	
	//check valid date
	if (egn[4] < '0' || egn[4] > '3')breaker = 0;
	if (egn[4] == '3' && egn[5] > '1')breaker = 0;
	if (egn[5] < '0' || egn[5] > '9')breaker = 0;
	
	
	for (index = 0; index < 10 ; index++){
	
		sumation[index] = egn[index] - '0';
	}
	sumation[10] = ( sumation[0] * 2 +
			sumation[1] * 4 +
			sumation[2] * 8 + 
			sumation[3] * 5 + 
			sumation[4] * 10 + 
			sumation[5] * 9 + 
			sumation[6] * 7 +
			sumation[7] * 3 + 
			sumation[8] * 6) % 11;
	
	if (sumation[10] == 10)sumation[10] = 0;
	
	if (sumation[10] != sumation[9])breaker = 0;
			
	
	
	
	
	
	//printing...
	printf("%d",breaker);
	
	return 0;
}
