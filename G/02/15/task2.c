#include <stdio.h>
#include <string.h>

char* find(char*, char);

int main() {
    
    char sentence[400], word, *found;
    
    fgets(sentence, 400 + 1, stdin);
    scanf("%c", &word);
    
    found = find(sentence, word); 
    
    if(found){
    
    	printf("%d\n", found - sentence);
    
    }else{
    
    	printf("-1\n");
    
    }
    
    return 0;
}

char* find(char *haystack, char needle) {
    
    int i;
    
    for (i = 0; i < strlen(haystack); i++) {
    
        if (haystack[i] == needle) {
        
            return haystack+i;
            
        }
        
    }
    
    return NULL;
}
