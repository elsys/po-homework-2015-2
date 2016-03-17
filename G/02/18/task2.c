#include <stdio.h>
#include <string.h>

char* find(char *, char);
int main()
{
	char *ptr = 0;
	char haystack[400];
	char needle;
	
	fgets(haystack, 400, stdin);
	
	scanf("%c", &needle);
	
	ptr = find(haystack, needle);
	if(ptr == NULL)
		printf("-1 \n");
	else
		printf("%d \n", ptr - haystack);
	return 0;
}

char* find(char *haystack, char needle)
{
	int i, l;
	
	l = strlen(haystack);
	
	for(i = 0; i < l; i++)
	{
		if(needle == haystack[i])
			return &haystack[i];
	
	}
	return NULL;
}
