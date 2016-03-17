#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <malloc.h>

char* find(char *haystack, char needle)
{
    char *result;
    int found=0;
    int i=0;
    
    while (i<strlen(haystack))
    {
        if (haystack[i]==needle)
        {
            found=1;
	    result=malloc(i*sizeof(char));
            strncpy(result, haystack, i+1);
            result[i+1]='\0';
            break;
        }
        i++;
    }
 
    if (!found)
    {
        return NULL;
    }
 
    return result;
 
}
 
int main()
{
    char *haystack;
    size_t len=0;
    getline(&haystack, &len, stdin);
 
    char needle;
    scanf("%c", &needle);
 
    char* result=find(haystack, needle);
 
    printf("%d", (int)strlen(result)-1);
 
    return 0;
}
