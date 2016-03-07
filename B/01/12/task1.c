#include <stdio.h>
#include <string.h>

long hash (char *word);

int main () {
	char word[201];

	scanf ("%s", word);

	printf ("%lu", hash (word) );

	return 0;
}

long hash (char *word) {
	int sum = 42, count;

	for (count = 0; count < strlen (word); count++) sum = sum + (word[count]) * (count + 1);

	return sum;
}

