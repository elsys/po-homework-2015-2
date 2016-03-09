#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long hash(char *word);

struct occurance_t
{
    long hash;
    int num;
};

int main()
{
    int length, i, j, k;
    int max, hashofmax;
    struct occurance_t h[3000];
    char word[200];

    for(i = 0; i < 3000; i++)
    {
        scanf("%s", word);
        h[i].hash = hash(word);
        h[i].num = 1;
        if(word[0] == 'v' && word[1] == 's' && word[2] == 'm' && word[3] == 'i' && word[4] == 's' && word[5] == 'a' && word[6] == 'l')
            break;
    }
    length = i;
    for(j = 0; j < i; j++)
    {
        for(k = j + 1; k < i ; k++)
        {
            if(h[j].hash == h[k].hash)
                h[j].num = h[j].num + 1;
        }
    }
    max = h[0].num;
    hashofmax = h[0].hash;
    for(i = 1; i < length; i++)
    {
        if(max < h[i].num)
        {
            max = h[i].num;
            hashofmax = h[i].hash;
        }
    }
    printf("%d ", max);
    printf("%d", hashofmax);

}

long hash(char *word)
{
    int sum = 42, i;
    for(i = 0; i < strlen(word); i++)
    {
        sum = sum + ((i + 1)*word[i]);
    }

    return sum;
}
