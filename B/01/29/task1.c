#include<stdio.h>
#include<string.h>

long hash(char *word);

	int main(){
		char word[200];
		
		scanf("%s", word);
		
		printf("%ld",hash(word));
  return 0;
	}
	
	long hash(char *word){
		long starter = 42;
		int index = 0, position = 1;
		for (;index < strlen(word) -1  ; index++, position++)starter = starter + (word[index] * position);
		return starter;
	}
