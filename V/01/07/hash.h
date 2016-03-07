#include <string.h>

typedef struct
{
	long int hash_sum;
	unsigned short int a;
	char words_with_this_hash[4][200];
}
occurance_t;

long int hash(char *word)
{
	long int hash_sum=42;
	unsigned short int i, l;
	l=strlen(word);
	for(i=0; i<l; i++)
	{
		hash_sum+=(int)word[i]*(i+1);
	}
	return hash_sum;
}