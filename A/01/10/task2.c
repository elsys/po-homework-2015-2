#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct occurance_t
{
	long hash;
	int count;
};

long hash(char *);

int main()
{
	char word[200]="";	
	struct occurance_t occurance[3000];
	int n=0,i=0,max=0;
	long max_hash=0;
	int found;
	long sum=0,end=3050;
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
			}
		}

		if(found==0)
		{
			occurance[n].hash=sum;
			occurance[n].count=1;
			n++;
		}
	}while(sum!=end);
	for(i=0;i<n;i++)
	{
		if(occurance[i].count>max)
		{
			max_hash=occurance[i].hash;
			max=occurance[i].count;
		}
	}
	printf("\n%d %ld",max,max_hash);
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
