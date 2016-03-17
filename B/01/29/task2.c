#include<stdio.h>
#include<string.h>

long hash(char *word);

	struct occurance_t {
	long hash;
	int counter;
	};

	int main(){
		
		struct occurance_t stats[3000];
		
		long current;
		
		int i;
		int cnt = 0;
		char word[200];
		
		for (i = 0 ;i < 3000;i++){
			stats[i].counter = 1;
			stats[i].hash = 0;
		}
		for (i = 0 ;i < 3000;i++){
		scanf("%s", word);
		
		if (i != 0)
			if (word[0] == 'v' && 
			word[1] == 's' && 
			word[2] == 'm' && 
			word[3] == 'i' && 
			word[4] == 's' && 
			word[5] == 'a' &&
			word[6] == 'l')
			{
				cnt++;
				break;
			}
			current = hash(word);
			
			stats[i].hash = current;
			cnt++;
			
			
		}
		int i2;
		for (i = 0 ;i < cnt;i++){
			for (i2 = 0 ;i2 < cnt;i2++)
			if (i2 != i)
				if (stats[i].hash == stats[i2].hash)stats[i].counter++;
		
		}
		
		int  tempcount;
		long temphash;
		
		for (i = 1 ;i < cnt;i++){
			if (stats[i].counter > stats[i-1].counter){
				temphash = stats[i].hash;
				tempcount = stats[i].counter;
			}
		
		}
		printf("%d %ld",tempcount, temphash);
		return 0;
	}
	
	long hash(char *word){
		long starter = 42;
		int index = 0, position = 1;
		for (;index < strlen(word) ; index++, position++)starter = starter + (word[index] * position);
		return starter;
	}
