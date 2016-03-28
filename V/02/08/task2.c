#include <stdio.h>

char* find(char *haystack, char needle);

int main()
{
	
	char haystack[401],  needle;

	for (int i = 0; i < 400 ; ++i)
	{
		haystack[i]=fgetc(stdin);
		if(haystack[i]==EOF || haystack[i]=='\n' )break;

	}
	scanf("%c",&needle);

	char *pt=find( haystack, needle);
	if(pt==NULL)printf("%d", -1);
	else
	printf("%d\n",pt-haystack );
	
	
	return 0;
}

char* find(char *haystack, char needle)
{
	for (int i = 0; i < 400 && haystack[i]!='\0'; ++i)
	{
		if(haystack[i] == needle)return &haystack[i];
	}
	return (char*)NULL;
}