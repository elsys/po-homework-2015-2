#include <stdio.h>
#include <string.h>
#include <malloc.h>

char* find(char *haystack, char needle)
{
    char *result;
    int found = 0;
    int i ;
    for (i = 0; i < strlen(haystack); i++)
    {
        if (haystack[i] == needle)
        {
            found = 1;
            result = malloc(i * sizeof(char));
            strncpy(result, haystack, i+1);
            result[i+1] = '\0';
            break;
        }
    }

    if (!found)
    {
        return NULL;
    }

    return result;

}

int main()
{
    char haystack[400];
    char needle;
    fgets(haystack, 400, stdin);

    scanf("%c", &needle);

    char* result = find(haystack, needle);

    printf("%d", (int)strlen(result) - 1);

    return 0;
}
