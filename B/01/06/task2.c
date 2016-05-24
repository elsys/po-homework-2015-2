#include <stdio.h>
#include <string.h>

long hash(char * );

struct occurance_t
{
	int hesh;
	int times;
};

int main () 
{
	char word[200];
	int helper = 0, b = 1 , t=0;
	int p = 0;
	struct occurance_t str[3000];
	while(1)
	{
		scanf("%s", word);
			if(word[0] == 'v' && word[1] == 's' && word[2] == 'm' && word[3] == 'i' && word[4] == 's' && word[5] == 'a' && word[6] == 'l' )
				break;
		str[helper].hesh = hash(word);
		helper++;
	}	
	for (; p < helper; p++)
	{
		if(p == 0) 
			str[p].times = 1;
		for (;b < helper; b++ )
			if(str[p].hesh == str[b].hesh)
				str[p].times++;
		b = p;
	}	
	p=0;	
	b = 0;
	for (; p < helper ; p ++)
	{
		for(; b < helper; b++)
			if (str[p].times < str[b].times)
				t = b;
		b = p;		
	} 
	printf("%d %d", str[t].times , str[t].hesh);
	return 0 ;
}


long hash(char *word)
{
	int hesh = 42, helper = 0;
	int size = strlen (word);
	while(helper < size)
	{	
		hesh += word[helper] * (helper + 1);
		helper ++;	
	}
	return hesh;
}