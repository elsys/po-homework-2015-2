#include <stdio.h>
#include <stdlib.h>

char* find(char *haystack, const char needle)
{
	for(int i = 0; haystack[i] != '\0'; i++)
		if(*(haystack+i) == needle)
			return (haystack+i);
	return NULL;
}


int main () {
	int size = 1;
	char* input = malloc(sizeof(char)*size), c;
	while((c = getchar()) != '\n') {
		input[size-1] = c;	
		input = (char*) realloc(input, ++size);
	}
	c = getchar();
	printf("%d", (find(input, c) != NULL) ? (find(input,c) - input)*sizeof(char) : (-1) );
	free(input);
	return 0;
}