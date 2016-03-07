#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long hash(char *w_word);

int main()
{
    char w_word[200] = {0};
    fgets(w_word,200,stdin);
    printf("%li", hash(w_word));
    return 0;
}

long hash(char *w_word)
{
    char word;
    long hash_value = 42;
    int ascii_value = 0;
    int counter = 0;
    int length = 0;
    int positioncounter = 1;
    length = strlen(w_word);
    length--;
    while(counter<length)
    {
        word = w_word[counter];
        ascii_value = word;
        ascii_value = ascii_value * positioncounter;
        hash_value = hash_value + ascii_value;
        counter++;
        positioncounter++;
    }

    return hash_value;
}
