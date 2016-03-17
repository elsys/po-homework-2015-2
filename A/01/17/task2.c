#include <stdio.h>
#include <string.h>


struct occurance_t{
        long hash;
        int occurance_number;
};


long hash(char *word);

int main()
{
    char word[200];

    int i = 0,temp = 0,p = 0;

    struct occurance_t common;
    struct occurance_t words[3000];

    for(i = 0; i < 3000; i++);
    {
        words[i].hash = 0;
        words[i].occurance_number = 0;
    }

    while(p<3000)
        {
            scanf("%s",word);

            temp = hash(word);

                if(strcmp(word,"vsmisal") == 0)
                {
                    break;
                }

           for(i = 0; i < 3000; i++)
           {
               if(words[i].hash == 0)
               {
                   words[i].occurance_number = 1;

                   words[i].hash = temp;

                   break;
               }
               if(words[i].hash == temp)
               {
                   words[i].occurance_number ++;

                   break;
               }
           }

           p++;
        }
     for(i = 0; words[i].hash > 0; i++)
        {
            if(words[i].occurance_number > common.occurance_number)
                {
                    common.occurance_number = words[i].occurance_number;
                    common.hash = words[i].hash;
                }
     }

    printf("%d %ld",common.occurance_number,common.hash);

    return 0;
}

long hash(char *word)
{
        int hash = 42;
        int p = 0;
        int i;

        p = strlen(word);

        for(i = 0; i <= p; i++)
            {
                hash=hash + word[i]*(i+1);
            }

    return hash;
}


