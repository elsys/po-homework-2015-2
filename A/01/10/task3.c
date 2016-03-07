#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct occurance_t
{
	long hash;
	int count;
	char array[4][200];
	int n;
};

long hash(char *word);

int main()
{
	char word[200];	
	struct occurance_t occurance[3000];
	int n=0,i=0,j=0;
	int found,word_found,stop=0;
	long sum=0;
	do{
		do{
			scanf("%s",word);
		}while(strlen(word)>200);
		sum=hash(word);
		found=0;
		for(i=0;i<n;i++)
		{
			if(occurance[i].hash==sum)
			{
				occurance[i].count++;
				found=1;
				word_found=0;
				for(j=0;j<occurance[i].n;j++)
				{
					if(occurance[i].array[j]==word)
					{
						word_found=1;
					}
				}
				if(word_found==0)
				{
					strcpy(occurance[i].array[occurance[i].n],word);
					occurance[i].n++;
					if(occurance[i].n==4)
					{
						stop=1;
					}
				}
			}
		}

		if(found==0)
		{
			occurance[n].hash=sum;
			occurance[n].count=1;
			strcpy(occurance[n].array[0],word);
			occurance[n].n=1;
			n++;
		}

	}while(stop!=1 && n<300);
	for(i=0;i<n;i++)
	{
		printf("\n%ld",occurance[i].hash);
		for(j=0;j<occurance[i].n;j++)
		{
			printf(" %s",occurance[i].array[j]);
		}
	}
	return 0;
}

long hash(char *word)
{
	long sum=42;
	int i=0;
	for(i=0;i<strlen(word);i++)
	{
		sum=sum+word[i]*(i+1);
	}
	return sum;
}
