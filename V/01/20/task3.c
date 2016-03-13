#include <stdio.h>
#include <string.h>

typedef struct {
	long hash, count;
	char similar[4][200];
} occurance_t;

long hash(char *word) {
	long i, sum = 42;
 
	for (i = 0; i < strlen(word); ++i)
		sum += word[i]*(i+1);
 
	return sum;
}

int main() {
	occurance_t words[3000];
	char word[200];
	long i, max_count = 0, k = 0;

	while(max_count < 4) {
		scanf("%s", word);

		for (i = 0; i <= 3000; ++i) {
			if (words[i].hash == hash(word)) {
				strcpy(words[i].similar[++words[i].count], word);

				if (words[i].count > max_count) 
					max_count = words[i].count;

				break;
			} else if (words[i].hash == 0) {
				words[i].hash = hash(word);
				words[i].count = 1;
				strcpy(words[i].similar[words[i].count], word);
				break;
			}
		}

		++k;
	}

	for (i = 0; i < k ; ++i) {
		if (words[i].count >= 2) {
			printf("[%ld]", words[i].hash);
			
			int j;

			for (j = 0; j <= 4; ++j)
				printf("%s ", words[i].similar[j]);

			printf("\n");
		}
	}

	return 0;
}
