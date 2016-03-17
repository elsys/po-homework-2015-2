#include <stdio.h>
#include <string.h>

long hash (char *word)
{
	int start = 42;
	int l;
	int counter;

	scanf("%s",word);

	l = strlen(word);

	for(counter = 0; counter <= l; counter++)
	{
		l = strlen(word);
		start = start + (word[counter] * (counter + 1));

	}

	return start;
}

int main() 
{
	char word[200];

	printf("%ld\n", hash(word));

	return 0;
}