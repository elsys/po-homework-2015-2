#include <stdio.h>
#include <string.h>
#define MAX 11

int main(){
	
	char input[MAX];
	int number[MAX];
	int searched;
	int plus_minus = 0;
	int output = 0;
	
	fgets(input, MAX, stdin);
	scanf("%d", &searched);
	
	for(int i = 0; i < strlen(input) - 1; i++){
		number[i] = input[i] - '0';
	}
	
	int result = number[0];
	
	while(!(plus_minus >> (strlen(input) - 2) & 1)){
		for(int i = 0; i < strlen(input) - 2; i++){
			if((plus_minus >> i) & 1){
				result -= number[i + 1];
			}
			else{
				result += number[i + 1];
			}
		}
		if(result == searched){
			output = 1;
			for(int i = 0; i < strlen(input) - 1; i++){
				printf("%d", number[i]);
				if(i < strlen(input) - 2){
					if((plus_minus >> i) & 1){
						printf("-");
					}
					else{
						printf("+");
					}
				}
			}
			printf("=%d\n", searched);
		}
		result = number[0];
		plus_minus ++;
	}
	if(!output){
		printf("-1");
	}
	return 0;
}
