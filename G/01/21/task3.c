#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

#define MAX_INPUT_WORDS 3000
#define HASH_START_VALUE 42

struct occurance_t
{
	long word_hash;
	int count;
	char words[4][200];
};

long hash(char *word);
int is_string_equals(char *first, char *second);
int get_index(struct occurance_t *array, int hash, int lenght);
void sort_by_hash(struct occurance_t *array, int lenght);
void print_occurance_t(struct occurance_t _struct);

int main()
{
	char word[200];

	struct occurance_t words[MAX_INPUT_WORDS];

	int words_counter = 0;

	int max_count = 0;

	while(true)
	{
		scanf("%s",word);

		long hash_value;
		hash_value = hash(word);
		int index = get_index(words, hash_value, words_counter);

		if(index == -1)
		{
			index = words_counter;
			words[index].word_hash = hash_value;
			words[index].count = 1;
			strcpy(words[index].words[0], word);
			words_counter++;
		}
		else
		{
			int i = 0,has_already_exist = false;
			for (; i < words[index].count; ++i)
			{
				if(is_string_equals(words[index].words[i],word))
				{
					has_already_exist = true;
					break;
				}
			}

			if(!has_already_exist)
			{
				strcpy(words[index].words[words[index].count],word);
				words[index].count++;
			}
		}

		if(max_count < words[index].count)
		{
			max_count = words[index].count;
		}

		if(max_count >= 4)
		{
			break;
		}
	}

	sort_by_hash(words,words_counter);

	int i = 0;
	for (; i < words_counter; i++)
	{
		print_occurance_t(words[i]);
	}

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

void sort_by_hash(struct occurance_t *array, int lenght)
{
	int a,b;
	for(a=0; a < lenght; ++a)
	{
        for(b=lenght-1; b>a; --b)
    	{   
            if(array[b-1].word_hash > array[b].word_hash)
            {
                    struct occurance_t t = array[b-1];
                    array[b-1] = array[b];
                    array[b] = t;
            }
        }
    }
}

void print_occurance_t(struct occurance_t _struct)
{
	printf("%ld", _struct.word_hash);
	int i = 0; 
	for(;i < _struct.count; i++)
	{
		printf(" %s", _struct.words[i]);
	}
	printf("\n");
}
