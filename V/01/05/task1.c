#include <stdio.h>
#include <string.h>

long hash(char *word);

int main()
{
	char input[200] = {0};
    
    scanf("%s", input);
	printf("%ld", hash(input));
	return 0;
}

long hash(char *word)
{
	int begin = 42;
	int i = 1,l = strlen(word);
	while(i <= l)
	{	
		begin += word[i - 1] * i;
		i++;
	}
	return begin;
}
