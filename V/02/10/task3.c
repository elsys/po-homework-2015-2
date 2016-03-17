#include <stdio.h>
#include <string.h>

int* hop(int *elem);
int is_in_bound(int *arr, int size, int *ptr);

int main()
{
   int arr[50],h=0,i=0;
   int *ptr;
   
   
   while(scanf("%d",&arr[i]) != EOF && i<50)
      {
      i=i+1;
      }
     
     
   
  ptr=&arr[0];
  
  //printf("%d\n",*ptr);
  
  do{
  
  	if (*ptr==0)
	{
	printf("1\n");
	break;
	}
  	ptr=hop(ptr);
  	
  	h++;
	
	//printf("\n %d",*ptr);
	
	
	
	if (is_in_bound(arr,i,ptr)==0 || h>49)
	{
	
	printf("0\n");
	break;
	}
	
	//printf("\nj=%d",j);
	
	
  }while(1);
  
 
printf("%d\n",h);

return 0;
}



int * hop(int *elem)
{
elem=elem+ *elem;
return(elem);
}

int is_in_bound(int *arr, int size, int *ptr)
{
	if((ptr - arr < 0) || (ptr - arr >size))
	{
		return 0;
	}
	 
   return 1;
}
