#include <stdio.h>
#include <string.h>

typedef struct{
	char count[5][200];
} occurance_t;

int fix_count(occurance_t*, int);
long hash(int);
char words[3000][200];

int main()
{
	int i = 0;
	int no_four_same_words = 1;
	occurance_t sentence[3000];
	while((no_four_same_words) && i<=3000)
	{
		fgets(words[i], 200, stdin);
		no_four_same_words = fix_count(sentence, i);
		i++;
	}
	for(int j = 0; j < i; j++)
	{
		if(sentence[j].count[0][0] == '4')
		{
			for(int k = 1; k < 5; k++)
			{
				printf("%s\n", sentence[j].count[k]);
			}
		}
	}
	return 0;
}
int fix_count(occurance_t* sentence, int i)
{
	int j, h, k;
	for(j = 0; (j < i) || (i == 0); j++)
	{
		if( (hash(i) == hash(j)) && i!=0 )
		{
			h = ++sentence[j].count[0][0] - 48;
			for(k = 0; k < strlen(words[i]); k++)
			{
				sentence[j].count[h][k] = words[i][k];
			}
			sentence[i].count[0][0] = '0';
			if(h == 4) return 0;
		}
		else
		{
			sentence[i].count[0][0] = 49;
			for(k = 0; k < strlen(words[i]); k++)
			{
				sentence[i].count[1][k] = words[i][k];
			}
		}
		if(i == 0) break;
	}
	return 1;
}
long hash(int i)
{
	int value = 42;
	for(int j = 0; j < strlen(words[i]); j++)
	{
		value = value + words[i][j]*(j+1);
	}
	return value;
}
