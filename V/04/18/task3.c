#include <stdio.h>
#include <string.h>

int main()
{
    char s[20],s1[10][20];
    int i,sum,a,n,j,st=1,k;

    scanf("%s",s);
    scanf("%d",&a);
    n=strlen(s);
    for(i=n-1;i>0;i--)
       s[i+i]=s[i];
    for(i=0;i<n-1;i++)
        st=st*2;
    n=n+n-1;
    for(i=1;i<n-1;i=i+2)
        s[i]='+';
    for(i=0;i<n;i=i+2)
        s[i]=s[i]-'0';

for(i=1,k=0;i<st;i++)
{

    sum=s[0];
    for(j=1;j<n;j=j+2)
        if(s[j]=='+')
            sum=sum+s[j+1];
        else
            sum=sum-s[j+1];
    if(sum==a)
    {strcpy(s1[k],s);
        k++;
    }

    if(s[n-2]=='+')
        s[n-2]='-';
    else
        s[n-2]='+';

    if(i%2==0)
    {

        if(s[n-4]=='+')
            s[n-4]='-';
        else
            s[n-4]='+';
    }
     if(i%4==0)
     {
        if(s[n-6]=='+')
            s[n-6]='-';
        else
            s[n-6]='+';
     }
     if(i%8==0)
     {
        if(s[n-8]=='+')
            s[n-8]='-';
        else
            s[n-8]='+';
     }
     if(i%16==0)
       {
        if(s[n-10]=='+')
            s[n-10]='-';
        else
            s[n-10]='+';
       }
     if(i%32==0)
       {
        if(s[n-12]=='+')
            s[n-12]='-';
        else
            s[n-12]='+';
       }
     if(i%64==0)
        {
        if(s[n-14]=='+')
            s[n-14]='-';
        else
            s[n-14]='+';
        }
     if(i%128==0)
       {
        if(s[n-16]=='+')
            s[n-16]='-';
        else
            s[n-16]='+';
       }
     if(i%256==0)
       {
        if(s[n-18]=='+')
            s[n-18]='-';
        else
            s[n-18]='+';
       }
}


    if(k==0)
        printf("-1");
    for(i=k-1;i>=0;i--)
    {
     for(j=0;j<n;j++)
       if(j%2!=0)
        printf("%c",s1[i][j]);
       else
        printf("%d",s1[i][j]);
        printf("=%d\n",a);
    }
    return 0;
}
