#include<stdio.h>
#include<string.h>

char *find(char *, char);

int main()
{
char str[400];
char bomb;
int i;

	
	fgets(str, 400, stdin);		
	

scanf("%c", &bomb);	
	if(find(str, bomb) != NULL)
	{
		printf("%c", *find(str, bomb));
	}
	else printf("-1");

return 0;
}

char *find(char *haystack, char needle)
{
char *pali, end;
int i;

	for(i = 0; i < strlen(haystack) - 1; i++)
	{
		if(needle == haystack[i])
		{
			end = i + '0';
			break;
		}
	}
	if(end == 0)
		return NULL;
	else
	{
		pali = &end;
		return pali;
	}
}


