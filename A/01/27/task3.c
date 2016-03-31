#include <stdio.h>
#include <string.h>

typedef struct{
	int count;
	int hash;
	char words[5][200];
} occurance_t;

int check(char*, occurance_t*, int);
int fill(char*, occurance_t*, int);
long hash(char*);
int sort(occurance_t*, int);

int main()
{
	occurance_t data[3000];
	char word[200];
	int i, k;
	for(i = 0; i < 3000; i++)
	{
		scanf("%s", word);
		if(check(word, data, i)) break;
	}
	k = sort(data, i);
	for(int j = 0; j < i; j++)
	{
		if(data[j].count >= 2)
		{
			printf("%d", data[j].hash);
			for(int h = 0; h < data[j].count; h++)
				printf(" %s", data[j].words[h]);
			if(j != k) printf("\n");
		}
	}
	return 0;
}

int check(char *word, occurance_t* data, int length)
{
	int j;
	for(j = 0; j < length; j++)
	{
		if(hash(word) == data[j].hash)
		{
			if(fill(word, data, j)) return 1;
			else return 0;
		}
	}
	data[j].hash = hash(word);
	data[j].count = 1;
	for(int i = 0; i < strlen(word); i++)
	{
		data[j].words[0][i] = word[i];
	}
	return 0;
}

int fill(char* word, occurance_t* data, int j)
{
	int k, i;
	for(i = 0; i < data[j].count; i++)
	{
		k = 0;
		for(int h = 0; h < strlen(word); h++)
		{
			if(data[j].words[i][h] != word[h])
			{
				k = 1;
				break;
			}
		}
		if(k == 0) return 0;
	}
	data[j].count++;
	for(int h = 0; h < strlen(word); h++)
	{
		data[j].words[i][h] = word[h];
	}
	if(data[j].count == 4) return 1;
	else return 0;
}

int sort(occurance_t* data, int length)
{
	occurance_t temp;
	int max = 0, position_max;
	for(int i = 0; i < length; i++)
	{
		for(int j = i; j < length; j++)
		{
			if(data[i].hash > data[j].hash)
			{
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
			
		}
	}
	for(int i = 0; i < length; i++)
	{
		if( (data[i].count >= 2) && (data[i].hash > max) )
		{
			max = data[i].hash;
			position_max = i;
		}
	}
	return position_max;
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
