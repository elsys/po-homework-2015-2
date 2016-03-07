#include <stdio.h>
#include <string.h>


long hash(char *word);

int main()
{
	char word[200];
	int i, p = 0, hashv = 42;
 
	scanf ("%s", word);
	i = strlen(word);
	

	for (; p<i; p++)
	{
		hashv= hashv + hash(&word[p]);
	}

			
	printf ("%d", hashv);

	return 0;
}

long hash (char *word)
{
	int result;
	static int counter = 0;
	counter ++;
	result = *word * counter;
	

	return result;
}


