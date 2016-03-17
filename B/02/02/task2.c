#include <stdio.h>
#include <string.h>
char* find(char *haystack, char needle);

int main()
{
	char haystack[400], needle;
	int i = 0, result = 0 , j;
	fgets(haystack, 400, stdin);
	scanf("%c", &needle);
	i = strlen(haystack);
	for (j = 0; j<=i; j++)
	{
		if(find(&haystack[j], needle))
		{
			result = j;
			break;
		}	
	}	
	

		
	printf ("\n %d", result);
	return 0;
}

char* find(char *haystack, char needle)
{
	
	if(needle == *haystack)
		return (void *)1;
	else return 0;
}
