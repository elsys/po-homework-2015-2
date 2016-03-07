#include <stdio.h>
#include <string.h>

struct occurance_t
{
	long hash;
	long count;
};



long hash(char*);


int main()
{
	char input[200];
	struct occurance_t word[3000];
	int c = 0;
	
	while(1)
	{
		scanf("%s", input);
		
		if(strcmp(input, "vsmisal") == 0)
		{
			break;
		}
		
		word[c].hash = hash(input);
		word[c].count = 1;
		
		for(int i = 0; i < c; i++)
		{
			if(word[c].hash == word[i].hash)
			{
				c --;
				word[i].count++;
			}
		}
		
		c++;
	}
	
	long max_count = word[0].count;
	int current = 0;
	for(int i = 1; i < c; i++)
	{
		if(max_count < word[i].count)
		{
			max_count = word[i].count;
			current = i;
		}
	}
	
	printf("%ld %ld", max_count, word[current].hash);

	return 0;
}

long hash(char *word)
{
	long sum = 42;
	int ascii = 0;
	
	for(int i = 0; i < strlen(word); i++)
	{
		ascii = word[i];
		sum += (ascii * (i + 1));
	}

	return sum;
}
