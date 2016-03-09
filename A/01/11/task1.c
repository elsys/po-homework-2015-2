#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long hash(char* word);

int main()
{
	int hashed;
	char word[200];

	scanf("%s", word);

	hashed = hash(word);

	printf("%d", hashed);

	return 0;
}

long hash(char* word)
{
	int i;
	long base = 42;
	
	for(i = 0; i < strlen(word); i++)
	{
		base += word[i]*(i+1);
	}

	return base;
}
