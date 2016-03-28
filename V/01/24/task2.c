#include <stdio.h>
#include <string.h>

long hash(char *);

struct occurance_t 
{

	int count;
	long hesh;
	
};

int main() 
{

	int c = 0, i, j;
	struct occurance_t sentence[200];
	struct occurance_t holder;
	char word[200];
	
	do{
	
		scanf("%s", word);
		
		sentence[c].hesh = hash(word);
		sentence[c].count = 1; 
		
		
		for(i = 0; i < c; i++) 
		{
		
			if(sentence[i].hesh == hash(word)) 
			{
			
				sentence[i].count++;
				
			}
			
		}
		
		c++;
		
	}while(!(word[0] == 'v' && word[1] == 's' && word[2] == 'm' && word[3] == 'i' && word[4] == 's' && word[5] == 'a' && word[6] == 'l' && word[7] == '\0'));

	for(i = 0; i < c; i++)
	 {
	
		for(j = 0; j < c; j++)
		{
		
			if(sentence[i].count > sentence[j].count) 
			{
			
				holder = sentence[i];
				sentence[i] = sentence[j];
				sentence[j] = holder;
				
			}
			
		}
			
	} 

	printf("%d %ld \n",sentence[0].count ,sentence[0].hesh);


	return 0;
}

long hash(char *word)
{

    int count;
    long hash = 42;

	for(count = 0; count < strlen(word); count++)
	{
		hash = hash + word[count]*(count+1);
	}
    return hash;
}
