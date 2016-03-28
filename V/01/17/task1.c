#include <stdio.h>
#include <string.h>

long hash( char *word);

int main() {

	char word[200] = {0};
	
	do {
		scanf("%s", word);
	} while( strlen(word) > 200 );
	
	printf("\n %ld", hash(word));

	return 0;
}

long hash( char *word) {

	int i = 0;
	long hashs = 42;
	
	while(i <= strlen(word)){
		hashs += word[i]*(i+1);
		i++;
	}

	return hashs;
}
