#include <stdio.h>
#include <string.h>

#define WRONG_ISBN 0
#define CORRECT_ISBN 1

int prefix(char *ISBN13);
char convert(char *ISBN, char *ISBN13);
int all(char *ISBN13);
int check(char *ISBN13);

int main() {

	char ISBN[20];
	char ISBN13[20];

	scanf("%s", ISBN);

	convert(ISBN, ISBN13);

	if(prefix(ISBN13) == 0)
	{
		return 0;
	}
	if(all(ISBN13) == 0)
	{
		return 0;
	}

	if((ISBN13[4] - 48) == 9 && (ISBN13[5] - 48) == 3 && (ISBN13[6] - 48) == 3 &&
	(ISBN13[7] - 48) == 3 && (ISBN13[8] - 48) == 4 && (ISBN13[9] - 48) == 6)
	{
		printf("Bluebridge\n");	
	}
	
	if((ISBN13[4] - 48) == 5 && (ISBN13[5] - 48) == 5 && (ISBN13[6] - 48) == 5 &&
	(ISBN13[7] - 48) == 8 && (ISBN13[8] - 48) == 3)
	{
		printf("Alyson Books\n");
	}

	if((ISBN13[4] - 48) == 4 && (ISBN13[5] - 48) == 2 && (ISBN13[6] - 48) == 1 &&
	(ISBN13[7] - 48) == 0)
	{
		printf("FUNimation Productions, Ltd.\n");
	}

	if((ISBN13[4] - 48) == 0 && (ISBN13[5] - 48) == 1)
	{
		printf("Pyramid Books\n");
	}

	if(check(ISBN13) == (ISBN13[12] - 48))
	{
		printf("1\n"); return 0;
	}
	else
	{
		printf("0\n"); return 0;
	}

	return 0;
}

char convert(char *ISBN, char *ISBN13) {

	int counter;
	int help;	

	for(counter = 0; counter < 20; counter++)
	{
		if(ISBN[counter] >= '0' && '9' >= ISBN[counter])
		{
			ISBN13[help] = ISBN[counter];
			help++;
		}
	}

	return 0;
}

int prefix(char *ISBN13) {

		
	if(ISBN13[0] == '9' && ISBN13[1] == '7' && (ISBN13[2] == '8' || ISBN13[2] == '9'))
	return CORRECT_ISBN;
	else {
		printf("0\n");
		return WRONG_ISBN;
	}

	return -1;
}

int all(char *ISBN13) {
	
	int counter;	
	
	for(counter = 0; 1; counter++)
	{
		if(ISBN13[counter] == '\0') break;
	}

	if(counter != 13)
	{
		printf("0\n");
		return WRONG_ISBN;
	}
	
	return -1;
}

int check(char *ISBN13)
{
	int sum = 0;
	int num = 0;	
	int check = 0;

	ISBN13[0] = (ISBN13[0] - 48) * 1;
	ISBN13[1] = (ISBN13[1] - 48) * 3;
	ISBN13[2] = (ISBN13[2] - 48) * 1;
	ISBN13[3] = (ISBN13[3] - 48) * 3;
	ISBN13[4] = (ISBN13[4] - 48) * 1;
	ISBN13[5] = (ISBN13[5] - 48) * 3;
	ISBN13[6] = (ISBN13[6] - 48) * 1;
	ISBN13[7] = (ISBN13[7] - 48) * 3;
	ISBN13[8] = (ISBN13[8] - 48) * 1;
	ISBN13[9] = (ISBN13[9] - 48) * 3;
	ISBN13[10] = (ISBN13[10] - 48) * 1;
	ISBN13[11] = (ISBN13[11] - 48) * 3;

	sum = ISBN13[0] + ISBN13[1] + ISBN13[2] + ISBN13[3] + ISBN13[4] + ISBN13[5]
	+ ISBN13[6] + ISBN13[7] + ISBN13[8] 
	+ ISBN13[9] + ISBN13[10] + ISBN13[11];

	num = sum % 10;

	check = 10 - num;

	return check;
}
