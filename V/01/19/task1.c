#include <stdio.h>
#include <string.h>
#define start 42

long hash(char *word) {
        long num = start;
        for(int count = 0; count < strlen(word); count++) {
            num += word[count]*(count+1);
        }
        return num;
}

int main() {
    char word[200];
    scanf("%s", word);
    long sum = hash(word);
    printf("%ld", sum);
    return 0;
}
