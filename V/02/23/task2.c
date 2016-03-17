#include <stdio.h>
#include <string.h>

int is_eq(char a, char b) {
	return a == b;
}

char* find(char *haystack, char needle) {
	int i = 0;
	for(; i < strlen(haystack); i++) {
		if(is_eq(haystack[i], needle)) {
			return &haystack[i];
		}
	}
	return NULL;
}

int main() {
	char word[400] = {0}, c;
	scanf("%[^\n]s", word);
	scanf("%c", &c);
	c = getchar();
	printf("%d", (find(word, c) == NULL) ? (-1) : (find(word, c)- word));

	return 0;
}