#include <stdio.h>
#include <string.h>


struct occurance_t {
	long hash;
	int count;
};

long hash(char *);

int main() {

	char word[200];
	long arr[3000][2];
	long curr_hash;
	int i, max = 0, t_word;
	struct occurance_t words;

	for(i = 0; i < 3000; i++) {
		arr[i][0] = 0;
		arr[i][1] = 0;
	} 

	while(1) {

		scanf("%99s", word);

		if(word[0] == 'v' &&
		   word[1] == 's' &&
		   word[2] == 'm' &&
		   word[3] == 'i' &&
		   word[4] == 's' && 
		   word[5] == 'a' &&
		   word[6] == 'l') break;

		curr_hash = hash(word);

		for(i = 0; i < 3000; i++) {
			if(arr[i][0] == 0) 
			{
				arr[i][0] = curr_hash;
				arr[i][1]++;
				i = 3000;
			}
			else if(curr_hash == arr[i][0]) 
			{
				arr[i][1]++;
				i = 3000;
			}
		}

	}

	for(i = 0; i < 3000; i++) {
		if(arr[i][1] > max) 
		{
			max = arr[i][1];
			t_word = arr[i][0];
		} 
	}

	words.hash = t_word;
	words.count = max;

	printf("%d %ld", words.count, words.hash);

	return 0;
}

long hash(char *word) {
	long hash = 42;
	int i;

	for(i = 0; i < strlen(word); i++) {
		hash += word[i] * (i + 1);
	}

	return hash;
}