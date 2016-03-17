#include <stdio.h>
#include <string.h>

long hash(char *);

struct occurance_t{
	long hash;
	char word[4][200];
	int count;
};

int main()
{
	int i=0, n=0, j=0, temp=0;
	char word[200];
	long temp_hash=0;
	struct occurance_t words[3000], temp_swap;
	while(i!=3000)
	{
		j=0;
		while(j!=4)
		{
			words[i].word[j][0]='0';
			j++;
		}
		words[i].hash=0;
		words[i].count=0;
		i++;
	}
	i=0;
	while(1)
	{
		temp=0;
		n=0;
		scanf("%s", word);
		temp_hash=hash(word);
		while(n!=i)
		{
			if (words[n].hash==temp_hash)
			{
				j=0;
				while(j<words[n].count)
				{
					if ((strcmp(word, words[n].word[j])==0))
					{
						temp=1;
						break;
					}
					j++;
				}
				if(temp==0)
				{
					j=words[n].count;
					strcpy(words[n].word[j], word);
					words[n].count++;
					temp=1;
				}
				break;
			}
			n++;
		}
		if (temp==0)
		{
			strcpy(words[i].word[0], word);
			words[i].hash=temp_hash;
			words[i].count++;
			i++;
		}
		if(j==3)
		{
			break;
		}
	}
	while(1)
	{
		temp=0;
		for(n=0; n<i; n++)
		{
			if(words[n].hash>words[n+1].hash)
			{
				temp_swap=words[n];
				words[n]=words[n+1];
				words[n+1]=temp_swap;
				temp=1;
			}
		}
		if(temp==0)
		{
			break;
		}
	}
	n=0;
	while (n<=i)
	{
		switch (words[n].count)
		{
			case 2:
				printf("%ld %s %s\n", words[n].hash, words[n].word[0], words[n].word[1]);
				break;
			case 3:
				printf("%ld %s %s %s\n", words[n].hash, words[n].word[0], words[n].word[1], words[n].word[2]);
				break;
			case 4:
				printf("%ld %s %s %s %s\n", words[n].hash, words[n].word[0], words[n].word[1], words[n].word[2], words[n].word[3]);
				break;
			default:
				break;
		}
		n++;
	}
	return 0;
}

long hash(char *word)
{
	long hash=42;
	int n, i=0, temp;
	n=strlen(word);
	while(i!=n)
	{
		temp=word[i];
		hash=hash+(temp*(i+1));
		i++;
	}
	return hash;
}