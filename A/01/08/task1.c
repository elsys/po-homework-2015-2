#include <stdio.h>
#include <string.h>

long hash(char* word);

int main(){
	char word[201];

	scanf("%s", word);
	printf("%li", hash(word));

	return 0;
}

long hash(char* word){
	int i;
	long hashed = 42;
	
	for(i = 0; i < strlen(word); i++){
		hashed += word[i]*(i+1);
	}

	return hashed;
}