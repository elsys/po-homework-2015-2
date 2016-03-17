#include <stdio.h>
#include <string.h>
#include <malloc.h>


char* find(char *haystack, char needle)
{
    long index;

    const char *ptr = strchr(haystack,needle);
    if(ptr)
    {
        index= ptr-haystack;
        return (void *)index;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    char haystack[401];
    fgets(haystack, 401, stdin);

    char needle;
    scanf("%c", &needle);

    char* index = find(haystack, needle);

    printf("%d",(int)(index));

    return 0;
}
