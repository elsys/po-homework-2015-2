#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int long_hash(char *);

int main()
{

    char word[200];

    scanf("%s",word);

    printf("%d",long_hash(word));


    return 0;
}
int long_hash(char *word){

    int length,i,answer = 42;

    length = strlen(word);

    for(i = 0;i < length; i++){

        answer = answer + ((int) word[i]) * (i + 1);

    }

    return answer;

}
