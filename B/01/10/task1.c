#include <stdio.h>
#include <string.h>

long hash(char *);

int main()
{
	
	char text[202];

	scanf("%[^\n]s",text);

	printf("%ld", hash(text));

	return 0;
}

long hash(char *word) {
	int hash = 42;

	int position = 1;
	
	int index = 0;

	for (index = 0; index < strlen(word); index++) {

		hash = hash + (word[index]*position);
		position++;
	}
	return hash;
}
