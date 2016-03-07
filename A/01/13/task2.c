#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct occurance_t
{
    int hash;
    int count;
};

int long_hash(char *word);
int get_occurance_t(struct occurance_t array[], int lenght, int hash);

int main()
{

    struct occurance_t array_of_occurance[3000];
    int  i = 0 , hash = 42, lenght = 0, max, index;
    
    char str[200], str2[200];

    strcpy(str2, "vsmisal");
    while(strcmp(str, str2) != 0)
    {
        scanf("%s", str);
        hash = long_hash(str);
        index = get_occurance_t(array_of_occurance, lenght, hash);
        if(index == -1)
        {
            array_of_occurance[lenght].count = 1;
            array_of_occurance[lenght].hash = hash;
            lenght++;
        }
        else
        {
            array_of_occurance[index].count++;
        }
    }

    max = array_of_occurance[0].count;
    hash = array_of_occurance[0].hash;
    for(i = 1; i < lenght; i++)
    {
        if(max < array_of_occurance[i].count)
        {
            max = array_of_occurance[i].count;
            hash = array_of_occurance[i].hash;

        }
    }

    printf("%d %d", max, hash );

    return 0;
}

int long_hash(char *word)
{
    int i = 1, temp = 42, p;

    while(*word != '\0')
    {
        p = *word * i;
        temp = p + temp;

        word++;
        i++;
    }

    return temp;
}

int get_occurance_t(struct occurance_t array[], int lenght, int hash)
{
    int i;
    for(i = 0; i < lenght; i++)
    {
        if(array[i].hash == hash) {
            return i;
        }
     }

     return -1;
}

