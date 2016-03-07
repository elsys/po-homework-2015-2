#include <stdio.h>
#include <string.h>

long hash(char* word);

int main() {
    char sentence[200];
    scanf("%s", sentence);
    int hash_n = hash(sentence);
    printf("%ld", hash_n);
    return 0;
}


long hash(char* word) {
    long hesh = (long)42, i;
    for(i = 0; i < strlen(word); i++) {
        hesh += (long)(word[i]*(i+1));
    }

    return hesh;
}
