#include <stdio.h>
#include <string.h>

char* find (char *haystack, char needle);
	
int main()
{
	char haystack[400];
	char needle;
	char *counter;

	scanf("%[^\n]s", haystack);
	scanf("%s", &needle);

	if(find(haystack, needle) == NULL)
	{
		printf("-1\n");
	}
	else
	{
		counter = find(haystack, needle);

		printf("%d\n",(int)(counter - haystack));
	}

	return 0;
}

char* find (char *haystack, char needle)
{
	int lenght = 0;
	int counter = 0;
	
	lenght = strlen(haystack);

	for(counter = 0; counter < lenght; counter++)
	{
		if(haystack[counter] == needle)
		{
			return &haystack[counter];
			break;	
		}			
	}

	return NULL;	
}