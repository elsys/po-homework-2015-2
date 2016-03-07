#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WORD 200
#define MAX 3000

struct occurance_t
{
	long hash;
	int count;
	char same[4][WORD];
	int len;
};

long hash(char *word);

int main()
{
	int i = 0,j,result;
	char arr[MAX];
	struct occurance_t word[MAX];

	for(i=0; i<MAX; i++)
	{
		word[i].hash=0;
		word[i].count=0;
		for(j = 0;j < 4;j++)
		word[i].same[j][0] = '\0';
	}


	do
	{

		scanf("%s", arr);
		result = hash(arr);
	
		for(j = 0; j < MAX; j++)
			{
				if(word[j].hash==result)
				{	
					strcpy(word[j].same[word[j].count],arr);

					word[j].count++;
					
					break;
				}

				else if(word[j].hash == 0)
				{
					word[j].hash=result;
					
					word[j].count=1;
					
					strcpy(word[j].same[0],arr);
					
					break;
				}
			}
			
		if(word[j].count==4)
			break;

	
	}while(1>0);
	
		
	
      
   	for(i = 0; word[i].hash != '\0'; i++)
	{
		printf("%ld  ",word[i].hash);
		for(j = 0 ; j <4;j++)
			printf("%s ",word[i].same[j]);
		printf("\n");
	}
	

	return 0;
}

long hash(char *word)
{
	int i,len;
	long asc = 42;
	
	len = strlen(word) - 1;
	
	for(i = 0; i <= len ; i++)
	{
		asc +=   word[i] * (i + 1);
	}

	return asc;
}