#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct occurance_t {
   long unsigned hash;
   int times;
   char words[4][200];
} word_counter;
 
struct occurance_t all[3000];
int key = 0;
int max_number_of_word_till_death = 4;
 

int compare_function(const void *v1, const void *v2){
     word_counter *p1 = (word_counter *) v1;
    word_counter *p2 = (word_counter *) v2;
    if (p1->hash < p2->hash)
        return -1;
    else if (p1->hash > p2->hash)
        return +1;
    else
        return 0;
}
 

void sort_all(){
    qsort((void*)all, key, sizeof(all[0]), compare_function);
}
 
void print_all(){
    int i = 0;
    for (i = 0; i < key; i++){
        printf("[%ld] => ",all[i].hash);
        int k = 0;
        for (k = 0; k < all[i].times; k++){
            printf("%s ", all[i].words[k]);
        }
        printf("\n");
    }
}
 
int should_stop(){
    struct occurance_t biggest = all[0];
    int i = 0;
    for (i = 1; i < key; i++){
        if (all[i].times > biggest.times){
            biggest = all[i];
        }
    }
    if (biggest.times == max_number_of_word_till_death){
        return 1;
    } else {
        return 0;
    }
}
 
long my_hashing_function(char *word){
    long hash = 42;
    int length = strlen(word);
    int i;
    for(i = 0 ; i < length; ++i){
        hash += (int)word[i]*(i+1);
    }
    return hash;
}

void add_to_hash(char* word){
 
    int k;
    long hash = my_hashing_function(word);
    for (k = 0; k < key; k++){
        if (all[k].hash == hash){
            memcpy(all[k].words[all[k].times],word, 200);            
            all[k].times += 1;
            break;
        }
    }
    if (k == key){
        all[k].hash = hash;
        memcpy(all[k].words[0],word, 200);            
        all[k].times = 1;
        key += 1;
    }
}
 
int main(){
    while (1) {
        char* word;
        word = malloc(200);
        scanf("%s", word);
        add_to_hash(word);  
        free(word);      
        if (should_stop()){
            break;
        }
    }
 
    sort_all();
    print_all();    
    return 0;
}