#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct occurance_t{

    int hash[3000];
    int counter[3000];

};
int main()
{

    struct occurance_t var;

    char word[200];
    char exception[] = "vsmisal";

    int i,k,length;

    int hash = 42;

    int helper,helper_one,max;

    for(i = 0;i < 3000;i++){
        var.counter[i] = 0;
    }


        i = 0;

        while(1){
        scanf("%s",word);

        if(strcmp(word,exception) == 0){
            break;
        }

        length = strlen(word);

        for(k = 0;k < length; k++){

            hash = hash + ((int) word[k]) * (k + 1);

        }

        var.hash[i] = hash;

        hash = 42;

        i++;
    }

    helper = i;

    for(i = 0; i < helper;i++){

        for(k = 0;k < helper;k++){

            if(var.hash[i] == var.hash[k]){
                var.counter[i]++;
            }

        }
    }


    max = 0;

    for(i = 0;i < helper; i++){
        if(var.counter[i] > max){
            max = var.counter[i];
            helper_one = i;
        }
    }

    printf("%d %d",max,var.hash[helper_one]);

    return 0;
}
