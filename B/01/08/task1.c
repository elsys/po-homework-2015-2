#include <stdio.h>
#include <string.h>

long hash(char *);

int main() {

	char word[200];

	scanf("%99s", word);

	printf("%ld", hash(word));

	return 0;
}

long hash(char *word) {
	long hash = 42;
	int i;

	for(i = 0; i < strlen(word); i++) {
		hash += word[i] * (i + 1);
	}

	return hash;
}