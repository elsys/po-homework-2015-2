#include <string.h>
#include <stdio.h>

long hash(char *word);

int main(){
	
	char sentence[200];
	
	fgets(sentence, 200, stdin);
	
	printf("%ld\n", hash(sentence));
	
	return 0;
}

long hash(char *word){
	
	long int hash;
	short int replacer;
	
	hash = 42;
	
	for(int i = 0; i < strlen(word) - 1; i ++){
		replacer = word[i];
		hash = hash + (replacer * (i + 1));
	}
	
	return hash;
}
