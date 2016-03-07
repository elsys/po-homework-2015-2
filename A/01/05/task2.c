#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct occurance_t
{
    int occurances;
    long hash;
};
long hash(char *word)
{
	int i=0,lenght;
	long res=42;
    lenght=strlen(word);
        for(i=0;i<lenght-1;i++)
        {
            res=res + word[i]*(i+1);
        }
    return res;
}
int main()
{
    int i = 0,b = 0,checkmate = 1,checker = 0,suv = 0,suv_pos = 0;
    char input[200] = {0};
    struct occurance_t array[3000];
    fgets(input,200,stdin);
    checkmate = strcmp(input, "vsmisal\n");
    array[i].hash = hash(input);
    array[i].occurances = 1;
    i=1;

    do{
        fgets(input,200,stdin);
            for(;b<=i;b++)
            {
                if(hash(input) == array[b].hash)
                {
                    array[b].occurances++;
                    checker = 1;
                }
            }
            if(checker==0)
            {
                array[i].hash = hash(input);
                array[i].occurances = 1;
            }
        i++;
        b = 0;
        checker = 0;
        checkmate = strcmp(input, "vsmisal\n");
        if(i==3000)
        {
            checkmate = 0;
        }
    }while(checkmate!=0);
    b = 0;
    suv = array[b].occurances;
    suv_pos = b;
    b++;
    for(;b<i;b++){
        if(suv < array[b].occurances)
        {
            suv = array[b].occurances;
            suv_pos = b;
        }
    }
    printf("\n%d %li", array[suv_pos].occurances, array[suv_pos].hash);
    return 0;
}
