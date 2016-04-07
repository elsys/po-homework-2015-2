#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int twoToPow(int power);
void sortStings(char strArr[512][25], int arrLen);

int main(){
	char input[12], combinations[512][25];
	int target, sum, curCase, checker, digits[10], len, i, nextFreeSpace = 0;

	scanf("%s", input);
	scanf("%d", &target);
	len = (int)strlen(input);

	for(i = 0; i < len; i++)
		digits[i] = input[i] - '0';

	for(curCase = 0; curCase < twoToPow(len-1); curCase++){			//len if first negaive
        sum = digits[0];
		for(checker = 1, i = (len-1); checker < twoToPow(len-1); i--, checker <<= 1)	//len if first negaive
			if(checker & curCase){
				sum -= digits[i];
			}else{
				sum += digits[i];
			}

		if(sum == target){
			char temp[25];
			for(i = 0; i < 25; i++){
				temp[i] = 0;
			}

            for(checker = twoToPow(len-1), i = 0; checker>0; checker >>= 1, i++){
                if(checker & curCase){
                    temp[i] = '-';
                    i++;
                }else if(checker != twoToPow(len-1)){
                    temp[i] = '+';
                    i++;
                }
                temp[i] = digits[i/2] + '0';
            }
            temp[i] = '=';

			char tempTarget[5];
			sprintf(tempTarget, "%d", target);

			strcat(temp, tempTarget);
			strcpy(combinations[nextFreeSpace], temp);
			nextFreeSpace++;
		}
	}

	if(nextFreeSpace > 0){
		sortStings(combinations, nextFreeSpace);
		for(i = 0; i < nextFreeSpace; i++){
			printf("%s", combinations[i]);
			if(i < nextFreeSpace - 1){
				printf("\n");
			}
		}
	}else
		printf("-1");

	return 0;
}

int twoToPow(int power){
	int i, ans = 1;
	for(i = 0; i < power; i++)
		ans *= 2;

	return ans;
}

void sortStings(char strArr[512][25], int arrLen){
	int i, j;
	for(i = 0; i < arrLen-1; i++){
		for(j = 0; j < arrLen-i-1; j++){
			if(strcmp(strArr[j], strArr[j+1]) < 0){
				char temp[25];
				strcpy(temp, strArr[j]);
				strcpy(strArr[j], strArr[j+1]);
				strcpy(strArr[j+1], temp);
			}
		}
	}
}
