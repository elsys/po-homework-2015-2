#include <stdio.h>
#include <string.h>
char* find(char *haystack, char needle);

int main()
{
	int i = 0;
	char search, in[401] = { 0 };
	while(1)
	{
		scanf("%c",&in[i]);
		if(in[i] == '\n') break;
		else i++;
	}
	scanf("%c",&search);

	printf("%ld\n",( find(in,search) != NULL ) ? (find(in,search) - in) : -1);

	return 0;
}

char* find(char *haystack, char needle)
{
	int l = strlen(haystack) - 1;
	for(int i = 0 ; i < l ; i++)
	{
		if(haystack[i] == needle) return (haystack+i);
	}
	return NULL;
}