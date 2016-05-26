#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct occurance_t
{
	long hash;
	int count;
	char array[4][200];
};

long hash(char *word);
int repeating_words(struct occurance_t *occurance, int pos, char *word);

int main()
{
	char word[200];	
	struct occurance_t occurance[3000];
	struct occurance_t temp;
	int i=0,j=0,stop=0,found,sort;
	long sum=0;
	do{
		scanf("%s",word);
	}while(strlen(word)>200);
	sum=hash(word);
	found=0;
	for(i=0;i<3000 && stop==0;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(occurance[j].count==0)
 			{
 				occurance[j].hash=sum;
				strcpy(occurance[j].array[occurance[j].count],word);
				occurance[j].count++;
				if(occurance[j].count==4)
				{
					stop=1;
					break;
				}
				found++;
				break;
			}
			if(occurance[j].hash==sum)
			{
				if(repeating_words(occurance,j,word)==1)
				{
					break;
				}
				strcpy(occurance[j].array[occurance[j].count],word);
				occurance[j].count++;
				if(occurance[j].count==4)
				{
					stop=1;
					break;
				}
				break;
			}
		}
		if(stop==0)
		{
			scanf("%s",word);
			sum=hash(word);
		}
	}
	while(sort!=1)
	{
		sort=1;
		for(i=0;i<found-1;i++)
		{
			if(occurance[i].hash>occurance[i+1].hash)
			{
				temp=occurance[i];
				occurance[i]=occurance[i+1];
				occurance[i+1]=temp;
				sort=0;
			}
		}
	}
	for(i=0;i<found;i++)
	{
		if(occurance[i].count>1)
		{
			printf("%ld ",occurance[i].hash);
			for(j=0;occurance[i].array[j][0]!=0 && j<4;j++)
			{
				printf(" %s ",occurance[i].array[j]);
			}
			printf("\n");
		}
	}
	return 0;
}

int repeating_words(struct occurance_t *occurance, int pos, char *word)
{
	int i=0;
	for(i=0;i<4;i++)
	{
		if(strcmp(word,occurance[pos].array[i])==0)
		{
			return 1;
		}
		if(occurance[pos].array[i][0]=='\0')
		{
			break;
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
