#include <stdio.h>
#include <string.h>

char *find(char *, char);

int main()
{
    char mas[400], y;
    int i, k;
    char *pos;

	fgets(mas,400,stdin);
	y=getchar();
	k=strlen(mas);

	pos=find(mas,y);
	i=(int)(pos-mas);

	if(i==k)
    {
        i=-1;
    }
	printf("%d",i);

	return 0;
}

char *find(char *haystack, char needle)
{
	int i, len;

	len=strlen(haystack);

	for(i=0; i<len; i++)
	{
		if(*haystack==needle)
        {
			break;
		}
		else haystack++;
	}
	return haystack;
}
