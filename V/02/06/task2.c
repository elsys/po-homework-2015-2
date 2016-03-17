#include <stdio.h>
#include <string.h>

char* find( char *, char );

int main() {
	int i = 0;
	char arr[5000], letter = 'q', helper = 0;
	for( i = 0; helper != '\n' ; i++ ) {
		arr[i] = getchar();
		helper = arr[i];
	}

	scanf("%s", &letter); 

	if( find( arr, letter ) == NULL ) {
		printf("-1");
	} else {
		printf("%ld", find( arr, letter ) - arr );
	}

	return 0;
}

char* find( char *haystack, char needle ) {

	int i = 0;
	for( i = 0; i < strlen( haystack ) ; i++ ) {
		
		if( i == strlen(haystack) ) {
			return NULL;
		}

		if( needle == haystack[i]) {// pointer is only 2 byte;
			return ( haystack + i ) ; 
		}
	}
	return NULL;
}
