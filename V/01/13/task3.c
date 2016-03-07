#include <stdio.h>
#include <string.h>

struct occurance_t{
	long hash;
	int occurance;
	char words[4][200];
};

long hash(char *word);

int main()
{
	struct occurance_t input[3000], swap;
	memset(&input,0,sizeof(struct occurance_t)*3000);
	char word[200];
	int i = 0;

    for(int t=0 ; t<3000 && scanf(" %s",word) != EOF ; t++)
    {
        for(int i=0 ; i<3000 ; i++)
        {
            if(input[i].hash!=0 && hash(word)==input[i].hash)
            {
                strcpy(input[i].words[input[i].occurance],word);
                input[i].occurance++;
                break;
            }
            else if(input[i].hash==0)
            {
                input[i].hash = hash(word);
                strcpy(input[i].words[input[i].occurance],word);
                input[i].occurance++;
                break;
            }
        }
        if(input[i].occurance >= 4) break;
    }

    for(int c = 0 ; c < ( i - 1 ); c++)
    {
        for(int d = 0 ; d < i - c - 1; d++)
        {
            if(input[d].hash < input[d+1].hash)
            {
                swap       = input[d];
                input[d]   = input[d+1];
                input[d+1] = swap;
            }
        }
    }

    for(int h=0;h<i;h++)
    {
        printf("[%ld]",input[h].hash);
        for(int n=0 ; n<input[h].occurance ; n++)
        {
            printf(" %s",input[h].words[n]);
        }
        printf("\n");
    }

	return 0;
}

long hash(char *word)
{
	long hash = 42;
	int i, len = strlen(word);
	for(i=0;i<len;i++)
	{
		hash += word[i] * (i+1);
	}
	return hash;
}