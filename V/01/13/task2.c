#include <stdio.h>
#include <string.h>

struct occurance_t{
	long hash;
	int occurance;
};

long hash(char *word);

int main()
{
	struct occurance_t input[3000];
	memset(&input,0,sizeof(struct occurance_t)*3000);
	char word[200];
	int check = 0, i = 0;

	while(scanf(" %s",word) != EOF && strcmp(word,"vsmisal")!=0)
	{
		for(i=0;i<3000;i++)
		{
			if(hash(word)==input[i].hash && input[i].hash!=0)
			{
				input[i].occurance++;
				break;
			}
			else if(input[i].hash==0)
            {
                input[i].hash = hash(word);
                input[i].occurance++;
                break;
            }

		}
	}

	for(int j=1 ; j<i ; j++)
    {
        if(input[j].occurance > input[check].occurance)
            check = j;
    }
    printf("%d %ld",input[check].occurance,input[check].hash);
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