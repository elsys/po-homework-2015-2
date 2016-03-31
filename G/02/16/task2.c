#include <stdio.h>
#include <string.h>

char* find(char *haystack, char needle);

int main(){


    char haystack[400];
    char needle;
    char *pointer;

    scanf("%[^\n]s",haystack);
    scanf(" %c",&needle);

    pointer = find(haystack, needle);


    if(pointer == NULL){
        printf("-1");

    }else{

        printf("%d",(int)(pointer - haystack));

    }

    return 0;
}

char* find(char *haystack, char needle)
{

    int i , length;

    char *answer = NULL;

    length = strlen(haystack);

    for(i = 0; i < length; i++){

        if(haystack[i] == needle){

            answer = (haystack + i);
            break;

        }

    }
    return answer;

}
