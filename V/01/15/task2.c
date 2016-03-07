#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task2.h"

extern short strleng(char*);
extern long hash(char*);

char* getWord();

int compare_signature(occurance_t*, int, long);
occurance_t* add_signature(occurance_t* , occurance_t);


int main() {
	char* word = NULL;
	int size = 0;
	occurance_t* occ_class = NULL;
	while(strcmp(word = getWord(), "vsmisal")) {
		int tmp;
		if((tmp = compare_signature(occ_class, size, hash(word))) != 0)
			occ_class[tmp].times++;
		else {
			occurance_t temp;
			temp.hash = hash(word);
			temp.times = 1;
			occ_class = add_signature(occ_class, temp);
			size++;
		}
	}

	int tmp = 0;

	for(int i = 0; i < size; i++) {
		if(occ_class[i].times > tmp)
			tmp = i;
	}

	printf("%d %ld\n", occ_class[tmp].times, occ_class[tmp].hash);

	free(word);
	free(occ_class);

	return 0;
}

occurance_t* add_signature(occurance_t* occ_class, occurance_t base) {
	static int size = 0;
	if(occ_class == NULL) {
		occ_class = (occurance_t*) malloc(sizeof(occurance_t) * (++size)); // return ((occ_class = malloc(occ_class, sieof(occurance_t) * (++size))[0] = base);
		occ_class[size-1] = base;
		return occ_class;
	}
	occ_class = realloc(occ_class, sizeof(occurance_t) * (size+1));
	occ_class[size++] = base;
	return occ_class;
}

int compare_signature(occurance_t* occ_class, int size, long base) {
	if(occ_class == NULL)
		return 0;
	for(int i = 0; i < size; i++) {
		if(occ_class[i].hash == base)
			return i;
	}
	return 0;
}

char* getWord() {
	short size;
	char* input = malloc(sizeof(char) * (size=50)), c;
	int len = 0;
	while(((c = getchar()) != EOF) && c != ' ' && c != '\n') {
		input[len++] = c;
		if(len == size) input = realloc(input, sizeof(char) * (size *= 2));
	}
	input[len++] = '\0';
	return realloc(input, sizeof(char) * len);
}
