#include <stdio.h>
#include <string.h>

long hash(char *word) {
	long i, sum = 42;
 
	for (i = 0; i < strlen(word); ++i)
		sum += word[i]*(i+1);
 
	return sum;
}

int main() {
	char input[200];

	scanf("%s", input);
	printf("%ld\n", hash(input));

	return 0;
}
