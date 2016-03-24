#include <stdio.h>
#include <string.h>

char* find (char *haystack, char needle);

int main () {
	char haystack[401];
	char needle;

	scanf ("%[^\n]s", haystack);
	scanf ("%s", &needle);

	find (haystack, needle);

	return 0;
}

char* find (char *haystack, char needle) {
	int count;

	for (count = 0; count < 400; count++) {
	if (haystack[count] == needle) {
	printf ("%d", count);
	return haystack;
	}
	}

	printf ("-1");

	return NULL;
}
