#include <stdio.h>
#include <string.h>

struct occurance_t{
	long hash_of_word;
	char words[200];
	int most_common_words;
	int is_met;
};

long hash(char *);

int main()
{
	char word[200];
	int counter = 1;
	struct occurance_t arr[3000];
	
		//scanf("%s",word);
		//arr[0].hash_of_word = hash(word);
		//strcpy(arr[0].words[0] ,word);
	
	
	while(arr[0].most_common_words != 4)
	{
		scanf("%s",word);
		arr[counter].hash_of_word = hash(word);
		arr[0].hash_of_word = hash(word);
		strcpy(arr[counter].words ,word);
		strcpy(arr[0].words ,word);
		
		if(arr[0].hash_of_word == arr[counter].hash_of_word)
		{
			arr[0].most_common_words ++;
			arr[counter].is_met = 1;
		}
		counter++;
	}
	printf("%ld ",arr[0].hash_of_word);
	counter = 0;

	while(counter < arr[0].most_common_words)
	{
		printf("%s ",arr[counter].words);
		counter ++;
	}
	printf("\n");
	
	return 0;
}
long hash(char *word)
{
    long ascii_counter = 42;
    long counter = 0;

    while(word[counter] != '\0')
    {
        ascii_counter = ascii_counter + (word[counter] * (counter + 1));
        counter++;
    }
    return ascii_counter;
}
