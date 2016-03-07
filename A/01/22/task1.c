#include <stdio.h>
#include <string.h>

long hash(char *);

int main()
{
	char word[200];
	scanf("%s",word);
	printf("%ld\n", hash(word));
	return 0;
}

long hash(char *word)
{
	long hash=42;
	int n, i=0, temp;
	n=strlen(word);
	while(i!=n)
	{
		temp=word[i];
		hash=hash+(temp*(i+1));
		i++;
	}
	return hash;
}