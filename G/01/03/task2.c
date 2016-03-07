 #include <stdio.h>
#include <stdlib.h>

struct occurance_t {
int hash_t;
int times ;

};
int main()
{
   char  word[2000];
    int i = 0;
    int answer = 42;
    int code =1 ;
    int mass[200];
    int ct =0 ;
int sod =1;
    struct occurance_t type1;

for(sod = 1;sod<3000;sod++ )
 {
         scanf("%s",word);

       if(word[0] == 'v' && word[1] == 's' && word[2] == 'm' && word[3] =='i'&& word[4]=='s' && word[5] == 'a' && word[6] == 'l')
        {

 answer =42;
    i =0 ;
   while(word[i] != '\0')
        {

answer = answer + (word[i] * (i + 1));
i++;
}
mass[ct] = answer;
ct ++;
break;
}
else
{
 i = 0;
 answer = 42;
   while(word[i] != '\0')
        {

answer = answer + (word[i] * (i + 1));
i++;
}

mass[ct] = answer;
ct++;

}

 }
 
 type1.times = 1;
for(i= 0 ;i<ct;i++)
{
    code = i +1;
    while(code<ct)
    {
    if(mass[i] == mass[code])
    {

        type1.hash_t = mass[code];
      type1.times ++;
     
      break;
    }

    code ++;

    }
}

printf("%d\n", type1.hash_t);
printf("%d\n", type1.times);
return 0 ;
}

