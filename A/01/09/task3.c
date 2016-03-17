#include <stdio.h>
#include <string.h>
#define MAX_COLLISIONS 4
#define MAX_WORDS 3000

struct occurance_t {
    long hash;
    unsigned int count;
    char versions[MAX_COLLISIONS][200];
    int collisions;
};

long hash(char*);
int index_of(char*, struct occurance_t*, int);
int put_version(char*, struct occurance_t*, int);
void sort(struct occurance_t*, int);
void print_words(struct occurance_t*, int);

int main() {

    int i = 0, temp;
    char word[200];
    
    struct occurance_t words[MAX_WORDS] = { { 0, 0 } };
    
    while (1) {
        
        scanf("%s", word);
            
        if ((temp = index_of(word, words, i)) != -1) {
            words[temp].count++;
            if (!put_version(word, words, temp)) {
                break;
            }
        } else {
            words[i].hash = hash(word);
            words[i].count = 1;
            put_version(word, words, i);
            i++;
        }
    }
    
    sort(words, i - 1);
    print_words(words, i);
    
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

int put_version(char *word, struct occurance_t *words, int index) {
    
    int i;
    
    for (i = 0; i < MAX_COLLISIONS; i++) {
        if (strcmp(word, words[index].versions[i]) == 0) {
            return 1;
        }
    }
    
    for (i = 0; i < MAX_COLLISIONS; i++) {

        if (strlen(words[index].versions[i]) <= 1) {
            
            strcpy(words[index].versions[i], word);
            words[index].collisions++;
            
            if (i == MAX_COLLISIONS - 1) {
                return 0;
            }
            
            return 1;
        }
    }
    
    return 0;
    
}

void sort(struct occurance_t *words, int length) {
    
    struct occurance_t temp;
    int sorted = 0, j = 0;
    
    while (!sorted) {
        sorted = 1;
        j++;
        for (int i = 0; i < length; i++) {
            if (words[i].hash > words[i + 1].hash) {
                temp = words[i];
                words[i] = words[i + 1];
                words[i + 1] = temp;
                sorted = 0;
            }
        }
    }
}

void print_words(struct occurance_t *words, int length) {
    
    for (int i = 0; i < length; i++) {
        if (words[i].collisions > 1) {
            printf("%ld ", words[i].hash);
            for (int j = 0; j < MAX_COLLISIONS; j++) {
                printf("%s ", words[i].versions[j]);
            }
            printf("\n");
        }
    }
}