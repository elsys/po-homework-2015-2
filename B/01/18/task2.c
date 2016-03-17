#include <stdio.h>
#include <string.h>

#define MAX 1000000

typedef struct{
    long hash;
    int meet;
    long temp[3001];
}occurance_t;

occurance_t last = {0, 0, {0}};

void get_word(char *);
long hash(char *);
void make_record(long);
void hash_checker();

int main()
{    
    char input[3000];
    char str[MAX];
    char *stop = "vsmisal";
    
    do{
        fgets(input, 3000, stdin);
        strcat(str, input);
    }while (!strstr(input, stop));
    
    get_word(str);
    
    hash_checker();
    
    printf("%d %ld", last.meet, last.hash);
  
    return 0;
}


long hash(char *word)
{
    int index = 0;
    int result = 42;
    int length = 0;
    
    length = strlen(word);
    
    for (index = 0; index < length; index++)
    {  
        result += (index + 1) * word[index]; 
    }
    
    make_record(result);
    
    return result;
}

void get_word(char *word)
{ 
    int index = 0;
    int sec_index = 0;
    int length = 0;
    
    length = strlen(word) - 7;
    
    for (index = 0, sec_index = 1; sec_index < length; sec_index++)
    {
        if (word[sec_index] == ' ')
        {
            hash(strndup(word + index, sec_index - index));
            
            index = sec_index + 1;
        }
    }
}

void make_record(long sum)
{   
    int index = 0;
    
    while (1)
    {     
        if (last.temp[index] == 0)
        {
            last.temp[index] = sum;
            break;
        }    
        index++;
    }
}

void hash_checker()
{
    int index = 0;
    int sec_index = 0;
    int count = 1;

    last.meet = count;
    last.hash = last.temp[0];
    for (index = 0; last.temp[index] != 0; index++)
    {
        count = 1;
        
        for (sec_index = 1; last.temp[sec_index] != 0; sec_index++)
        {
            if (last.temp[index] == last.temp[sec_index])
            {
                count++;
            }
        }   
        
        if (last.meet < count)
        {
            last.meet = count;
            last.hash = last.temp[index];
        }
    }
    
}
