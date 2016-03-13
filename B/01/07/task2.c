#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct occurance_t{
    int xesh[3000],sim[3000];
};
long hash(char *word);
int main (){
    int i,a,b,c=0,d;
    struct occurance_t mlg;
    char word[200],smis[8]= "vsmisal";
    for(i=0;i<3000;i++) mlg.sim[i] = 0;
    for(i=0;;i++){
        scanf("%s",word);
        if(strcmp(word,smis) == 0) break;
        mlg.xesh[i] = hash(word);
    }
    for(a=0;a<i;a++){
        for(b=0;b<i;b++){
            if(mlg.xesh[a] == mlg.xesh[b]) mlg.sim[a]++;
        }
        if(mlg.sim[a]>c) {
            c = mlg.sim[a];
            d = a;
        }
    }
    printf("%d %d", c, mlg.xesh[d]);
    return 0;
}
long hash(char *word){
    int i,end=42;
        for(i=0;i<strlen(word);i++){
        end = end + word[i]*(i+1);
    }
    return end;
}
