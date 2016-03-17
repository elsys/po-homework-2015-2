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
	
	/*sort -.-*/
	long swap;
	char tempString[200];
	for (int i = 0 ; i < c - 1; i++)
	{
		for (int d = 0 ; d < c - i - 1; d++)
		{
		  if (word[d].hash > word[d+1].hash)
		  {
			swap = word[d].hash;
			word[d].hash = word[d+1].hash;
			word[d+1].hash = swap;
			
			swap = word[d].count;
			word[d].count = word[d+1].count;
			word[d+1].count = swap;
			
			strcpy(tempString, word[d].word[0]);
   			strcpy(word[d].word[0], word[d+1].word[0]);
   			strcpy(word[d+1].word[0], tempString);
   			
   			strcpy(tempString, word[d].word[1]);
   			strcpy(word[d].word[1], word[d+1].word[1]);
   			strcpy(word[d+1].word[1], tempString);
   			
   			strcpy(tempString, word[d].word[2]);
   			strcpy(word[d].word[2], word[d+1].word[2]);
   			strcpy(word[d+1].word[2], tempString);
   			
   			strcpy(tempString, word[d].word[3]);
   			strcpy(word[d].word[3], word[d+1].word[3]);
   			strcpy(word[d+1].word[3], tempString);
		  }
		}
	}
	/*...*/
	
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
