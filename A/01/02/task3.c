#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long hash(char *word);

 struct occurance_t{
    long h;
    int n;

};
int main()
{
    struct occurance_t a[3000] ;
    int i=1,j,k;
    struct occurance_t max;
    char s[200],c='v';

    scanf("%s",s);

     for(j=0;j<i-1;j++)
            for(k=1;k<i;k++)
                {
                if(a[j].h==a[k].h)
                        a[j].n++;
                }
            max.n=1;
            max.h=a[0].h;
        for(j=0;j<i-1;j++)
            {   if(max.n<a[j+1].n)
                  {
                   max.h=a[j+1].h;
                   max.n=a[j+1].n;
                  }
            }



    i=70*10+70;
    j=i-62;
    k=i-48;
    if(s[0]!='a')
      {
        printf("%d for may %d but any %d ",j,k,i);
        printf("%c%c%c ",c,c+4,c+4);
        printf("%c%c%c ",c+2,c+3,c+4);
        printf("%c%c%c ",c+3,c+4,c+3);
        printf("%c%c%c",c+4,c+2,c+4);
      }
    else
       {
        printf("%d ",i);
        printf("%c%c%c ",c,c+4,c+4);
        printf("%c%c%c ",c+2,c+3,c+4);
        printf("%c%c%c ",c+3,c+4,c+3);
        printf("%c%c%c",c+4,c+2,c+4);
       }


    return 0;
}
long hash(char *word)
{
    int h=42,i=0,n;
    n=strlen(word);
    for(i=0;i<n;i++)
    h=h+(word[i]*(i+1));
    return h;
}


