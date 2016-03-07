#include <stdio.h>
#include <stdlib.h>
#include "task1.h"

extern long hash(char*);

int main() {
	char* word = (char*)malloc(200*sizeof(char));
	scanf("%s", word);
	printf("%ld", hash(word));
	free(word);
	return 0;
}