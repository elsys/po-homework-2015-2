#include <stdio.h>
#include <string.h>

long hash( char *word);

int main() {

	char word[200];
	do {
		scanf("%s", word);
	} while( strlen(word) > 200 );
	printf("\n %ld", hash(word));
	return 0;
}

long hash( char *word) {

	int i;
	long hash_sum = 42;
	for( i = 0 ; i <= strlen(word) - 1; i++ ) {
		hash_sum += word[i]*(i+1);
	} 
	return hash_sum;
}
