#include <stdio.h>
#include <string.h>


long hash(char []);

int main(){
	char word[200];
	scanf("%s",word);
	printf("%ld",hash(word));
	return 0;
}

long hash(char word[]){
	long result = 42;
	for(unsigned int i = 0;i < strlen(word);i++){
		result = result + (word[i] * (i + 1));
	}
	return result;
}