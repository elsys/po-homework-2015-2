#include<stdio.h>
#include<string.h>
 
struct occurance_t{
int hash;
int times;
};


long hash(char *word)
{
        int counter=0;
int lenght=0;
int sum=0;
int count=1;
int helper=0;

   lenght=strlen(word);

for(;counter<lenght;counter++)
{
helper=word[counter]*count;
sum=sum+helper;
count++;
}

   sum=sum+42;
return sum;
}
int main() {
   int i = 0;
   int count = 0;
   int counter = 0;
   int comman = 1;
   int helper= 0;
   char word[200];
   struct occurance_t arr[3000];
   

for(i=0;i<3000;i++)
{
scanf("%s", word);
if(word[0] == 'v' && word[1] == 's' && word[2] == 'm' && word[3] == 'i' && word[4] == 's' && word[5] == 'a' && word[6] == 'l')break;
arr[count].hash = hash(word);
  arr[count].times = 1;
    for(counter = 0; counter < count; counter++)
  {
 
    if(arr[counter].hash == arr[count].hash)
    {
      arr[count].times++;
    }
  }
 
count++;  
}
for(counter = 0; counter < count; counter++)
{
    if(arr[counter].times > comman)
{
          comman = arr[counter].times;
            helper = counter;  
                }
  
  
}
printf("%d %d ", arr[helper].times, arr[helper].hash);
return 0;
} 
