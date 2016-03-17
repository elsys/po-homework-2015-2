#include<stdio.h>

void minmax(int *arr, int size, int *min, int *max)
{ int i;

for(i=0;i<size;i++)
{ if(*(arr+i) >*max)
{*max=*(arr+i);}
if(*(arr+i)<*min)
{*min=*(arr+i);}
}
}
int main()
{ int min,max,a,l,sum,i=0;
int arr[500];
scanf("%d",&a);
while(i<a)
{scanf("%d",&arr[l++]);i++;}
min=arr[0];max=arr[0];
minmax(arr,l,&min,&max);
sum=min+max;
printf("%d",sum);
return 0;
}

