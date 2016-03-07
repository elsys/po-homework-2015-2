#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long hash(char *word);

 struct occurance_t{
    long h;
    int n;

};
int main()
{   struct occurance_t a[3000] ;
    int i,j,k,n=3000;
    char s[200];
    struct occurance_t max;

    for(i=0;i<n;i++)
    {scanf("%s",s);
        a[i].h=hash(s);
        a[i].n=0;

        if(s[0]=='v'&&s[1]=='s'&&s[2]=='m'&&s[3]=='i'&&s[4]=='s'&&s[5]=='a'&&s[6]=='l')
            break;
    }
        for(j=0;j<i-1;j++)
            for(k=1;k<i;k++)
                {
                if(a[j].h==a[k].h)
                        a[j].n++;
                }
            max.n=a[0].n;
        for(j=0;j<i-1;j++)
            {   if(max.n<a[j+1].n)
                  {
                   max.h=a[j+1].h;
                   max.n=a[j+1].n;
                  }
            }


    printf("%d %li",max.n,max.h);


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
