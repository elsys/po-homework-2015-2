#include <stdio.h>
#include <string.h>

long hash(char*);

int main(){
    char word[201];

    scanf("%s", word);

    printf("%ld",hash(word));

return 0;
}

long hash(char *word){
    int i, length, sum= 42;

    length= strlen(word);

    for(i = 0; i < length; i++){

         sum += (word[i]*(i+1));
    }

 return sum;
}
