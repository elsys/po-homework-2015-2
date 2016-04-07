#include <stdio.h>
#include <string.h>
int main ()
{
int arr[100];
char array1[100];
  char array[100];
scanf("%s",array);
scanf("%s",array1);
 int target = (array1[0]-'0') * 10 + (array1[1]-'0');
int m=0;
int charcount = 0;
for(m=0; array[m]; m++) {
    if(array[m] != ' ') {
       arr[m]=array[m]-'0';
    }
}
int sum=0;
int i=0;
	if(m == 2){
		sum = arr[0]+arr[1];
		sum = arr[0] - arr[1];
	}
if(m == 3){
		sum = arr[0]+arr[1] + arr[2];
		if(sum == target){
			printf("%d+%d+%d=%d\n",arr[0],arr[1],arr[2],sum);
		}

		sum = arr[0] - arr[1] + arr[2];
if(sum == target){
			printf("%d+%d+%d=%d\n",arr[0],arr[1],arr[2],sum);
		}

		sum = arr[0] + arr[1] -arr[2];
if(sum == target){
			printf("%d+%d-%d=%d\n",arr[0],arr[1],arr[2],sum);
		}
	sum = arr[0] - arr[1] -arr[2];
if(sum == target){
			printf("%d-%d-%d=%d\n",arr[0],arr[1],arr[2],sum);
		}


	}

if(m == 4){
		sum = arr[0]+arr[1] + arr[2]+ arr[3];
		if(sum == target){
			printf("%d+%d+%d+%d=%d\n",arr[0],arr[1],arr[2],arr[3],sum);
		}

		sum = arr[0] - arr[1] - arr[2] + arr[3];
if(sum == target){
			printf("%d-%d-%d+%d=%d\n",arr[0],arr[1],arr[2],arr[3],sum);
		}

		sum = arr[0] + arr[1] +arr[2] - arr[3];
if(sum == target){
			printf("%d+%d+%d-%d=%d\n",arr[0],arr[1],arr[2],arr[3],sum);
		}
sum = arr[0] + arr[1] - arr[2] - arr[3];
if(sum == target){
			printf("%d+%d-%d-%d=%d\n",arr[0],arr[1],arr[2],arr[3],sum);
		}

sum = arr[0] - arr[1] + arr[2] - arr[3];
if(sum == target){
		printf("%d-%d+%d-%d=%d\n",arr[0],arr[1],arr[2],arr[3],sum);
		}

	}

if(m == 5){
		sum = arr[0]+arr[1] + arr[2]+ arr[3]+ arr[4];
		if(sum == target){
			printf("%d+%d+%d+%d+%d=%d\n",arr[0],arr[1],arr[2],arr[3],arr[4],sum);
		}

		sum = arr[0] - arr[1] - arr[2] + arr[3]+arr[4];
if(sum == target){
			printf("%d-%d-%d+%d+%d=%d\n",arr[0],arr[1],arr[2],arr[3],arr[4],sum);
		}

		sum = arr[0] + arr[1] +arr[2] + arr[3] - arr[4];
if(sum == target){
			printf("%d+%d+%d+%d-%d=%d\n",arr[0],arr[1],arr[2],arr[3],arr[4],sum);
		}
sum = arr[0] - arr[1] - arr[2] + arr[3] + arr[4];
if(sum == target){
			printf("%d-%d-%d+%d+%d=%d\n",arr[0],arr[1],arr[2],arr[3],arr[4],sum);
		}

sum = arr[0] - arr[1] + arr[2] - arr[3] + arr[4];
if(sum == target){
		printf("%d-%d+%d-%d+%d=%d\n",arr[0],arr[1],arr[2],arr[3],arr[4],sum);
		}

	}


  return 0;
}
