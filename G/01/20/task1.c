#include <stdio.h>

long hash(char* word);

int main()
{
	char word[201] = {0};
	
	scanf("%s", word);
	printf("%li", hash(word));

	return 0;
}

long hash(char* word)
{
	int counter=0;
	long hashed = 42;
	
	while(word[counter] != '\0')
	{
		hashed += word[counter]*(counter+1);
		counter ++;
	}

	return hashed;
}
