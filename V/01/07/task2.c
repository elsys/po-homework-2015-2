#include <stdio.h>
#include "hash.h"

int main()
{
	char word[200];
	unsigned short int i, j, max=0, id_of_max=0;
	long int hashed_word;
	occurance_t hashes[2001];
	for(i=0; i<2001; i++)
	{
		hashes[i].hash_sum=0;
		hashes[i].a=0;
	}
	i=0;
	do
	{
		scanf("%s", word);
		i++;
		hashed_word=hash(word);
		for(j=0; j<2000; j++)
		{
			if(hashes[j].hash_sum==hashed_word)
			{
				hashes[j].a++;
				break;
			}
			else if(hashes[j].hash_sum==0)
			{
				hashes[j].hash_sum=hashed_word;
				hashes[j].a=1;
				break;
			}
		}
	}
	while(strcmp(word, "vsmisal")!=0);
	i=0;
	while(hashes[i].a!=0)
	{
		if(hashes[i].a>max)
		{
			max=hashes[i].a;
			id_of_max=i;
		}
		i++;
	}
	printf("%d %ld\n",max, hashes[id_of_max].hash_sum);
	return 0;
}