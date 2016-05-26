#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* find(char *haystack,char needle);

int main()
{
	char haystack[400]={'\0'},needle;
	char *result;
	fgets(haystack,400,stdin);
	scanf("%c",&needle);
	result=find(haystack,needle);
	if(result!=NULL)
	{
		printf("\n%d",(int)(result-haystack));
	}
	else
	{
		printf("\n-1");
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
