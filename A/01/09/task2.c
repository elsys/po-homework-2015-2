#include <stdio.h>
#include <string.h>
#define MAX_WORDS 3000
#define STOPPER "vsmisal"

struct occurance_t {
    long hash;
    unsigned int count;
};

long hash(char*);
int index_of(char*, struct occurance_t*, int);

int main() {

    int i = 0, temp;
    char word[200];
    
    struct occurance_t most_common = { 0, 0 };
    struct occurance_t words[MAX_WORDS] = { { 0, 0 } };
    
    while (1) {
        
        scanf("%s", word);
        
        if (strcmp(word, STOPPER) != 0 && i < MAX_WORDS) {
            
            if ((temp = index_of(word, words, i)) != -1) {
                words[temp].count++;
            } else {
                words[i].hash = hash(word);
                words[i].count = 1;
                i++;
            }
            
        } else {
            break;
        }
    }

    
    temp = 0;
    for (int j = 0; j < i; j++) {
        
        if (words[j].count > temp) {
            temp = words[j].count;
            most_common.hash = words[j].hash;
            most_common.count = words[j].count;
        }
    }
    
    printf("%d %ld", most_common.count, most_common.hash);

    return 0;
}

long hash(char *word) {
    
    long result = 42;
    int length = strlen(word);
    
    for (int i = 0; i < length; i++) {
        result += word[i] * (i + 1);
    }
    
    return result;
}

int index_of(char *word, struct occurance_t *words, int length) {
    
    for (int i = 0; i < length; i++) {
        if (hash(word) == words[i].hash) {
            return i;
        }
    }
    
    return -1;
}