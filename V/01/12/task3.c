#include <stdio.h>
#include <string.h>


struct occurance_t{
	long hash;
	int times;
	char same_hash[4][200];
};

long hash(char word[]);

int main(){
	int cnt = 0,flag = 1,i,position = 0;
	char current_input[200];
	struct occurance_t words[3000];
	// printf("%ld\n",words[0].hash );
	for(i = 0; i < 3000; i++){
		flag = 1;
		scanf("%s",current_input);
		for(int i = 0; i < cnt ; i++){
			// printf("%ld == %ld\n",hash(current_input),words[i].hash );
			if(hash(current_input) == words[i].hash){
				// strcpy(words[i].same_hash[words[i].times][0],current_input);
				// printf("%d(0.0)\n",i);
				for(unsigned int k = 0; k < strlen(current_input);k++){
					words[i].same_hash[words[i].times][k] = current_input[k];
				}
				// printf("%s , %d\n",cu );
				words[i].times++;
				if(words[i].times == 4){
					goto Finish; //znam che e kofti ama ne mojah da izmislq drugo
				}
				flag = 0;
			}
		}
		if(flag){
			position++;
			// printf("%d -_-\n",i );
			words[i].hash = hash(current_input);
			for(unsigned int k = 0; k < strlen(current_input);k++){
				words[i].same_hash[words[i].times][k] = current_input[k];
			}
			// strcpy(words[i].same_hash[words[i].times],current_input);
			words[i].times++;
		}
		cnt++;
	}
	Finish:
	for (int j = 0; j < i; ++j){
		for (int k = j; k < i; ++k){
			if(words[j].hash > words[k].hash){
				struct occurance_t swap = words[k];
				words[k] = words[j];
				words[i] = swap;
			}
		}
	}
	for(int k = 0; k < position;k++){
		if(words[k].times > 1){
			printf("[%ld] ",words[k].hash);
			for(int j = 0; j < words[k].times;j++){
				for(unsigned int p = 0; p < strlen(words[k].same_hash[j]);p++){
					printf("%c",words[k].same_hash[j][p]);
				}
				printf(" ");
			}
			printf("\n");	
		}
	}
	//printf("%d %ld",words[max_id].times, words[max_id].hash);
	return 0;
}

long hash(char word[]){
	long result = 42;
	for(unsigned int i = 0;i < strlen(word);i++){
		result = result + (word[i] * (i + 1));
	}
	return result;
}