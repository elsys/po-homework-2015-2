#include <stdio.h>
#include <string.h>

int date_validation(int *real_EGN);

int control_digit_validation(int *real_EGN);

int main(){
	char entered_EGN[12];

	int real_EGN[12] , counter , validation_one = -2 , validation_two = -2;

	scanf("%s", entered_EGN);

	for( counter = 0; counter < 10; counter++){
		real_EGN[counter] = entered_EGN[counter] - '0';
	}

	validation_one = date_validation(real_EGN);

	validation_two = control_digit_validation(real_EGN);

	if(validation_one == 1 && (validation_two == real_EGN[9]))
		printf("1");
	else
		printf("0");

	return 0;
}

int date_validation(int *digit){

	int correct = 0 , date ;

	date = digit[2] * 10 + digit[3];

	if((date >= 1 && date <= 12)||(date >= 21 && date <= 32)||(date >= 41 && date <= 52))
		correct =  1;

	return correct;
}
int control_digit_validation(int *digit){

	int result ,control_digit;

	result = (digit[0]*2 + digit[1]*4 + digit[2]*8 + digit[3]*5 + digit[4]*10 + digit[5]*9 + digit[6]*7 + digit[7]*3 + digit[8]*6);

	control_digit = result % 11;

	if(control_digit == 10)

        control_digit = 0;

	return control_digit;
}
