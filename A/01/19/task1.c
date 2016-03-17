#include <stdio.h>
#include <string.h>

long hash(char *);

int main()
{
	char input[200] = {0};
	scanf("%s", input);
	
	printf("%ld", hash(input));

	return 0;
}

long hash(char *word)
{
	long sum = 42;
	int ascii = 0;
	
	for(int i = 0; i < strlen(word); i++)
	{
		ascii = word[i];
		sum += (ascii * (i + 1));
	}

	return sum;
}
