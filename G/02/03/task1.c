 #include <stdio.h>
#include <stdlib.h>
void minmax(int *arr, int size, int *max, int *min)
{
    int ct;
    int helper;
    int help;
 int  answer=0;
max = &arr[0];
   for(ct = 1;ct<size;ct++)
   {
	if(*max < arr[ct])
	{
	max = &arr[ct];	
	}
   }

min = &arr[0];

for(ct = 1; ct<size;ct++)
{
if(*min>arr[ct])
{
min = &arr[ct]; 
}

}
helper = *max;
help = *min;
answer  = helper+help;
printf("%d",answer);
   
}
int main()
{

    int arr[500];
    int size;
    int *min = 0;
    int *max =0;
    int i;

     do{

        scanf("%d",&size);

     }while(size<1);

    for(i=0;i<size;i++)
    {

        scanf("%d",&arr[i]);

    }

    minmax(arr,size,max,min);

    return 0;
}

