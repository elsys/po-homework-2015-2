#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

#define MAX_INPUT_WORDS 3000
#define HASH_START_VALUE 42
#define END "vsmisal"

struct occurance_t
{
	long word_hash;
	int count;
};

long hash(char *word);
int is_string_equals(char *first, char *second);
int get_index(struct occurance_t *array, int hash, int lenght);

int main()
{
	char word[200];

	struct occurance_t words[MAX_INPUT_WORDS];

	int words_counter = 0;

	while(true)
	{
		scanf("%s",word);

		if(is_string_equals(word,END))
		{
			break;
		}

		long hash_value;
		hash_value = hash(word);
		int index = get_index(words, hash_value, words_counter);
		if(index == -1)
		{
			words[words_counter] = (struct occurance_t){hash_value , 1};
			words_counter++;
		}
		else
		{
			words[index].count++;
		}
	}
	int max_index = words_counter-1, max_count = words[words_counter-1].count;
	for (words_counter-=2;words_counter >= 0; words_counter--)
	{
		if(words[words_counter].count > max_count)
		{
			max_index = words_counter;
			max_count = words[words_counter].count;
		}
	}

	printf("%d %ld", max_count, words[max_index].word_hash);

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

int is_string_equals(char *first, char *second)
{
	int counter = 0;

	while(first[counter] != '\0' && second[counter] != '\0')
	{
		if(first[counter] != second[counter])
		{
			return false;
		}

		counter++;
	}

	if(first[counter] != second[counter])
	{
		return false;
	}

	return true;
}

int get_index(struct occurance_t *array, int hash, int lenght)
{
	int i = 0;
	for(;i < lenght; i++)
	{
		if(array[i].word_hash == hash)
		{
			return i;
		}
	}

	return -1;
}
