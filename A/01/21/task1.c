#include <string.h>
#include <stdio.h>
#define max 200

long hash(char *word);

int main(){
	
	char sentence[max];
	
	for(int i = 0; i < max; i++){
		sentence[i] = 0;
	}
	
	fgets(sentence, max, stdin);
	
	printf("%ld", hash(sentence));
	
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
