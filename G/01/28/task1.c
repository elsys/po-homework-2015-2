#include <stdio.h>

long hash(char *);
int main()
{
    char word[200];
    printf("%ld",hash(word));

    return 0;
}
long hash(char *word)
{
    long ascii_counter = 42;
    long counter = 0;
    scanf("%s",word);

    while(word[counter] != '\0')
    {
        ascii_counter = ascii_counter + (word[counter] * (counter + 1));
        counter ++;
    }
    return ascii_counter;
}
