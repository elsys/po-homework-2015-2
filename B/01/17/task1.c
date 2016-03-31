#include <stdio.h>
#include <string.h>

long hash(char * );
int main(){
    char word[200];
	scanf("%[^\n]s",word);

	printf("%ld",hash(word));
    return 0;
}
long hash(char *word){
    int i,p;
    int hash=42;
    for(i=1,p=0;p<strlen(word);i++,p++){
        hash=hash+(word[p]*i);

    }
    return hash;

}
