#include <stdio.h>
#include <string.h>
#define STRINGLENGTH 12

int validation_for_months(int *pegn);
int validation_for_checkpoint(int *pegn);

int main()
{
	char inp_egn[STRINGLENGTH];
	int pegn[STRINGLENGTH];
	int i,valid1 = -2,valid2 = -2;
	
	scanf("%s",inp_egn);
	

	for( i = 0; i < 10; i++)
	{
		pegn[i] = inp_egn[i] - '0';
	}

	/*for ( i = 0; i < 10; ++i)
	{
		printf("%d",pegn[i]);
	}*/

	valid1 = validation_for_months(pegn);

	valid2 = validation_for_checkpoint(pegn);
	if((valid2 == pegn[9]) && valid1 == 1)
		printf("1");
	else 
		printf("0");




	


	return 0;
}

int validation_for_months(int *ptr)
{
	int date,check = 0;


	date = ptr[2] * 10 + ptr[3];
	//printf("date = %d",date);

	if((date >= 1 && date <= 12)||(date >= 21 && date <= 32)||(date >= 41 && date <= 52))
		check =  1;

	//printf("month \n%d\n",check);
	return check;
}

int validation_for_checkpoint(int *ptr)
{
	int checkpoint,checkpoint_remainder;


	checkpoint = (ptr[0]*2 + ptr[1]*4 + ptr[2]*8 + ptr[3]*5 + ptr[4]*10 + ptr[5]*9 + ptr[6]*7 + ptr[7]*3 +ptr[8]*6);


	checkpoint_remainder = checkpoint % 11;


	if(checkpoint_remainder == 10)checkpoint_remainder = 0;
	//printf("checkpoint :%d\n ",checkpoint_remainder);
	return checkpoint_remainder;	
}