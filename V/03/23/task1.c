#include <stdio.h>
#include <string.h>



int main() {

	int result = 0;
	char egn[12] = {0};
	scanf("%s", egn);

	if(strlen(egn) == 10) {
			for(int i = 0; i < 10; i++)
				egn[i] -= '0';

			int month = egn[3] + egn[2]*10;
			if( (month >= 1 && month <= 12) || (month >= 21 && month <= 33) || (month >= 41 && month <= 53)) {
				result = 1; 
			}
			else {
				result = 0;
			}

			int tmp = 0;
			int tmps[9] = {2, 4, 8, 5, 10, 9, 7, 3, 6};
			for(int i = 0; i < 10; i++) {
				tmp += egn[i]*tmps[i];
			}
			tmp %= 11;
			if(tmp == 10)
				tmp = 0;
			if(tmp == egn[9]) {
			}
			else {
				result = 0;
			}

	}
	else {
		printf("0");
		return 0;
	}

	printf("%d", result);
	return 0;
}