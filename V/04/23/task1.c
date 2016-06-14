#include <stdio.h>

int getsize(int);
int is_isbn(int[]);

int main() {
	int isbn[5];
	scanf("%d-%d-%d-%d-%d", &isbn[0], &isbn[1], &isbn[2], &isbn[3], &isbn[4]);


	int sum = 0;
	for(int i = 0; i <= 4; i++) {
		sum += getsize(isbn[i]);
	}

	if(sum != 13 && !is_isbn(isbn)) {
		printf("0");
		return 0;
	}
	
	printf("1\n");

	if(isbn[0] == 978 || isbn[1] == 979) {
		switch(isbn[2]) {
			case 1:
				printf("Pyramid Books");
	        case 4210:
	            printf("FUNimation Productions, Ltd.");
	            break;
        	case 55583:
           		printf("Alyson Books");
        	    break;
            case 933346:
            	printf("Bluebridge");
            	break;
		}
	}
	else {
		printf("0");
	}	

	return 0;
}


int getsize(int num) {
	int i = 0;

	if(num == 0)
		return 1;

	while(num != 0) {
		i++;
		num /= 10;
	}
	return i;
}

int is_isbn(int num[])
{
        int sum = 0, is_even = 0;

        for(int i = 0; i < 4; i++) {
        	int tmp = num[i];
        	while(tmp != 0){
        		sum += tmp%10 * (is_even == 1 ? 3 : 1);
        		is_even = !is_even;
        		tmp/=10;
        	}
        }
        return ((10-(sum%10) == num[4]) ? 1 : 0);
}