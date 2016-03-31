#include <stdio.h>
#include <string.h>


long hash(char []);

int main(){
	char word[200] = {0};
	do{
		scanf("%200[^\n]",word);	
	}while(strlen(word) > 200);
	printf("%ld",hash(word) );
}

long hash(char word[]){
	long result = 42;
	for(unsigned int i = 0;i < strlen(word);i++){
		result = result + (word[i] * (i + 1));
	}
	return result;
}