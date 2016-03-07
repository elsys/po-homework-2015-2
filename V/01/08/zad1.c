#include <stdio.h>

long hash(char *word);

int main()
{
	char word [200];

	scanf("%s",word);



	printf("%li\n", hash(word) );	

	return 0;
}

long hash(char *word)
{
	long hash1=42;
	int len=0;
	while(word[len]!='\0') len++; 
	

	for (int i = 0; i < len; ++i)
	{
		hash1 += ((long)word[i])*(i+1);
	}

	return hash1;
}