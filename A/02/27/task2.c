#include <stdio.h>
#include <string.h>

char* find(char*, char);

int main()
{
	char string[400], key;
	int i;
	fgets(string, 400, stdin);
	scanf("%c", &key);
	if(find(string, key) != NULL)
	{
		i = find(string, key) - string;
		printf("%d", i);
	}
	else printf("-1");
	return 0;
}

char* find(char *haystack, char needle)
{
	for(int i = 0; i < strlen(haystack); i++)
	{
		if(needle == haystack[i]) return &haystack[i];
	}
	return NULL;
}
