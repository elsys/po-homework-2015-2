#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct occurance_t
{
	int hash;
	int number_words;
}words[3000];

long hash(char *);

int main ()
{

	
	int count, count2 = 0, count3, max = 1, n = 0;
	char word[200];
	
	for(count = 0; count < 3000; count++)
	{
		scanf("%s", word);
		if(word[0] == 'v' && word[1] == 's' && word[2] == 'm' && word[3] == 'i' && word[4] == 's' && word[5] == 'a' && word[6] == 'l') 
			break;
			
  		words[count2].hash = hash(word);
  		words[count2].number_words = 1;
  	
  		for(count3 = 0; count3 < count2; count3++)
  		{
  	
  	   		if(words[count3].hash == words[count2].hash)
  	   		{
  	     			words[count2].number_words++;
  	   		}
  		}
  	
  		count2++;
	}
	for(count3 = 0; count3 < count2; count3++)
	{
    		if(words[count3].number_words > max)
		{
	       	     max = words[count3].number_words;
	             n = count3;  
	     	}
	   
	   
     	}
     	
   	printf("%d %d \n", words[n].number_words, words[n].hash);
   

	return 0;
}

long hash(char *word)
{
	int l, count, i, end = 42, k;
	
	l = strlen(word);
	
	for(count = 0, i = 1; count < l; count++, i++)
		{
			k = word[count];
			k = k * i;
			end = end + k;
		}
	
	return end;

}
