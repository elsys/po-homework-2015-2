#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* find (char *haystack, char needle);

int main() {

	char needle;
	char haystack[400] = {0};
	fgets(haystack, 400, stdin);
	scanf("%c", &needle);
	printf("%ld", find(haystack,needle) - haystack);

	return 0;
} 

char* find(char *haystack, char needle) {
	int j = strlen(haystack);
	for (int i = 0; i < j; i++) {
		if (needle == haystack[i]) {
			return &haystack[i];
		}
	}
	return NULL;
}
