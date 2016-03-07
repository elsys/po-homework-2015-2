#include<stdio.h>

struct occurance_t{
	int most_common_word;
	long hash_of_word;
};

long hash(char *);
int main()
{
	char word[200];
	int counter = 0 ,counter2 = 0,counter3 = 1,counter4 = 1,counter5 = 0;
	struct occurance_t arr[3000];
	arr[0].most_common_word = 1;
	
	while(1)
	{
		scanf("%s",word);
		if(word[0] == 'v' && word[1] == 's' && word[2] == 'm' && word[3] == 'i' 
		   && word[4] == 's' && word[5] == 'a' && word[6] == 'l')
		{
			//arr[counter].hash_of_word = hash(word);
			counter ++;
			break;
		}
		arr[counter].hash_of_word = hash(word);
		counter++;
	}
	while(counter2 < counter)
	{
		while(counter3 < counter)
		{
			if(arr[counter2].hash_of_word == arr[counter3].hash_of_word)
			{
				arr[0].most_common_word += 1;
				counter3++;
				counter5 = counter2;
			}
			counter3++;
		}
		counter2++;
		counter3 = 1 + counter4;
		counter4++;
	}
	printf("%d ",arr[0].most_common_word);
	printf("%ld\n",arr[counter5].hash_of_word);
		
	return 0;
}

long hash(char *word)
{
    long ascii_counter = 42;
    long counter = 0;
   
    while(word[counter] != '\0')
    {
        ascii_counter = ascii_counter + (word[counter] * (counter + 1));
        counter ++;
    }
    return ascii_counter;
}
