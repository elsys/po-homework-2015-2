#include <stdio.h>
#include <string.h>
#define MAX 11

int main(){
	
	char sort[512][2*MAX] = {{-1}};
	char help[2*MAX] = {-1};
	char input[MAX];
	int searched;
	int plus_minus = 0;
	int times = 0;
	
	fgets(input, MAX, stdin);
	scanf("%d", &searched);
	
	int result = input[0] - '0';
	
	while(!(plus_minus >> (strlen(input) - 2) & 1)){
		for(int i = 0; i < strlen(input) - 2; i++){
			if((plus_minus >> i) & 1){
				result -= input[i + 1] - '0';
			}
			else{
				result += input[i + 1] - '0';
			}
		}
		if(result == searched){
			times ++;
			for(int i = 0; i < strlen(input) - 1; i++){
				sort[times][i*2] =  input[i];
				if(i < strlen(input) - 2){
					if((plus_minus >> i) & 1){
						sort[times][i*2 + 1] =  '-';
					}
					else{
						sort[times][i*2 + 1] =  '+';
					}
				}
			}
		}
		result = input[0] - '0';
		plus_minus ++;
	}
	for(int i = 0; i < times ; i++){
		for(int j = 0; j < times - j; j++){
			if(strcmp(sort[i], sort[i + 1]) < 0){
				strcpy(help, sort[i]);
				strcpy(sort[i], sort[i + 1]);
				strcpy(sort[i + 1], help);
			}
		}
	}
	for(int i = 1; i <= times ; i++){
		printf("%s=%d\n", sort[i], searched);
	}
	if(!times){
		printf("-1");
	}
	return 0;
}
