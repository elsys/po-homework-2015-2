#include<stdio.h>
#include<string.h>
#define MAX_WORDS 3000
#define MAX_WORD_LENGTH 200
typedef struct{
                int count;
                long hash;
        } occurance_t;
occurance_t words[MAX_WORDS];
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
    char word[MAX_WORD_LENGTH];
    int foundVsmisal = 0;
    int word_count = 0;
    int j = 0;
    int match = 0;
    int maximum = 1;
    int location = 0;
    long hashed;
    while (fscanf(stdin, "%s", word)){
            match = 0;
      char *dot = strstr(word, "vsmisal");
      if (dot != NULL){
        foundVsmisal = 1;
        *dot = 0;
      }
      if (strlen(word) > 0){
        hashed = hash(word);
        for(j = 0; j < word_count; ++j){
            if(words[j].hash == hashed) {
             match = j;
            }
        }
        if(match){
            words[match].count+=1;
        }else{
            words[word_count].hash = hashed;
            words[word_count].count = 1;
        }
      }
        word_count++;
        if(foundVsmisal) break;
    }
    for(j = 0; j < word_count-1; ++j){
            //printf("words[%d]\ncount = %d\nhash=%ld\n\n",j,words[j].count,words[j].hash);
        if(words[j].count > maximum){
            maximum = words[j].count;
            location = j;
        }
    }
    printf("%d %ld", words[location].count, words[location].hash);
    return 0;
}
