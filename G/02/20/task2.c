#include <stdio.h>
#include <string.h>

char* find(char *haystack ,char needle)
{
	int i;
		
	for(i = 0;haystack[i] != '\0';i++)
	{
		if(haystack[i]==needle)
		{
			return &haystack[i];
		}
	}
	return NULL;
}
int main() 
{
	char haystack[400]; 
	char needle, *index = 0;
	
	scanf("%[^\n]s",haystack);
	getchar();
	scanf("%c",&needle); 
	
	if(find(haystack ,needle) == NULL )
	{
		printf("-1\n");
	}
	else
	{
		index = find(haystack ,needle);
		printf("%d\n",(int)(index - haystack));
	}
	return 0;
}
