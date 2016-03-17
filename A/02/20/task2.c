#include <stdio.h>
#include <string.h>
#define MAX 400

char* find(char*, char);

int main()
{
	char haystack[MAX];
	char needle; 
	int out;

	fgets(haystack, 400, stdin);
	scanf("%c", &needle);

	find(haystack, needle);

	if(find(haystack, needle)!= NULL)
	{
		out = find(haystack, needle) - haystack;
		printf("%d", out);
	}
	else
	{
		printf("-1");
	}
	return 0;

}

char* find(char *haystack, char needle)
{
	char *out;

	for(int i=0; i< strlen(haystack); i++)
	{
		if(haystack[i] == needle)
		{
			out = &haystack[i];
			return out;
		}
	}

	return NULL;
}