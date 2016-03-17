#include <stdio.h>
#include <string.h>

long hash (char *word);
int main ()
{
	char word[200];
	fgets (word, 200 , stdin);
	hash (word);
	return 0;
}
long hash (char *word)
{
	int sum = 42,i , n = 0,temp;
	n = strlen(word) - 1;
	for (i = 0; i < n; i++)
	{
		temp=word[i]*(i+1);
		sum=sum +temp;
	

	}
	printf("%d\n", sum );



	return sum;
}