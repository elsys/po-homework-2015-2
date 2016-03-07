#include <stdio.h>
#include <string.h>

typedef struct {
	long hash, count;
} occurance_t;

long hash(char *word) {
	long i, sum = 42;
 
	for (i = 0; i < strlen(word); ++i)
		sum += word[i]*(i+1);
 
	return sum;
}
 
int main() {
	occurance_t words[3000], most_word;
	char word[200];
	long i;

	while(strcmp(word, "vsmisal") != 0) {
		scanf("%s", word);

		for (i = 0; i <= 3000; i++) {
			if (words[i].hash == hash(word)) {
				if (++words[i].count > most_word.count)
					most_word = words[i];
				
				break;
			} else if (words[i].hash == 0) {
				words[i].hash = hash(word);
				words[i].count = 1;
				break;
			}
		}

	}

 	printf("%ld %ld\n", most_word.count, most_word.hash);
 
	return 0;
}
