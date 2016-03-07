#include <stdio.h>
#include <string.h>
#define HASH_START_VALUE 42

long hash(char *);

int main()
{
	char input_word[200];
	long word_hash;

	scanf("%s",input_word);

	word_hash = hash(input_word);

	printf("%ld\n", word_hash);

	return 0;
}

long hash(char *word)
{
	long word_hash = HASH_START_VALUE;

	int word_lenght = strlen(word);

	int i = 0;
	for(;i < word_lenght; i++)
	{
		word_hash += word[i] * (i+1);
	}

	return word_hash;
}
