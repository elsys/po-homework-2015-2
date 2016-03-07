#include <stdio.h>
#include <string.h>

long hash(char *);

int main()
{
    char word[200];

    scanf("%s", word);

    printf("%ld", hash(word));

    return 0;

}

long hash(char *word){

    int count;
    long hash = 42;

	for(count = 0; count < strlen(word); count++){
	
		hash = hash + word[count]*(count+1);
	
	}

    return hash;

}
