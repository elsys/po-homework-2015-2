#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long hash(char *w_word);

struct occurance_t
{
    int occurances;
    long hash1;
};

int main()
{
    int counter = 0;
    int counter2 = 0;
    int flag = 1;
    int flag2 = 0;
    int maxoccurence = 0;
    int maxoccurencepos = 0;
    char w_word[200] = {0};

    struct occurance_t wordstruct[3000];

    fgets(w_word,200,stdin);
    flag = strcmp(w_word, "vsmisal\n");
    wordstruct[counter].hash1 = hash(w_word);
    wordstruct[counter].occurances = 1;
    counter++;
    while(flag!=0)
    {
        fgets(w_word,200,stdin);
        while(counter2<=counter)
        {
            if(hash(w_word) == wordstruct[counter2].hash1)
            {
                wordstruct[counter2].occurances++;
                flag2 = 1;
            }
            counter2++;
        }
        if(flag2==0)
        {
            wordstruct[counter].hash1 = hash(w_word);
            wordstruct[counter].occurances = 1;
        }
        counter++;
        counter2 = 0;
        flag2 = 0;
        flag = strcmp(w_word, "vsmisal\n");
        if(counter==3000)
        {
            flag = 0;
        }
    }
    counter2 = 0;
    maxoccurence = wordstruct[counter2].occurances;
    maxoccurencepos = counter2;
    counter2++;
    while(counter2<counter)
    {
        if(maxoccurence < wordstruct[counter2].occurances)
        {
            maxoccurence = wordstruct[counter2].occurances;
            maxoccurencepos = counter2;
        }
        counter2++;
    }
    printf("\n");
    printf("%d ", wordstruct[maxoccurencepos].occurances);
    printf("%li", wordstruct[maxoccurencepos].hash1);
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
