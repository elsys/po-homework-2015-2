#include <stdio.h>
#include <string.h>

#define MAX_LINE_SIZE 401

char* find(char *haystack, char needle);

int main()
{
	char line[MAX_LINE_SIZE];
	char needle;
	char *finded;

	scanf("%[^\n]s",line);
	scanf(" %c", &needle);

	finded = find(line, needle);

	int position = finded == NULL ? -1 : (int)(finded - line);

	if(finded == NULL)
	{
		printf("-1");
	}
	else
	{

		printf("%d", position);
	}

	return 0;
}

char* find(char *haystack, char needle)
{
	int i;
	for (i = 0; i < strlen(haystack); ++i)
	{
		if(haystack[i] == needle)
		{
			return &haystack[i];
		}
	}

	return NULL;
}
