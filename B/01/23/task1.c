#include <stdio.h>

char text[200];

long hash(char word)
{
    long value=42;
    int len = strlen(text), i;
	for(i = 0;i<len;i++)
	{
		value=value+text[i] * (i+1);
	}
	return value;
}

int main()
{
    int value;
    scanf("%s", text);
    value = hash(text);
    printf("%d",value);
    return 0;
}
