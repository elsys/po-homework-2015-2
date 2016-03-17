#include <stdio.h>
#include <string.h>


struct occurance_t{
	long hash;
	int times;
};

long hash(char word[]);

int main(){
	int cnt = 0,flag = 1;
	int max_times = 1,max_id = 0;
	char current_input[200] = {0};
	char endl[7]="vsmisal";
	struct occurance_t words[3000];
	while(1){
		flag = 1;
		scanf("%s",current_input);
		if(!strcmp(endl,current_input)){
			break;
		}
		for(int i = 0; i < cnt ; i++){
			if(hash(current_input) == words[i].hash){
				words[i].times++;
				flag = 0;
				if(max_times < words[i].times){
					max_id = i;
				}
			}
		}
		if(flag){
			words[cnt].hash = hash(current_input);
			words[cnt].times++;
			cnt++;
		}

	}
	printf("%d %ld",words[max_id].times, words[max_id].hash);
	return 0;
}

long hash(char word[]){
	long result = 42;
	for(unsigned int i = 0;i < strlen(word);i++){
		result = result + (word[i] * (i + 1));
	}
	return result;
}