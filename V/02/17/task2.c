#include <stdio.h>
#include <string.h>

char* find(char *haystack, char needle);

int main(){
    char haystack[400], needle, *pointer;
    
    scanf("%[^\n]s", haystack);
    scanf(" %c", &needle);
    
    pointer = find(haystack, needle);
    if(pointer == NULL){
        printf("-1");
    }
    else{
        printf("%d",(int)(pointer - haystack));
    }

    return 0;
}

char* find(char *haystack, char needle)
{
    int l , i;
    char *a = NULL;
    
    l = strlen(haystack);
    for(i = 0; i < l; i++){
        if(haystack[i] == needle){
            a = (haystack + i);
            break;
        }
    }
    return a;
}
