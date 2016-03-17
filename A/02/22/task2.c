#include <stdio.h>
#include <string.h>

char* find(char *, char);

int main()
{
	char haystack[400];
	char needle;
	char *ptr;
	fgets(haystack, 400, stdin);
	scanf("%c",&needle);
	ptr=find(haystack, needle);
	if(ptr!=NULL)
	{
		printf("%ld", ptr-haystack);
	}
	else
	{
		printf("-1");
	}
	return 0;
}

char* find(char *haystack, char needle)
{
	int i=0, temp=0;
	char*ptr;
	while(i<strlen(haystack))
	{
		if(needle==haystack[i])
		{
			temp=1;
			break;
		}
		i++;
	}
	if(temp==1)
	{
		ptr=&haystack[i];
	}
	else
	{
		ptr=NULL;
	}
	return ptr;
}