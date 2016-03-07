#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct occurance_t
{
	int frequency;
	long hash;
};

long hash(char* word);

int main()
{
	int i = 0, k;
	char word[200];
	long int tempHash;
	struct occurance_t words[3000];
	int max;

	scanf("%s", word);
	tempHash = hash(word);

	for(i = 0; i < 3000; i++)
	{
		words[i].hash = 0;
		words[i].frequency = 0;
	}

	for(i=0; i < 3000 && strcmp(word, "vsmisal") != 0; i++)
	{
		if(strlen(word) > 200) return 404;

		for(k = 0; k <= i; k++)
		{
			if(words[k].frequency == 0)
			{
				words[k].hash = tempHash;
				words[k].frequency++;
			}

			else if(words[k].hash == tempHash) words[k].frequency++;
		}
		scanf("%s", word);
		tempHash = hash(word);
	}

	for(k = 0; k < i; k++)
	{
		if(words[k].frequency > words[max].frequency) max = k;
	}

	printf("%d %ld", words[max].frequency, words[max].hash);

	return 0;
}

long hash(char* word)
{
	int i;
	long base = 42;
	
	for(i = 0; i < strlen(word); i++)
	{
		base += word[i]*(i+1);
	}

	return base;
}
