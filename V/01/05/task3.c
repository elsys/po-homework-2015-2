#include <stdio.h>
#include <string.h>

long hash(char *);

struct occurance_t{
	long hash;
	char word[4][200];
	int count;
};

int main()
{
	int i = 0, a = 0, b = 0, tent = 0;
	char word[200];
	long tent_hash = 0;
	struct occurance_t words[3000], tent_swap;
	while(i != 3000)
	{
		b = 0;
		while(b != 4)
		{
			words[i].word[b][0] = '0';
			b++;
		}
		words[i].hash = 0;
		words[i].count = 0;
		i++;
	}
	i = 0;
	while(1)
	{
		tent = 0;
		a = 0;
		scanf("%s", word);
		tent_hash = hash(word);
		while(a != i)
		{
			if (words[a].hash == tent_hash)
			{
				b = 0;
				while(b < words[a].count)
				{
					if ((strcmp(word, words[a].word[b]) == 0))
					{
						tent = 1;
						break;
					}
					b++;
				}
				if(tent == 0)
				{
					b = words[a].count;
					strcpy(words[a].word[b], word);
					words[a].count++;
					tent = 1;
				}
				break;
			}
			a++;
		}
		if (tent == 0)
		{
			strcpy(words[i].word[0], word);
			words[i].hash = tent_hash;
			words[i].count++;
			i++;
		}
		if(b == 3)
		{
			break;
		}
	}
	while(1)
	{
		tent = 0;
		for(a = 0; a < i; a++)
		{
			if(words[a].hash > words[a + 1].hash)
			{
				tent_swap = words[a];
				words[a] = words[a + 1];
				words[a + 1] = tent_swap;
				tent = 1;
			}
		}
		if(tent == 0)
		{
			break;
		}
	}
	a = 0;
	while (a <= i)
	{
		switch (words[a].count)
		{
			case 2:
				printf("%ld %s %s\n", words[a].hash, words[a].word[0], words[a].word[1]);
				break;
			case 3:
				printf("%ld %s %s %s\n", words[a].hash, words[a].word[0], words[a].word[1], words[a].word[2]);
				break;
			case 4:
				printf("%ld %s %s %s %s\n", words[a].hash, words[a].word[0], words[a].word[1], words[a].word[2], words[a].word[3]);
				break;
			default:
				break;
		}
		a++;
	}
	return 0;
}


long hash(char *word)
{
	int begin = 42;
	int i = 1,l = strlen(word);
	while(i <= l)
	{	
		begin += word[i - 1] * i;
		i++;
	}
	return begin;
}
