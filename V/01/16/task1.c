#include <stdio.h>
#include <string.h>

long hash (char *word);

int main () {
	char word [200] = {0};
	scanf("%s", word);

	printf("%ld", hash(word));	

	return 0;
}

long hash (char *word) {
	long hash = 42;
	int i = 0;
	while (i < strlen(word)) {
		hash = hash + word[i] * (i + 1);
		i++;
	}
	return hash;
}
