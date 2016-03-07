#include <stdio.h>
#include <string.h>

long hash(char *word);

int main()
{
    char word[200];

    scanf("%s", word);

    printf("%ld", hash(word));

    return 0;

}

long hash(char *word){

    int counter;
    long hash_code = 42;

    for(counter = 0; counter < strlen(word); counter++){

        hash_code += word[counter] * (counter + 1);

    }

    return hash_code;

}
