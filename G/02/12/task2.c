#include <stdio.h>
#include <string.h>

char* find(char *haystack, char needle);

int main(){

    char sentence[400];
    char word;
    int position;

    fgets(sentence, 400, stdin);
    scanf("%c", &word);

    position = find(sentence, word) - sentence;

    if(find(sentence, word)){

        printf("%d", position);

    }else{

        printf("%d", -1);

    }

    return 0;
}

char* find(char *haystack, char needle){

    int count;

    for(count = 0; count < strlen(haystack); count++){

        if(haystack[count] == needle){

            return &haystack[count];

        }

    }

    return NULL;

}
