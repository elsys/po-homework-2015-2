#include <stdio.h>
#include <string.h>
long hash(char * );
struct occurance_t{
	int hesh;
	int times;

};
int main () {

        char word[200];
	int helper = 0, iop = 1 , poi , ktimes=0;
	int kol = 0;
	struct occurance_t ss[3000];
		
		while(1){
			scanf("%s", word);
				if(word[0] == 'v' && word[1] == 's' && word[2] == 'm' && word[3] == 'i' && word[4] == 's' && word[5] == 'a' && word[6] == 'l' )
					break;
			
			ss[helper].hesh = hash(word);
			helper++;
		}
	
	for (; kol < helper; kol++){
		if(kol == 0){ss[kol].times = 1;}
		for (;iop < helper; iop++ ){
			
			if(ss[kol].hesh == ss[iop].hesh){
				ss[kol].times++;
			}
		}
	iop = kol;

	}	
	kol=0;	
	iop = 0;
	for (; kol < helper ; kol ++){
			
		for(; iop < helper; iop++)

			if (ss[kol].times < ss[iop].times){
				ktimes = iop;

			}
		iop = kol;		

	} 

printf("%d : %d", ss[ktimes].times , ss[ktimes].hesh);

 return 0 ;
}


long hash(char *word){
	
	int hesh = 42, helper = 0;
	int size = strlen (word);
	
	while(helper < size){
		
		hesh += word[helper] * (helper + 1);
		helper ++;
		
	}

return hesh;

}
