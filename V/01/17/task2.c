#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct occurance_t{

    int hash[3000];
    int counter[3000];
}v;
int main()
{
    char word[200];
    char exception[] = "vsmisal";

    int n, l, i = 0, hash = 42;
    int helper,h_one,max;

    for(i = 0;i < 3000;i++){
        v.counter[i] = 0;
    }
        i = 0;
        while(1){
        	scanf("%s",word);
        	if(strcmp(word,exception) == 0){
            	break;
        	}
        l = strlen(word);
        
        for(n = 0; n < l; n++){
            hash = hash + ((int) word[n]) * (n + 1);
        }
        v.hash[i] = hash;
        hash = 42;
        i++;
    	}
    helper = i;

    for(i = 0; i < helper;i++){
        for(n = 0;n < helper;n++){
            if(v.hash[i] == v.hash[n]){
                v.counter[i]++;
            }
        }
    }
    max = 0;
    
    for(i = 0;i < helper; i++){
        if(v.counter[i] > max){
            max = v.counter[i];
            h_one = i;
        }
    }

    printf("%d %d",max,v.hash[h_one]);

    return 0;
}
