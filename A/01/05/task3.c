#include<stdio.h>
#include<string.h>
struct occurance_t{
    int number;
    long hash;
    int occ;
    char words[4][200];
 
};
long hash(char *word)
{   int counter=0,lenght;
    long res=42;
    lenght=strlen(word);
    for(counter=0;counter<lenght-1;counter++)
    {
        res=res+word[counter]*(counter+1);
    }
    return res;
}
int main()
{
    int counter_1=0,counter_s=0,counter_2=0,counter_3=0,suv,inp_suv,checkmate=0,sorting=0;
    long res=0;
    char input[200];
    struct occurance_t occurances[3000];
    struct occurance_t tmp;
    while(checkmate!=1 && counter_1<3000)
    {
        fgets(input,200,stdin);
        res=hash(input);
        suv=0;
       
        for(counter_2=0;counter_2<counter_1;counter_2++)
        {
            if(occurances[counter_2].hash==res)
            {
                occurances[counter_2].occ++;
                suv=1;
                inp_suv=0;
                counter_3=0;
               while(counter_3<occurances[counter_2].number)
               {
               
                    if(occurances[counter_2].words[counter_3]==input)
                    {
                        inp_suv=1;
                    }
                counter_3++;
                }
                if(inp_suv==0)
                {
                    strcpy(occurances[counter_2].words[occurances[counter_2].number],input);
                    occurances[counter_2].number++;
                    if(occurances[counter_2].number==4)
                    {
           
                        checkmate=1;
                    }
                }
            }              
    }
 
        if(suv==0)
        {
            occurances[counter_1].hash=res;
            occurances[counter_1].occ=1;
            strcpy(occurances[counter_1].words[0],input);
            occurances[counter_1].number=1;
            counter_1++;
        }
 
    }
    counter_2=0;
    do
    {
        sorting=1;
    for(counter_s=0;counter_s<counter_1;counter_s++)
    {
        for(counter_2=0;counter_2<counter_s;counter_2++)
            {
                if(occurances[counter_2].hash>occurances[counter_2+1].hash)
                    {
                        tmp=occurances[counter_2];
                        occurances[counter_2]=occurances[counter_2+1];
                        occurances[counter_2+1]=tmp;
                        sorting=0;
                    }
           }
    }
       
    }while(sorting!=1);
    counter_s=0;
    counter_2=0;
    while(counter_2<counter_1)
    {
        counter_3=0;
        if(occurances[counter_2].occ>1)
        {
        printf("\n%ld",occurances[counter_2].hash);
            while(counter_3<occurances[counter_2].number)
             { 
            while(occurances[counter_2].words[counter_s]!=occurances[counter_2].words[counter_3-1] && counter_s<counter_3)
                    {printf("%s",occurances[counter_2].words[counter_3]);
                counter_s++;}
                counter_3++;
             }
        }
    counter_2++;
    }
 
  return 0;
    }
