#include <stdio.h>
#include <string.h>
#define MAX 3000

long hash(char*);

struct occurance_t{
    int occur;
    long hash;
};

int main(){
    struct occurance_t words[MAX];
    struct occurance_t Common;
    char word[201];
    int i, temp;

    for(i = 0; i < MAX; i++){
        words[i].occur = 0;
        words[i].hash = 0;
    }

    Common.occur = 0;
    Common.hash = 0;

    do{
        scanf("%s", word);
        temp = hash(word);

        for(i = 0; i < MAX; i++){

            if(words[i].hash == 0){

                words[i].occur++ ;
                words[i].hash = temp;
                break;
            }

            else{
                if(words[i].hash == temp){

                    words[i].occur++;
                    break;
                }
            }
        }

    }while( strcmp(word, "vsmisal") != 0);

    for(i = 0; words[i].hash > 0; i++){

		if(words[i].occur > Common.occur){

		    Common.occur = words[i].occur;
			Common.hash = words[i].hash;
        }
	}

	printf("%d %li", Common.occur, Common.hash);


    return 0;
}

long hash(char *word){
    int i, length, sum = 42;

    length = strlen(word);

    for(i = 0; i < length; i++){

         sum += word[i] * (i+1);
    }

 return sum;
}
