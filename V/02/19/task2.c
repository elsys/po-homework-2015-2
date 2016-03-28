#include <stdio.h>
#include <string.h>

char* find(char* , char);

int main() {
	char search[400], c = getchar();
	int i = 0;
	while(c != '\n') {
		search[i++] = c;
		c = getchar();
	}
	search[i] = '\0';
	c = getchar();
	if(find(search, c) == NULL);
	else {
		int result = (int)(find(search,c) - search);
		printf("%d\n", result);
		return 0;
	}
	printf("%d\n", -1);
	return 0;
}


char* find(char *haystack, char needle) {
	int i;
	for(i = 0; i <= strlen(haystack); i++) {
		if(i == strlen(haystack)) {
			return NULL;
		}
		if(haystack[i] == needle) {
			return &haystack[i];
		}
	}
	return NULL;	
}