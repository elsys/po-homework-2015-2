#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct occurance_t
{
	int hash;
	int count;
};

long hash(char *word)
{
    int i;
	int num=42;
	for(i=0;i<strlen(word);i++)
	{
		num = num+word[i]*(i+1);
	}
	return num;
}

int main()
{
	char word[200];
	struct occurance_t occurance[3000];
	int n=0,i=0,num_occurances=0;
    long max_hash=0;
	int tmp=0;
	int num=0;
	int stop=0;
	while(n<201 && stop==0)
    {
        scanf("%s",word);

        if(strcmp(word,"vsmisal")!=0)
        {
             num=hash(word);
            tmp=0;
            for(i=0;i<n;i++)
            {
                if(occurance[i].hash==num)
                {
                    occurance[i].count++;
                    tmp=1;
                    break;
                }
            }
            if(tmp==0)
            {
                occurance[n].hash=num;
                occurance[n].count=1;
                n++;
            }

        }
        else
        {
            stop=1;
        }
	}
	for(i=0;i<n;i++)
	{
		if(occurance[i].count>num_occurances)
		{
			max_hash=occurance[i].hash;
			num_occurances=occurance[i].count;
		}
	}
	printf("\n%d %ld",num_occurances,max_hash);

	return 0;
}

