#include <stdio.h>
#include <string.h>
 
struct occurance_t
{
    long h;
    int i;
};
 
long hash(char *w)
{
    long h = 42,l = strlen(w);
 
    int i = 0;
    for(;i < l; i++)
    {
        h = h + w[i] * (i+1);
    }
 
    return h;
}
 
int main()
{
    char w[200];
 
    struct occurance_t word[3000];
    long m[] = {0,0};
    int i_words = 0, i;
    scanf("%s",w);
    if(w[0]=='v'&& w[1] == 's' && w[2] == 'm'&& w[3] == 'i' && w[4] == 's' && w[5] == 'a' && w[6] == 'l' && w[7] == '\0')
    {
        return 0;
    }
   
    do
    {
        long h = hash(w);
        int p = -1;
        for(i = 0;i < i_words; i++)
        {
            if(word[i].h == h)
            {
                p = i;
                break;
            }
        }
       
        if(p == -1)
        {
            word[i_words].h = h;
            word[i_words].i = 1;
            if(m[0] < word[i_words].i)
            {
                m[0] = word[i_words].i;
                m[1] = word[i_words].h;
            }
            i_words++;
        }
        else
        {
            word[p].i++;
            if(m[0] < word[p].i)
            {
                m[0] = word[p].i;
                m[1] = word[p].h;
            }
        }
        scanf("%s",w);
    }while(!(w[0]=='v'&& w[1] == 's' && w[2] == 'm'&& w[3] == 'i' && w[4] == 's' && w[5] == 'a' && w[6] == 'l' && w[7] == '\0'));
   
    printf("%ld %ld", m[0], m[1]);
 
    return 0;
}
