#include <stdio.h>
#include <string.h>

long hesh(char *);

int main()
{
	char arr[200];
	scanf("%s", arr);
	printf("%ld", hesh(arr));
    return 0;

}

long hesh(char *arr)
{

    int c;
    long hesh = 42;

	for(c = 0; c < strlen(arr); c++)
	{
		hesh = hesh + arr[c]*(c+1);
	}

    return hesh;
}
