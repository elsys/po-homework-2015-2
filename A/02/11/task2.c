#include <stdio.h>
#include <string.h>

char* find(char *haystack, char needle);

int main()
{
	char input[401] = {'\0'}, x, *output;
	long int result;

	fgets(input, 401, stdin);
	x = getchar();

	output = find(input, x);

	result = output - input;

	if(output == NULL)
	{
		printf("-1");
	}
	else
	{
		printf("%ld", result);
	}

	return 0;
}

char* find(char *haystack, char needle)
{
	int i;
	char *output = NULL;

	for(i = 0; haystack[i] != '\0' && i < 400; i++)
	{
		if(haystack[i] == needle)
		{
			output = &haystack[i];
			break;
		}
	}

	return output;
}
