#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long hash(char *w_word);

struct occurance_t
{
    int occurances;
    long hash1;
    char h_word[3][201];
};

int main()
{
    int counter = 0;
    int counter2 = 0;
    int flag = 1;
    int flag3 = 0;
    int uniquecount = 0;
    long swap = 0;
    char swapstring[200] = {'\0'};
    char laststring[200] = {'\0'};
    int counter3 = 0;
    long temp = 0;
    long temp2 = 0;
    int maxhashpos = 0;
    char w_word[200] = {'\0'};

    struct occurance_t wordstruct[3000];
    while(counter<3000)
    {
        wordstruct[counter].hash1 = 0;
        while(counter2<4)
        {
            wordstruct[counter].h_word[counter2][0] = 0;
            counter2++;
        }
        counter++;
        counter2=0;
    }
    counter = 0;
    counter2 = 0;
    scanf("%199s", w_word);
    strtok(w_word, "\n");
    wordstruct[counter].hash1 = hash(w_word);
    wordstruct[counter].occurances = 1;
    uniquecount++;
    strcpy(wordstruct[counter].h_word[0], w_word);
    counter++;
    while(flag!=0)
    {
        scanf("%199s", w_word);
        strtok(w_word, "\n");
        while(flag3 == 0)
        {
            temp = hash(w_word);
            temp2 = wordstruct[counter2].hash1;
            if(temp == temp2)
            {
                strcpy(wordstruct[counter2].h_word[wordstruct[counter2].occurances], w_word);
                if(wordstruct[counter2].occurances == 3)
                {
                    strcpy(laststring, w_word);
                }
                wordstruct[counter2].occurances++;
                flag3 = 1;
                if(wordstruct[counter2].occurances == 4)
                {
                    flag = 0;
                }
            }
            counter2++;
            if(counter2==2999)
            {
                flag3 = 1;
            }
        }
        if(temp != temp2)
        {
            wordstruct[counter].hash1 = hash(w_word);
            wordstruct[counter].occurances = 1;
            strcpy(wordstruct[counter].h_word[0], w_word);
            uniquecount = uniquecount + 1;
        }
        counter++;
        counter2 = 0;
        if(counter==2999)
        {
            flag = 0;
        }
        flag3 = 0;
    }
    counter2 = 0;
    counter3 = 0;
    flag = 1;
    while(flag!=0)
    {
        while(counter2 < (counter - 1))
        {
            while(counter3 < (counter - counter2 - 1))
            {
                if(wordstruct[counter3].hash1 > wordstruct[counter3+1].hash1)
                {
                    swap = wordstruct[counter3].hash1;
                    wordstruct[counter3].hash1 = wordstruct[counter3+1].hash1;
                    wordstruct[counter3+1].hash1 = swap;

                    swap = wordstruct[counter3].occurances;
                    wordstruct[counter3].occurances = wordstruct[counter3+1].occurances;
                    wordstruct[counter3+1].occurances = swap;

                    strcpy(swapstring, wordstruct[counter3].h_word[0]);
                    strcpy(wordstruct[counter3].h_word[0], wordstruct[counter3+1].h_word[0]);
                    strcpy(wordstruct[counter3+1].h_word[0], swapstring);

                    strcpy(swapstring, wordstruct[counter3].h_word[1]);
                    strcpy(wordstruct[counter3].h_word[1], wordstruct[counter3+1].h_word[1]);
                    strcpy(wordstruct[counter3+1].h_word[1], swapstring);

                    strcpy(swapstring, wordstruct[counter3].h_word[2]);
                    strcpy(wordstruct[counter3].h_word[2], wordstruct[counter3+1].h_word[2]);
                    strcpy(wordstruct[counter3+1].h_word[2], swapstring);
                    
                    strcpy(swapstring, wordstruct[counter3].h_word[3]);
                    strcpy(wordstruct[counter3].h_word[3], wordstruct[counter3+1].h_word[3]);
                    strcpy(wordstruct[counter3+1].h_word[3], swapstring);
                }
                counter3++;
            }
            counter2++;
            counter3 = 0;
        }
        counter2 = 0;
        while(counter2<counter)
        {
            if(wordstruct[counter2].hash1 != 0)
            {
                printf("\n");
                printf("%li ", wordstruct[counter2].hash1);
                printf("%s ", wordstruct[counter2].h_word[0]);
                printf("%s ", wordstruct[counter2].h_word[1]);
                printf("%s ", wordstruct[counter2].h_word[2]);
                if(wordstruct[counter2].occurances==4)
                {
                    printf("%s ", laststring);
                }
                uniquecount--;
            }
            counter2++;
            if(uniquecount==0)
            {
                counter2 = counter + 1;
            }
        }
        flag = 0;
        wordstruct[maxhashpos].hash1 = 0;
        counter2 = 0;
    }
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
