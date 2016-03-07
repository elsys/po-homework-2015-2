#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long hash(char*); 

int main(){
    char word[200];
    scanf("%s", word);
    printf("%ld", hash(word));
    return 0;
}

long hash(char *word){
    long a = 42;
    int i;
    for(i = 0; i < strlen(word); i++){
        a += (word[i] * (i + 1));
    }
    return a;
}
