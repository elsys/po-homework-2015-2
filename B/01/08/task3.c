#include <stdio.h>
#include <string.h>


struct occurance_t {
	long hash;
	int count;
	const char *words_t[4];
	int occurances;
};

long hash(char *);

int main() {

	char word[200], words1[3000][200];
	long arr[3000][2];
	long curr_hash, curr_word_hash = 42;
	int i, j, max = 0, l, t_word, counter, k = 0, n = 0;
	struct occurance_t words;

	for(i = 0; i < 3000; i++) {
		arr[i][0] = 0;
		arr[i][1] = 0;
	} 

	while(1) {

		scanf("%99s", word);

		for(i = 0; i < strlen(word); i++) {
			words1[n][i] = word[i];
		}

 		n++;

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

	printf("%ld ", words.hash);

	for(j = 0, k = 0; j < 4 && k < 3000; k++, j++) {
		
		for(counter = 0, i = 0; words1[k][i] != 0; counter++, i++);

		for(i = 0; i < counter; i++) {
			curr_word_hash += words1[k][i] * (i + 1);

		}

		if(t_word == curr_word_hash) {
		
			for(l = 0; l < counter; l++) {
				printf("%c", words1[k][l]);
			}
			printf(" ");
		}
		else {
			j = 0;
		}

		curr_word_hash = 42;

	}
	
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