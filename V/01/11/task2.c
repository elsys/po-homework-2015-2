#include <stdio.h>
#include <string.h>
long hash(char *word)
{
	long number=42;
	int i;
	for(i=0;i<=strlen(word)-1;i++){	
		number+=(i+1)*word[i];
	}
	return number;	
}

struct occurance_t{
	long number;
	int j;
};

int main(){
	struct occurance_t p[3000];
	char duma[200];
	int i=0,k,max=1,n=0;
	do{
		scanf("%s",duma);
		p[i].number=hash(duma);
		p[i].j=1;
	for(k=0;k<i;k++){
		if(p[k].number==p[i].number){
			p[i].j++;
		}
	}
	i++;
	}while(strcmp(duma, "vsmisal") != 0);
	for(k=0;k<i;k++){
		if(p[k].j > max){
			max=p[k].j;
			n=k;
		}
	}
	printf("%d %ld", p[n].j, p[n].number);
	return 0; 
}
