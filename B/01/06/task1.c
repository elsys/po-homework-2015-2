#include <stdio.h>
#include <string.h>

long hash(char *word);

int main()
{
	char word[200];
	
	scanf("%s", word);
	printf("%ld", hash(word));
	
	return 0;
}

long hash(char *word)
{
	int count = 0, length;
	int hash = 42;
	
	length = strlen(word);
	for(; count<length; count++)
		hash = hash + word[count] * (count + 1);
	return hash;
}