#include <stdio.h>
#include <string.h>
#define MAX 200

long hash(char *word);

int main()
{
	int result;
	char arr[MAX];
	

	scanf("%s",arr);
		
	result = hash(arr);
	
	printf("%d",result );

	return 0;
}

long hash(char *word)
{
	int i,len;
	long asc = 42;

	len = strlen(word) - 1;
	
	for(i = 0; i <= len ; i++)
	{
		asc +=   word[i] * (i + 1);
	}

	return asc;
}
