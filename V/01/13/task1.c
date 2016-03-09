#include <stdio.h>
#include <string.h>

long hash(char *word);

int main()
{
	char word[200];
	do
	{
		scanf("%s",word);
	}while(strlen(word)>200);
	printf("%ld",hash(word));
	return 0;
}

long hash(char *word)
{
	long hash = 42;
	int i, len = strlen(word);
	for(i=0;i<len;i++)
	{
		hash += word[i] * (i+1);
	}
	return hash;
}
