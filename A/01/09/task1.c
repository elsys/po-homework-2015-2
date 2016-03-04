#include <stdio.h>
#include <string.h>

long hash(char*);

int main() {
    
    char word[200];
    fgets(word, 201, stdin);
    
    printf("%ld", hash(word));
    
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