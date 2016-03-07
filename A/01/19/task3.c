#include <stdio.h>
#include <string.h>

struct occurance_t
{
	long hash;
	long count;
	char word[4][200];
};


long hash(char*);


int main()
{
	char input[200];
	struct occurance_t word[3000];
	int c = 0;
	int end = 0;
	
	while(1)
	{
		scanf("%s", input);
		
		word[c].hash = hash(input);
		strcpy(word[c].word[0], input);
		word[c].count = 1;
		
		for(int i = 0; i < c; i++)
		{
			if(word[c].hash == word[i].hash)
			{
				c--;
				word[i].count++;
				
				end = word[i].count;
				
				switch(end)
				{
					case 2: strcpy(word[i].word[1], input); break;
					case 3: strcpy(word[i].word[2], input); break;
					case 4: strcpy(word[i].word[3], input); break;
				}
			}
		}
		c++;
		
		if(end == 4)
		{
			break;
		}
	}
	
	for(int i = 0; i < c; i++)
	{
		if(word[i].count > 1)
		{
			printf("%ld ", word[i].hash);
			for(int d = 0; d < 4; d++)
			{
				printf("%s ", word[i].word[d]);
			}
			printf("\n");
		}
	}

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
