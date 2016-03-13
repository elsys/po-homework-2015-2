#include <stdio.h>
#include <string.h>

typedef struct{
    long hash;
    int meet;
    char words[3000][200];
    int occurance;
}occurance_t;


long hash(char *);

int main()
{
    occurance_t word;
    
    char input[1000];
    long temp[3000] = {0};
    int index = 0;
    int sec_index = 0;
    int count = 0;
    int current = 0;
    
    for (index = 0; ; index++)
    {
        scanf(" %[^\n]s", input);
        
        strcpy(word.words[index], input);
        temp[index] = hash(input);
        
        count = 0;
           
        for (sec_index = 0; temp[sec_index] != 0; sec_index++)
        {
            if (temp[index] == temp[sec_index])
            {
                count++;
            }
        }   
        
        if (count == 4)
        {
            break;
        }
    }  
    
    count = sec_index;
    
    for (index = 0; index < count; index++)
    {        
        current = 0;
          
         for (sec_index = 0; sec_index < count; sec_index++)
         {
            if (temp[index] == temp[sec_index])
            {
                current++;
            }
        }
        
        if (current == 1)
        {
            temp[index] = 0;
        }      
    } 
    
    for (index = 0; index < count; index++)
    {   
        if (temp[index] != 0)
        {
            current = temp[index];
            printf("[%d] ", current);
                    
            for (sec_index = 0; sec_index < count; sec_index++)
            {
                if (current == temp[sec_index] && temp[sec_index] != 0)
                {
                    temp[sec_index] = 0;
                    printf("%s ", word.words[sec_index]);
                }
            }
            printf("\n");
        }       
    } 
    
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
    
    return result;
}
