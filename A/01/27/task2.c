#include <stdio.h>
#include <string.h>

typedef struct{
	int count;
	int hash;
} occurance_t;

typedef struct{
	char word[200];
} sentence_t;

int input(sentence_t*);
int not_end(sentence_t*, int);
void arrange_words_info(sentence_t*, occurance_t*, int);
long hash(sentence_t*, int);
int check_count(occurance_t*, int);

int main()
{
	int count_words, c;
	sentence_t sentence[3001]; 
	occurance_t words_info[3001];
	count_words = input(sentence);
	arrange_words_info(sentence, words_info, count_words);
	c = check_count(words_info, count_words);
	printf("%d %d", words_info[c].count, words_info[c].hash);
	return 0;
}
int input(sentence_t* sentence)
{
	int i = 0;
	do{
		fgets(sentence[i].word, 200, stdin);
		i++;
	}while(not_end(sentence, i-1));
	return i;
}
int not_end(sentence_t* sentence, int i)
{
	int check = 0, j;
	char end[7] = "vsmisal";
	for(j = 0; j < strlen(sentence[i].word); j++)
	{
		if(sentence[i].word[j] == end[j]) check++;
	}
	if(check == 7) return 0;
	else return 1;
}
void arrange_words_info(sentence_t* sentence, occurance_t* words_info, int count_words)
{
	int p = 0;
	for(int i = 0; i < count_words; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(hash(sentence, i) == hash(sentence, j))
			{
				words_info[i].hash = 0;
				words_info[i].count = 0;
				words_info[j].count++;
				p = 1;
			}
			else if(p == 0 && j + 1 == i)
			{
				words_info[i].hash = hash(sentence, i);
				words_info[i].count = 1;
			}
		}
	}
}
long hash(sentence_t *sentence, int i)
{
	int value = 42;
	for(int j = 0; j < strlen(sentence[i].word); j++)
	{
		value = value + sentence[i].word[j]*(j+1);
	}
	return value;
}
int check_count(occurance_t* words_info, int count_words)
{
	int max = 0, c;
	for(int i = 0; i < count_words; i++)
	{
		if(words_info[i].count > max)
		{
			max = words_info[i].count;
			c = i;
		}
	}
	return c;
}
