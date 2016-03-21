#include <stdio.h>
#include <string.h>

//Писано в Code Blocks за Windows XP на клавиатура с неработещи Num Lock и двата Shift-а. :-)

char *find(char *haystack, char needle);

int main()
{
	char s1[400], s2, *pos;
	short unsigned int rez;
	fgets(s1, sizeof(char)*400, stdin);
	scanf("%c",&s2);
	pos=find(s1, s2);
	if(pos==NULL)
	{
		printf("-1");
		return -1;
	}
	rez=(long int)pos-(long int)s1;
	printf("%d",rez);
	return 0;
}

char *find(char *haystack, char needle)
{
	unsigned short int i=0, l;
	l=strlen(haystack);
	while(i<l)
	{
		if(haystack[i]==needle)
			return haystack+i;
		i++;
	}
	return NULL;
}
