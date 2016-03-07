#include <stdio.h>
#include <string.h>


long hash(char *);
int main()
{

	char word[200];
	printf("%ld",hash(word));

	return 0;
}
long hash(char *word)
{
	long i=42,l;
	scanf("%s",word);
	l = strlen(word);
	for(;l>=0;l--)
	{
		i=i+word[l]*(l+1);	
	}

	return i;
}
