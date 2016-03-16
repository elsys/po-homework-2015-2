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
    unsigned short int i, k, b = 0, size = 1;
    struct occurance_t broi[3000];
    memset(broi, 0, sizeof(broi));
    memset(word, 0, sizeof(word));
    do{
        scanf("%s", word);
        for(k = 0; k < size; k++){
			if(broi[k].hash_sum == hash(word)){
				broi[k].a++;
				break;
			}
			else
				continue;
		}
		if(k == size){
			broi[k].hash_sum = hash(word);
			broi[k].a = 1;
			size++;
		}
    }while(strcmp(word, "vsmisal") != 0);
    for(i = 0; i < size; i++)
        if(broi[i].a > b)
            b = i;
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
