#include <stdio.h>
#include <string.h>

char * find(char *haystack, char needle);

int main()
{
	char needle;
	char haystack[400];
	fgets(haystack,400,stdin);
	scanf("%c",&needle);
	printf("%ld", find(haystack,needle) - haystack);
	return 0;
}

char *find(char *haystack, char needle)
{
	int counter = 0;
	while(counter < strlen(haystack))
	{
		if(needle == haystack[counter])
		{
			return (haystack + counter);
		}
		counter++;
	}
	return NULL;
}