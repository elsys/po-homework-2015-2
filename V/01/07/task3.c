#include <stdio.h>
#include "hash.h"

int main()
{
	unsigned short int i, j, sorted=0;
	char word[200];
	long int hashed_word;
	occurance_t hashes[3000], sort_help;
	for(i=0; i<3000; i++)
	{
		hashes[i].hash_sum=0;
		hashes[i].a=0;
		for(j=0; j<4; j++)
			hashes[i].words_with_this_hash[j][0]='\0';
	}
	for(i=0; i<3000; i++)
	{
		scanf("%s",word);
		hashed_word=hash(word);
		for(j=0; j<3000; j++)
		{
			if(hashes[j].hash_sum==hashed_word)
			{
				strcpy(hashes[j].words_with_this_hash[hashes[j].a], word);
				hashes[j].a++;
				break;
			}
			else if(hashes[j].hash_sum==0)
			{
				hashes[j].hash_sum=hashed_word;
				hashes[j].a=1;
				strcpy(hashes[j].words_with_this_hash[0], word);
				break;
			}
		}
		if(hashes[j].a==4)
			break;
	}
	i=0;
	while(!sorted)
	{
		sorted=1;
		for(j=0; j<2999-i; j++)
		{
			if(hashes[j+1].hash_sum==0)
				break;
			if(hashes[j].hash_sum > hashes[j+1].hash_sum)
			{
				sorted=0;
				sort_help=hashes[j+1];
				hashes[j+1]=hashes[j];
				hashes[j]=sort_help;
			}
		}
		i++;
	}
	for(i=0; i<3000; i++)
	{
		if(hashes[i].hash_sum==0)
			break;
		if(hashes[i].a>1)
		{
			printf("%ld ",hashes[i].hash_sum);
			for(j=0; j<4; j++)
			{
				if(hashes[i].words_with_this_hash[j][0]=='\0')
					break;
				printf("%s ",hashes[i].words_with_this_hash[j]);
			}
			printf("\n");
		}
	}
	return 0;
}