#include<stdio.h>
#include<string.h>

struct occurance_t
{
	long hash_word;
	int most_used_word;
	
};

long hash(char *word)
{
    long count_ascii = 42;
    long counter = 0;
   
    while(word[counter] != '\0')
    {
        count_ascii = count_ascii + (word[counter] * (counter + 1));
        counter ++;
    }
    return count_ascii;
}

int main()
{
	char word[200];
	int counter = 0 ,counter2 = 0,counter3 = 1,counter4 = 1,counter5 = 0;
	struct occurance_t arr[3000];
	arr[0].most_used_word = 1;
	
	while(1)
	{
		scanf("%s",word);
		if(strcmp(word,"vsmisal") == 0)
		{
			counter ++;
			break;
		}
		arr[counter].hash_word = hash(word);
		counter++;
	}
	for(;counter2 < counter;counter2++)
	{
		for(;counter3 < counter;counter3++)
		{
			if(arr[counter2].hash_word == arr[counter3].hash_word)
			{
				arr[0].most_used_word += 1;
				counter3++;
				counter5 = counter2;
			}
			
		}
		counter3 = 1 + counter4;
		counter4++;
	}
	printf("%d %ld\n",arr[0].most_used_word, arr[counter5].hash_word);
		
	return 0;
}
