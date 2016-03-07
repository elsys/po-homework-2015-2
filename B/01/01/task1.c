#include <stdio.h>
#include <string.h>

long hash(char *word,int *counter);

int main()
{
    char word[200];
    int lenght,counter=0,result;

    scanf("%s", word);

    lenght=strlen(word);

    for(counter=0;counter<lenght;counter++){
    	result = hash(&word[counter], &counter);
    }
	printf("%d", result);
    return 0;
}

long hash(char *word,int *counter){
    int counter2=0;
	static int sum=42;
    char ascii;

            for(;counter2<=255;counter2++){
                    ascii = counter2;
                if (ascii == *word) {
                    sum += counter2*(*counter+1);
                }
    }
    return sum;
}
