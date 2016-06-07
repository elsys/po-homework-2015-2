 
 

#include <stdio.h>
#include <string.h>
#include <math.h>
int calculation( int n, int b, int opr)
{
    int sum=0;
    if(opr==1)
    {
        sum=n+b;
        
    }
    else if(opr==0)
    {
        sum=n-b;
        
    }
    return sum;
}

int main()
{
    char nums[11];
    int  a[11];
    int pp[511][9];

    int n,l=0,i,sum=0,j,k=0, max=0, current, elem, found=0;
    char oper;
    
    scanf("%s",nums);
    scanf("%d",&n);
    l=strlen(nums);
    for(i=0;i<l;i++)
    {
        a[i]=nums[i]-'0';
        
    }
    
    for(i=0;i<l-1;i++)
    {
        max = max + pow(2,i);
    }
 
    for(i=0;i<=max;i++)
    {
        current = i;
        for(j=l-2;j>=0;j--)
        {
            elem = current%2;
            current = current/2;
            pp[i][j] = elem;
        }
    }
   
    sum = a[0];
    for(i=0;i<=max;i++)
    {
        for(k=1;k<l;k++)
        {
           
            sum = calculation(sum,a[k],pp[i][k-1]);
        }
  
        if(sum==n)
        {
           found ++;
           printf("%d",a[0]);
           for(k=1;k<l;k++)
           {
               if(pp[i][k-1] == 1)
               {
                   oper = '+';
               }
               else
               {
                   oper = '-';
               }
               printf("%c",oper);
               printf("%d",a[k]);
           }
           printf("=%d\n",n);
        }
        sum = a[0];
        
    }
    
    if(found == 0)
    {
        printf("-1");
    }

return 0;
}
