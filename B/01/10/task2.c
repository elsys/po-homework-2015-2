#include <stdio.h>
#include <string.h>

long hash(char *);


struct occurance_t {

	long word_hash;
	int times;

}Max;

int main () {

	char current_word[201];
	
	int WordsNumber = 0;

	struct occurance_t MaxWords[3000];
	
	
	int index = 0;



	for(;;index++) {
		scanf("%s",current_word);
		if (current_word[0] == 'v')
		if (current_word[1] == 's')
		if (current_word[2] == 'm')
		if (current_word[3] == 'i')
		if (current_word[4] == 's')
		if (current_word[5] == 'a')
		if (current_word[6] == 'l') break;					
		

		MaxWords[index].word_hash = hash(current_word);//Hash for word

		MaxWords[index].times = 1;

		for (WordsNumber = 0; WordsNumber < index; ++WordsNumber)
		{
			
			if (MaxWords[index].word_hash==MaxWords[WordsNumber].word_hash) MaxWords[index].times += 1;
		}
		Max.times = MaxWords[index].times;
		Max.word_hash = MaxWords[index].word_hash;
	}


	printf("%d %ld", Max.times, Max.word_hash);

	return 0;
}

long hash(char *word) {
	long hash = 42;

	int position = 1;
	
	int index = 0;

	for (index = 0; index < strlen(word); index++) {

		hash = hash + (word[index]*position);
		position++;
	}
	return hash;
}
