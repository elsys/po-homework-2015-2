#include <stdio.h>
#include <string.h>

typedef struct{

    long hash;
    int count;

}occurance_t;

long hash(char *word);

int main()
{

    int counter = 0, counter2, max = 0, pos;
    char word[200];
    occurance_t words[3000];

    do{

        scanf("%s", word);

        if(word[0] == 'v' && word[1] == 's' && word[2] == 'm' && word[3] == 'i' && word[4] == 's' && word[5] == 'a' && word[6] == 'l') {

            break;

        }

        words[counter].hash = hash(word);
        words[counter].count = 1;

        for(counter2 = 0; counter2 < counter; counter2++){

            if(words[counter].hash == words[counter2].hash){

                words[counter].count++;

            }

        }

        counter++;

    }while(counter < MAX_WORDS);

    for(counter2 = 0; counter2 < counter; counter2++){

        if(words[counter2].count > max ){

            max = words[counter2].count;
            pos = counter2;

        }

    }

    printf("%d %ld", words[pos].count, words[pos].hash);

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
