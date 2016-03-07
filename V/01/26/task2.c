#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct occurance_t{
    long int hash_sum;
    unsigned short int a;
};

long hash(char*);

int main(){
    char word[200];
    unsigned short int i, k, b = 0;
    struct occurance_t broi[3000];
    memset(broi, 0, sizeof(broi));
    do{
        scanf("%s", word);
        i++;
        for(k = 0; k < 3000; k++){
            if(broi[k].hash_sum == hash(word)){
                broi[k].a++;
                break;
            } else if(broi[k].hash_sum == 0){
                broi[k].hash_sum = hash(word);
                broi[k].a = 1;
                break;
            }
        }
    }while(strcmp(word, "vsmisal") != 0);
    i = 0;
    while(broi[i].a != 0){
        if(broi[i].a > b)
            b = i;
        i++;
    }
    printf("%d %ld", broi[b].a, broi[b].hash_sum);
    return 0;
}

long hash(char *word){
    long int a = 42;
    int i;
    for(i = 0; i < strlen(word); i++){
        a += (word[i] * (i + 1));
    }
    return a;
}
