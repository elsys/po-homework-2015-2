#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* find(char *haystack,char needle);

int main()
{
	char haystack[400]={'\0'},needle;
	char *result;
	do{
		scanf("%s",haystack);
	}while(strlen(haystack)>400);
	scanf("%s",&needle);
	result=find(haystack,needle);
	if(result==NULL)
	{
		printf("\n-1");
	}
	else
	{
		printf("\n%d",(int)(result-haystack));
	}
	return 0;
}

char* find(char *haystack,char needle)
{
	int i;
	char *result;
	for(i=0;i<strlen(haystack);i++)
	{
		if(haystack[i]==needle)
		{
			result=&haystack[i];
			return result;
		}
	}
	return NULL;
}
