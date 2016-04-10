#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ()
{
int arr[100];
char array1[100];
  char array[100];
scanf("%s",array);
scanf("%s",array1);
int target = atoi(array1);
int m=0;


for(m=0; array[m]; m++) {
    if(array[m] != ' ') {
       arr[m]=array[m]-'0';
    }
}
int sum=0;
int flag=0;
	if(m == 2){
		sum = arr[0]+arr[1];
		sum = arr[0] - arr[1];
if(flag == 0 ){
			printf("-1\n");
		}

	}
if(m == 3){
		sum = arr[0]+arr[1] + arr[2];
		if(sum == target){
			printf("%d+%d+%d=%d\n",arr[0],arr[1],arr[2],sum);
			flag=1;		
	}

		sum = arr[0] - arr[1] + arr[2];
if(sum == target){
			printf("%d+%d+%d=%d\n",arr[0],arr[1],arr[2],sum);
			flag=1;
		}

		sum = arr[0] + arr[1] -arr[2];
if(sum == target){
			printf("%d+%d-%d=%d\n",arr[0],arr[1],arr[2],sum);
flag=1;
		}
	sum = arr[0] - arr[1] -arr[2];
if(sum == target){
			printf("%d-%d-%d=%d\n",arr[0],arr[1],arr[2],sum);
flag=1;
		}
if(flag == 0){
			printf("-1\n");
		}



	}

if(m == 4){
		sum = arr[0]+arr[1] + arr[2]+ arr[3];
		if(sum == target){
			printf("%d+%d+%d+%d=%d\n",arr[0],arr[1],arr[2],arr[3],sum);
flag=1;
		}

		sum = arr[0] - arr[1] - arr[2] + arr[3];
if(sum == target){
flag=1;
			printf("%d-%d-%d+%d=%d\n",arr[0],arr[1],arr[2],arr[3],sum);
		}

		sum = arr[0] + arr[1] +arr[2] - arr[3];
if(sum == target){
flag=1;
			printf("%d+%d+%d-%d=%d\n",arr[0],arr[1],arr[2],arr[3],sum);
		}
sum = arr[0] + arr[1] - arr[2] - arr[3];
if(sum == target){
flag=1;
			printf("%d+%d-%d-%d=%d\n",arr[0],arr[1],arr[2],arr[3],sum);
		}

sum = arr[0] - arr[1] + arr[2] - arr[3];
if(sum == target){
flag=1;
		printf("%d-%d+%d-%d=%d\n",arr[0],arr[1],arr[2],arr[3],sum);
		}
if(flag ==0 ){
			printf("-1\n");
		}


	}

if(m == 5){
		sum = arr[0]+arr[1] + arr[2]+ arr[3]+ arr[4];
		if(sum == target){
flag=1;
			printf("%d+%d+%d+%d+%d=%d\n",arr[0],arr[1],arr[2],arr[3],arr[4],sum);
		}

		sum = arr[0] + arr[1] - arr[2] + arr[3]+arr[4];
if(sum == target){
flag=1;
			printf("%d-%d-%d+%d+%d=%d\n",arr[0],arr[1],arr[2],arr[3],arr[4],sum);
		}

		sum = arr[0] + arr[1] +arr[2] + arr[3] - arr[4];
if(sum == target){
flag=1;
			printf("%d+%d+%d+%d-%d=%d\n",arr[0],arr[1],arr[2],arr[3],arr[4],sum);
		}
sum = arr[0] - arr[1] - arr[2] + arr[3] + arr[4];
if(sum == target){
flag=1;
			printf("%d-%d-%d+%d+%d=%d\n",arr[0],arr[1],arr[2],arr[3],arr[4],sum);
		}
sum = arr[0] - arr[1] + arr[2] - arr[3] + arr[4];
if(sum == target){
flag=1;
		printf("%d-%d+%d-%d+%d=%d\n",arr[0],arr[1],arr[2],arr[3],arr[4],sum);
		}
		if(flag == 0){
			printf("-1\n");
		}

	}


  return 0;
}
