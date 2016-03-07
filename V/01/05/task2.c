#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int hash(char *word);

struct occurance_t
{
	long int hash_times;
	int number;
};

int main()
{
	char letter[200];
	struct occurance_t m;
	struct occurance_t max[3000];
	int a,b,i = 0,number = 3000;

	while(i < number)
	{
		scanf("%s",letter);
		max[i].hash_times = hash(letter);
		max[i].number = 0; 

		if(letter[0] == 'v' &&
			letter[1] == 's' &&
			letter[2] == 'm' &&
			letter[3] == 'i' &&
			letter[4] == 's' &&
			letter[5] == 'a' &&
			letter[6] == 'l')
			break;
		i++;
 	}
 	for(a = 0; a < i - 1; a++)
		for(b = 1; b < i; b++)
		{
			if(max[a].hash_times == max[b].hash_times)
				max[a].number++;
		}
		m.number = max[0].number;
		for(a = 0; a < i -1; a++)
		{
			if(m.number < max[a + 1].number)
			{
				m.hash_times = max[a + 1].hash_times;
				m.number = max [a + 1].number;
			}
		}
		printf("%d %li",m.number,m.hash_times);
		return 0;
}

long int hash(char *word)
{
	int begin = 42;
	int i = 0,l;
	l = strlen(word);
	while(i < l)
	{
		begin += word[i]*(i + 1);
		i++;
	}
	return begin;
}
