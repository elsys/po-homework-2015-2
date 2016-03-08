#include <stdio.h>
#include <string.h>
#define MAXLEN 3000
#define MAX 200

struct occurance_t
{
	long hash;
	int count;
};

long hash(char*);

int main()
{
	char input[MAXLEN];
	int CurrentWord, LastMost=0, CurrentMost, i, count;

	struct occurance_t word[MAXLEN];

	for(i=0; strcmp(input, "vsmisal")!=0; i++)
	{
		scanf("%s", input);
		if(i==0)
		{
			if(strcmp(input, "vsmisal")==0)
			{
				return 0;
			}
		}

		CurrentWord = hash(input);

		for (count = 0; count < MAXLEN; count++)
		{
			if(word[count].hash == CurrentWord)
			{
				word[count].count++;
				break;
			}
			
			else
			{
				if(word[count].hash == 0)
				{
					word[count].hash = CurrentWord;
					word[count].count = 1;
					break;
				}
			}
		}
	}


	for(count = 0; count<i; count++)
	{
		if(word[count].count > LastMost)
		{
			LastMost = word[count].count;
			CurrentMost = count;
		}
	}

	printf("%d %ld\n", word[CurrentMost].count, word[CurrentMost].hash);
	return 0;
}




long hash(char *input) 
{
    
    long sum = 42;
    int length = strlen(input);
    
    for (int count=0; count<length; count++) 
    {
    	if(input[count]!= '\n')
    	{
       		sum += input[count]*(count+1);
    	}
    }
    
    return sum;
}