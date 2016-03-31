#include <stdio.h>

void minmax (int n,int *arr);

int main ()
{
int n,i=0;
int arr[500];

scanf("%d",&n);
	

while (i<n){
	scanf ("%d",&arr[i]);
	i++;
}

minmax (n,arr);

return 0;

}

void minmax (int n,int *arr){
	int k=0,sum,min=arr[0],max=arr[0];

	while (k<n){
		if(min>arr[k]){
			min=arr[k];
		}
		if(max<arr[k]){
			max=arr[k];
		}
		k++;
	}
	sum=min+max;
	printf ("%d\n",sum);
}