#include<stdio.h>
#include<string.h>
long hash(char *word){
    long hash = 42;
    int length = strlen(word);
    int i;
    for(i = 0 ; i < length; ++i){
        hash += (int)word[i]*(i+1);
    }
    return hash;
}
int main(){
    char word[200];
    scanf("%s", &word);
    printf("%ld", hash(word));
    return 0;
}
