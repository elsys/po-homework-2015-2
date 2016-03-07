#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define WORD 200
#define MAX 3000

struct occurance_t
{
	long hash;
	int count;

};

long hash(char *word);

int main()
{
	int i = 0,j,k,result,max = 0;
	char arr[MAX];
	struct occurance_t word[MAX];

	for(i = 0; i < MAX; i++)
	{
		word[i].hash=0;
		word[i].count=0;
	}


	do
	{
	scanf("%s",arr);
	result = hash(arr);
	
	for(j=0; j<MAX; j++)
		{
			if(word[j].hash == result)
			{
				word[j].count++;

				break;
			}
			else if(word[j].hash == 0)
			{
				word[j].hash=result;

				word[j].count=1;

				break;
			}
		}

	i++;
	}while(strcmp(arr,"vsmisal")!= 0);
	
		
	for(j = 0; j < i; j++)
     {
    	if(word[j].count > max)
   	   {
       	     max=word[j].count;

             k=j;
        }
	   
	   
     }


	printf("%d %ld",word[k].count,word[k].hash);
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