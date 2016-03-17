#include <stdio.h>

void minmax(int *arr,int size, int *min, int *max);

int main()
{
 int masiv[500];
 int i,sum,n,min,max;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  scanf("%d",&masiv[i]);
 }
 min=masiv[0],max=masiv[0];
 minmax(masiv,n,&min,&max);
 sum=min+max;
 printf("%d",sum);
}

void minmax(int *arr, int size, int *min,int *max)
{
 int i;
 for(i=0;i<size;i++)
 {
  if(*min > arr[i])
  {
   *min=arr[i];
  }
  if(*max<arr[i])
  {
   *max=arr[i];
  }
 }
}
