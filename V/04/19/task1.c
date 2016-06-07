#include <stdio.h>

int countDigits(int n)
{
  int counter = 0;

  if(n == 0)
  	return 1;

  while(n!=0)
  {
      n/=10;  
      ++counter;
  }

 return counter;
}


int getDigit(int n, int num)
{
  int counter;
  int numcnt = countDigits(n) - num;

  do {
  	counter = n%10;
    n/=10;  
    numcnt--;
  } while(numcnt > 0);

 return counter;
}


int isbn_check(int nums[5]) {

	int curr = 0;
	int sum = 0;

	for(int i = 0; i < 13; i++) {
		for(int j = 0; j < countDigits(nums[curr]); j++, i++) {
			if(i%2 == 0)
				sum += getDigit(nums[curr], j)*3;
			else
				sum += getDigit(nums[curr], j);
		}
		curr++;
	}

	if(nums[4] == (10-(sum%10)))
		return 1;
	else
		return 0;

}

int main() {

	int nums[5];
	scanf("%d-%d-%d-%d-%d", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4]);

	if(!(nums[0] == 978 || nums[0] == 979)) {
		printf("0");
		return 0;
	}
	int sum = 0;
	for(int i = 0; i < 5; i++) {
		sum += countDigits(nums[i]);
	}

	if(sum == 13 && isbn_check(nums)) {
		printf("1");
		switch(nums[2]) {
			case 933346:	printf("\nBluebridge");
			break;
			case 55583:		printf("\nAlyson Books");
			break;
			case 4210: 		printf("\nFUNimation Productions, Ltd.");
			break;
			case 01: 		printf("\nPyramid Books");
		    break;

		}
	}
	else
		printf("0");


	return 0;
}