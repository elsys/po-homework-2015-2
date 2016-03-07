#include <stdio.h>
#include "hash.h"

int main()
{
	unsigned short int i, j;
	char word[200];
	long int hashed_word;
	occurance_t hashes[3000];
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
	for(i=0; i<4; i++)
		printf("%s",hashes[j].words_with_this_hash[i]);
	return 0;
}