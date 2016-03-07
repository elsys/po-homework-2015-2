#include <stdio.h>
#include <string.h>

struct occurance_t{
    long int hash_value;
    unsigned short int occurance;
};

long hash(char*);

int main(){
    char word[200];
    unsigned short int i, counter;
    struct occurance_t words[3000];
    memset( words, 0, sizeof(words));
    do{
        scanf("%s", word);
        i++;
        for( counter = 0; counter < 3000; counter++ ){
            if(words[counter].hash_value == hash(word)){
                words[counter].occurance++;
                break;
            } else {
                if(words[counter].hash_value == 0){
                    words[counter].hash_value = hash(word);
                    words[counter].occurance = 1;
                    break;
                }   
            }
        }
    }while(strcmp(word, "vsmisal") != 0);
    unsigned int helper = 0;
    for( i = 0 ; words[i].occurance != 0; i++ ){
        if(words[i].occurance > helper)
            helper = i;
    }
    printf("%d %ld", words[helper].occurance, words[helper].hash_value);
    return 0;
}

long hash(char *word){
    long int helper = 42;
    int i = 0;
    for(i = 0; i < strlen(word); i++){
        helper += (word[i] * (i + 1));
    }
    return helper;
}
