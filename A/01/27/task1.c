#include <stdio.h>
#include <string.h>

long hash(char*);

int main()
{
	char word[200];

	fgets(word, 200, stdin);
	printf("%li", hash(word));
	return 0;
}
long hash(char *word)
{
	int value = 42;
	if(strlen(word) > 1)
	{
		for(int i = 0; i < strlen(word); i++)
		{
			value = value + word[i]*(i+1);
		}
	}
	return value;
}
