#include <stdio.h>
#include <string.h>

typedef struct occurance_t{

int reps;
long hash;

}occurance;

long comparing(long array[],int counter);
long hashing(char arr[]);

int main(){

    char str[200];
    int i;
    int hashes[3000] = {0};

    for(i=0; i<3000 && strcmp(str,"vsmisal") != 0;i++){

    scanf("%s",str);

    hashes[i]=hashing(str);

    }

comparing(hashes,i);

return 0;
}

long comparing(long array[], int counter){

occurance var;
var.reps=0;
var.hash=0;
int i,l=0,helper,helper2;

for(i=0;i<counter;i++){
l=i;
helper=array[i];
helper2=0;
for(l=0;l<counter;l++){

    if(helper==array[l]){
        helper2++;
        if(var.reps<helper2){var.reps=helper2;

        var.hash=helper;
        }
    }
}

}
printf("%d\n",var.reps);
printf("%d",var.hash);
}

long hashing(char arr[]){

int len = 0,i;
long eq=42;
len=strlen(arr);
for(i=0;i<len;i++){

    eq=eq+arr[i]*(i+1);

    }

return eq;
}



