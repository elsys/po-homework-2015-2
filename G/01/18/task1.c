#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long hash(char *);
int main()
{

	int answer;
	char word[200];
	
	scanf("%s",word);
	
	answer = hash(word);
	
	printf("%d\n", answer);

	return 0;
}

long hash(char *word)
{
	int l, count, i, end = 42, k;
	
	l = strlen(word);
	
	for(count = 0, i = 1; count < l; count++, i++)
		{
			k = word[count];
			k = k * i;
			end = end + k;
		}
	
	return end;

}
