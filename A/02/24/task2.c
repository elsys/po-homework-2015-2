#include <stdio.h>
#include <string.h>
#define MAXARRSIZE 400

char *find(char *,char );

int main()
{
	int result;
	char input_array[MAXARRSIZE], searched;
	
	fgets(input_array, MAXARRSIZE + 1, stdin);
	scanf("%c",&searched);

	if(find(input_array, searched) != NULL)
	{
		result = find(input_array, searched) - input_array;
		printf("%d",result);
	}
	
	else 
		printf("-1");

	return 0;
}

char *find(char *haystack,char needle)
{
	int i;
	char *ptr = NULL;
	for(i = 0;i < strlen(haystack); i++)
	{
		if(needle == haystack[i])
		{
			ptr = &haystack[i];
			break;
		}
	}

	return ptr;
}
