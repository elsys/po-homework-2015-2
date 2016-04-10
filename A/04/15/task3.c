#include <stdio.h>
#include <string.h>
//ravioli ravioli whats in the codeoli
struct sequence_t{
	int digit;
	int plus;
};
struct output_t{
	char string[27];
};


struct output_t printCurrent(struct sequence_t sequence[10], int temp, int len, int result);
int sum(struct sequence_t sequence[10], int len, int temp);

int main(){
	struct sequence_t sequence[10];
	struct output_t outputs[512]={{{0}}};
	int result, j, i, l, count=0, len, dupe;
	char input[11]={0}, temp[27];
	scanf("%s", input);
	for(i=0; i<10; i++){
		if(input[i]==0){
			sequence[i-1].plus=-1;
			break;
		}
		if(input[i]>='0' && input[i]<='9'){
			sequence[i].digit=(input[i]-'0');
			sequence[i].plus=1;
		}
		else{
			return 0;
		}
	}
	len=i;
	scanf("%d", &result);
	if(sum(sequence, len, -1)==result){
		printCurrent(sequence, -1, len, result);
	}
	for(i=0; i<len; i++){
		for(l=i; l<len; l++){
			if(sum(sequence, len, l)==result){
				dupe=0;
				outputs[count] = printCurrent(sequence, l, len, result);
				for(j=0; j<count; j++){
					if(strcmp(outputs[j].string, outputs[count].string)==0){
						dupe=1;
						break;
					}
				}
				if(dupe==0){
					count++;
				}
			}
		}
		sequence[i].plus=0;
	}
	if(count==0){
		printf("-1");
		return 0;
	}
	if(count>1){
		for (i = 0 ; i < ( count - 1 ); i++)
		{
			for (l = 0 ; l < count - i - 1; l++)
			{
				if(strcmp(outputs[l].string, outputs[l+1].string)<0) /* For decreasing order use < */
				{
					strcpy(temp,outputs[l].string);
					strcpy(outputs[l].string, outputs[l+1].string);
					strcpy(outputs[l+1].string, temp);
				}
			}
		}
	}
	for(i=0;i<count;i++){
		printf("%s\n", outputs[i].string);
	}
	return 0;
}

struct output_t printCurrent(struct sequence_t sequence[10], int temp, int len, int result){
	int i;
	struct output_t out={{0}};
	char c[2], end[10];
	for(i=0;i<len;){
		sprintf(c, "%d", sequence[i].digit);
		strcat(out.string, c);
		if(i!=len-1){
			if(sequence[i].plus==1 && i!=temp){
				strcat(out.string, "+");
			}
			else{
				strcat(out.string, "-");
			}
		}
		i++;
	}
	sprintf(end, "=%d", result);
	strcat(out.string, end);
	//printf("%s\n", out.string);
	return out;
}
int sum(struct sequence_t sequence[10], int len, int temp){
	int i, result=sequence[0].digit;
	//printf("\n---------- \nSTART OF SUM\n");
	//printf("%d %d", sequence[0].digit, result);
	for(i=1; i<len; i++){
		if(sequence[i-1].plus==1 && (i-1)!=temp){
			result+=sequence[i].digit;
		}
		else{
			result-=sequence[i].digit;
		}
		//printf("\n%d %d %d %d", temp, i-1, sequence[i].digit, result);
	}
	
	return result;
}
