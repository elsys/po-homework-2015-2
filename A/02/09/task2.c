#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 400

char* find(char*, char);

int main() {
    
    char input[MAX_LENGTH], symbol, *found;
    
    fgets(input, MAX_LENGTH + 1, stdin);
    scanf("%c", &symbol);
    
    found = find(input, symbol); 
    printf("%d", (int)(found ? found - input : -1));
    
    return 0;
}

char* find(char *haystack, char needle) {
    
    int length = strlen(haystack);
    
    for (int i = 0; i < length; i++) {
        if (haystack[i] == needle) {
            return &haystack[i];
        }
    }
    
    return NULL;
}