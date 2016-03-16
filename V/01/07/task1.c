#include <stdio.h>
#include "hash.h"

long int hash(char *word);

int main()
{
	char input[200];
	long int output;
	short unsigned int l;
	fgets(input, 200*sizeof(char), stdin);
	l=strlen(input)-1;
	input[l]='\0';
	output=hash(input);
	printf("%ld\n", output);
	return 0;
}