#include <stdio.h>
#include <string.h>

void breakdown(char*, long long*);
void process(long long*);
int is_isbn(long long []);

int main() {
	long long isbn[5] = {0};
	char arr[20] = {0};
	scanf("%s", arr);
	if(strlen(arr) == 17)
		breakdown(arr, isbn);
	else {
		printf("0");
		return 0;
	}
	process(isbn);
	return 0;
}

int is_isbn(long long cpy[])
{
        int i, sum = 0;
        long long num[5] = {0};

        for (i = 0; i < 4; i++) {
        	num[i] = cpy[i];
        	int is_even = 0;
            while(num[i] != 0) {
            	sum += num[i]%10 * ((is_even == 0) ? 1 : 3);
            	if(is_even == 1)
            		is_even = 0;
            	else
            		is_even = 1;
            	num[i]/=10;
            }
        }
        return (((10 - sum%10) == num[4]) ? 0 : 1);
}


void process(long long* num) {
	if(num[0] == 978 || num[0] == 979) {
		printf("%d", is_isbn(num));
			switch(num[2]) {
				case 933346:
					printf("\nBluebridge");
				break;
				case 55583:
					printf("\nAlyson Books");
				break;
				case 4210:
					printf("\nFUNimation Productions, Ltd.");
				break;
				case 01:
					printf("\nPyramid Books");
				break;
			}
	}
	else {
		printf("0");
	}
}

void breakdown(char* string, long long* num) {
	unsigned int num_pos = 0;
	for(int i = 0; i < strlen(string); i++) {
		if(string[i] == '-') {
			num_pos++;
			continue;
		}
		num[num_pos] = num[num_pos]*10 + (string[i]-48);
	}

}