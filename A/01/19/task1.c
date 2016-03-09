#include <stdio.h>
#include <string.h>

long hash(char *word);

int main()
{
	char input[200];
	fgets(input, 200, stdin);
	
	printf("%ld", hash(input));

	return 0;
}

long hash(char *word)
{
	long sum = 42;
	int ascii = 0;
	
	for(int i = 0; i < strlen(word) - 1; i++)
	{
		ascii = word[i];
		sum += (ascii * (i + 1));
	}

	return sum;
}
