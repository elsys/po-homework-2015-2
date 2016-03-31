#include <stdio.h>
#include <string.h>
#define MAX 401

char* find(char*, char);

int main(){
    char input[MAX], searched;

    fgets(input, MAX, stdin);
    scanf("%c", &searched);

    if(find(input, searched) == NULL)
        printf("-1");

    else
        printf("%d", find(input, searched) - input);

return 0;
}

char* find(char *haystack, char needle){
    char *resultptr;
    int i,length;

    resultptr = NULL;

    length = strlen(haystack);

    for(i = 0; i < length; i++){

        if(haystack[i] == needle){
            resultptr = &haystack[i];
            break;
        }
    }

    return resultptr;
}
