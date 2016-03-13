#include <stdio.h>
#include <string.h>

long hash(char *);

struct occurance_t{
	long hash;
	int count;
};

int main()
{
	int i=0, n=0, temp_1=0;
	char word[200];
	long temp;
	struct occurance_t words[3000];
	while(i!=3000)
	{
		words[i].hash=0;
		words[i].count=0;
		i++;
	}
	i=0;
	while(1)
	{
		temp_1=0;
		scanf("%s",word);
		if(word[0]=='v' && word[1]=='s' && word[2]=='m' && word[3]=='i' && word[4]=='s' && word[5]=='a' && word[6]=='l')
		{
			break;
		}
		else
		{
			temp=hash(word);
			n=0;
			while(n!=i)
			{
				if(temp==words[n].hash)
				{
					words[n].count++;
					temp_1=1;
					break;
				}
				n++;
			}
			if (temp_1==0)
			{
				words[i].hash=temp;
				words[i].count++;
				i++;
			}
		}
	}
	n=i;
	while(1)
	{
		temp_1=0;
		for(i=0; i<n; i++)
		{
			if(words[i].count<words[i+1].count)
			{
				words[i].count=words[i].count+words[i+1].count;
				words[i+1].count=words[i].count-words[i+1].count;
				words[i].count=words[i].count-words[i+1].count;

				words[i].hash=words[i].hash+words[i+1].hash;
				words[i+1].hash=words[i].hash-words[i+1].hash;
				words[i].hash=words[i].hash-words[i+1].hash;
				temp_1=1;
			}
		}
		if(temp_1==0)
		{
			break;
		}
	}
	printf("%d %ld\n", words[0].count, words[0].hash);
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