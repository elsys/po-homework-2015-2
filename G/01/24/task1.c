#include <stdio.h>
#include <string.h>

long hash(char *word);

int main(){

    char word[200];
    scanf("%s", word);
    printf("%ld", hash(word));

    return 0;

}

long hash(char *word){

    long result = 42;
    int counter = 0;

    while(counter++ < strlen(word)){

        result += word[counter-1]*(counter);

    }

    return result;

}
