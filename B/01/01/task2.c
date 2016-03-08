#include <stdio.h>
#include <string.h>

typedef struct{
	int counter_struct;
	int hash;
} occurance_t;

	static long sum=42;

long hash(char *word,int *counter);

int main()
{
    occurance_t duma[3000];

    char word[200];
    int lenght,counter=0,count=0,helper;
    long result;

    for (count=0;count<3000;count++){
        duma[count].counter_struct = 1;
    }

    for (count=0;count<3000;count++){
    scanf("%s", word);
    if (word[0]== 'v' && word[1]== 's' && word[2]== 'm' && word[3]== 'i' && word[4]== 's' && word[5]== 'a' && word[6]== 'l') break;

    lenght=strlen(word);
    result = 0;
    for(counter=0;counter<lenght;counter++){
    	result = hash(&word[counter], &counter);
    }
    duma[count].hash = result;
    if (count > 0){
    for(counter=0;counter<count;counter++){
        if (duma[counter].hash == duma[count].hash) duma[count].counter_struct++;
    }}
    sum = 42;
    }

    result = duma[0].counter_struct;
    for (count=0;count<3000;count++){
        if (duma[count].counter_struct > result){
            helper = count;
         result = duma[count].counter_struct;
    }}

    printf("%d %d",result,duma[helper].hash);

    return 0;
}

long hash(char *word,int *counter){
    int counter2=0;
    char ascii;

            for(;counter2<=255;counter2++){
                    ascii = counter2;
                if (ascii == *word) {
                    sum += counter2*(*counter+1);
                }
    }
    return sum;
}
