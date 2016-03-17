#include <stdio.h>
#include <string.h>

long hash(char *word);

int main()
{
	char input[200] = {0};
	int output;
	scanf("%s",input);
	output = hash(input);
	printf("%d\n", output);
	return 0;
}

long hash(char *word)
{
	int begin = 42;
	int i = 0,l;
	l = strlen(word);
	while(i < l)
	{
		begin += word[i]*(i + 1);
		i++;
	}
	return begin;
}
