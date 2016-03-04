#include <stdio.h>
#include "hash.h"

long int hash(char *word);

int main()
{
	char input[200];
	long int output;
	scanf("%s",input);
	output=hash(input);
	printf("%ld\n", output);
	return 0;
}