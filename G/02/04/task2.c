#include<stdio.h>
#include<string.h>
char* find(char *haystack, char needle)
{
	int count=0;
	int lenght=0;
	lenght = strlen(haystack);
for(;count < lenght;count++)
{
	if(haystack[count] == needle)
	{
	return &haystack[count];
	}

}
return NULL;
}

int main()
{
	char haystack[400];
	char needle;
	char  *helper ;


    scanf("%[^\n]s",haystack);
    getchar();
    scanf("%c",&needle);

	helper = find(haystack,needle);
	if(helper == NULL)printf("-1");
	else{
	printf("%d\n",(int)(helper-haystack));
	}

return 0;
}
