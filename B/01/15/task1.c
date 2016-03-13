#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long hash(char *word);
int main(){

char word[200];
scanf("%s",word);
printf("%ld",hash(word));

return 0;

}

long hash(char *word){


int counter = 0 ,length , hash = 42;
length = strlen(word);

for(;counter < length ; counter++){
    hash = hash + word[counter] * (counter+1);
}
return hash;
}
