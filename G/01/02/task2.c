
#include<stdio.h>
#include<string.h>
#define max_words 3000
#define max_word_length 200
typedef struct{
                long hash;
                int count;
        } occurance_t;
occurance_t words[max_words];
long hash(char *word){
    long hash = 42;
    int length = strlen(word);
    i=0;
//WHile le<3000
do
{
 
hash_of_word +=word[i]*(i+1);
++i;
 
}while(i < length);
    }
    return hash;
}
int main(){
    char word[max_word_length];
    int foundVsmisul = 0;
    int word_count = 0;
    int j = 0;
    int maximum = 1;
    int match = 0;
    int location = 0;
    long hashed;
    while (scanf(stdin, "%s", word)){
            match = 0;
      char *dot = strstr(word, "Vsmisul");
      if (dot != NULL){
        foundVsmisul = 1;
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
        ++word_count;
        if(foundVsmisul) break;
    }
         for(j = 0; j < word_count-1; j++){
      if(words[j].count > maximum){
            maximum = words[j].count;
           location = j;
        }
    }
    printf("%d %ld", words[location].count, words[location].hash);
    return 0;
}
