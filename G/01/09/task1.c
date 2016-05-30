#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int longhash(char* word){
	int result = 42;
	int i;
	for(i = 0; i <= strlen(word) - 1; i++){
		printf("word: %c\n", word[i]);
		result += word[i] * (i+1);
	}

	return result;
}

int main(){

	char *str = malloc(200 * sizeof(char));

	int i;
	printf("Enter a string: ");
	fgets(str, 200, stdin);

	while(strlen(str) >= 200){
		printf("Enter a string: ");
		fgets(str, 200, stdin);
	}

	i = strlen(str)-1;
	if( str[ i ] == '\n') 
	  str[i] = '\0';

	printf("hash = %d", longhash(str));

	return 0;
}
