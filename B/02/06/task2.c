#include<stdio.h>
#include<string.h>

char* find(char *haystack, char needle);

int main()
{
	char haystack[400], needle; 
	scanf("%[^\n]s", haystack);
	scanf("\n %c", &needle);
	if(*find(haystack, needle))
		printf("%c", haystack[0]);
	else printf("-1");		
	return 0;
}

char* find(char *haystack, char needle)
{
	int i;
	int l = strlen(haystack);
	for(i=0; i< l; i++)
	{
		if( haystack[i] == needle)
		{
			*haystack = 48 + i;
			return haystack;
		 	break;
		}
	}	
	return NULL;
}