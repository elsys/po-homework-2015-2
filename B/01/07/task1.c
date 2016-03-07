#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long hash(char *word);
int main (){
    int hasherino;
    char word[200];
    fgets(word, 50, stdin);
    hasherino = hash(word);
    printf("%d", hasherino);
    return 0;
}
long hash(char *word){
    int i,end=42;
        for(i=0;i<strlen(word)-1;i++){
        end = end + word[i]*(i+1);
    }
    return end;
}
