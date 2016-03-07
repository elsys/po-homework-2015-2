#include <stdio.h>
#include <string.h>
#define SIZE 200
#define MAX_WORDS 3000

typedef struct{

    long hash;
    int count;

}occurance_t;

long hash(char *word);

int main()
{

    int ctr = 0, check_ctr, max = 0, position;
    char word[SIZE];
    occurance_t words[MAX_WORDS];

    do{

        scanf("%s", word);

        if(word[0] == 'v' && word[1] == 's' && word[2] == 'm' && word[3] == 'i' && word[4] == 's' && word[5] == 'a' && word[6] == 'l') {

            break;

        }

        words[ctr].hash = hash(word);
        words[ctr].count = 1;

        for(check_ctr = 0; check_ctr < ctr; check_ctr++){

            if(words[ctr].hash == words[check_ctr].hash){

                words[ctr].count++;

            }

        }

        if(words[ctr].count > max ){

            max = words[check_ctr].count;
            position = check_ctr;

        }

    }while(ctr++ < MAX_WORDS);

    printf("%d %ld \n", words[position].count, words[position].hash);

    return 0;

}

long hash(char *word){

    int counter = 0;
    long hash_code = 42;

    while(counter++ < strlen(word)){
        
        hash_code += word[counter - 1] * (counter);
        
    }

    return hash_code;

}
