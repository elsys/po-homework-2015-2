#include <stdio.h>
#include <string.h>

typedef struct{
	int count;
	int hash;
} occurance_t;

int end(char*);
long hash(char*);
void check_and_fill(char*, occurance_t*, int);
int find_max_count(occurance_t*, int);

int main()
{
	occurance_t data[2000];
	char word[200];
	int max_count, i;
	for(i = 0; i < 2000; i++)
	{
		scanf("%s", word);
		if(end(word)) break;
		check_and_fill(word, data, i);
	}
	max_count = find_max_count(data, i);
	printf("%d %d", data[max_count].count, data[max_count].hash);
	return 0;
}

int end(char* word)
{
	char example[8] = "vsmisal";
	for(int i = 0; i < 7; i++)
	{
		if(word[i] != example[i]) return 0;
	}
	return 1;
}

long hash(char *word)
{
	int value = 42;
	if(strlen(word) > 1)
	{
		for(int i = 0; i < strlen(word); i++)
		{
			value = value + word[i]*(i+1);
		}
	}
	return value;
}

void check_and_fill(char* word, occurance_t* data, int length)
{
	int k = 0;
	for(int j = 0; j < length; j++)
	{
		if(hash(word) == data[j].hash)
		{
			data[j].count++;
			data[length].count = 0;
			k = 1;
		}
	}
	if(k == 0)
	{
		data[length].count = 1;
		data[length].hash = hash(word);
	}
}
int find_max_count(occurance_t* data, int length)
{
	int max = 0, element;
	for(int i = 0; i < length; i++)
	{
		if(data[i].count > max)
		{
			max = data[i].count;
			element = i;
		}
	}
	return element;
}
