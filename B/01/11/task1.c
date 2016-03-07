#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long hash(char *word){
	int l,count=42,count1=1;
	l=strlen(word);
	int i=l;
	for(l=0;l<i;l++,count1++){
		if(word[l]=='a')count = count+97*count1;
		else if(word[l]=='b')count = count+98*count1;
		else if(word[l]=='c')count = count+99*count1;
		else if(word[l]=='d')count = count+100*count1;
		else if(word[l]=='e')count = count+101*count1;
		else if(word[l]=='f')count = count+102*count1;
		else if(word[l]=='g')count = count+103*count1;
		else if(word[l]=='h')count = count+104*count1;
		else if(word[l]=='i')count = count+105*count1;
		else if(word[l]=='j')count = count+106*count1;
		else if(word[l]=='k')count = count+107*count1;
		else if(word[l]=='l')count = count+108*count1;
		else if(word[l]=='m')count = count+109*count1;
		else if(word[l]=='n')count = count+110*count1;
		else if(word[l]=='o')count = count+111*count1;
		else if(word[l]=='p')count = count+112*count1;
		else if(word[l]=='q')count = count+113*count1;
		else if(word[l]=='r')count = count+114*count1;
		else if(word[l]=='s')count = count+115*count1;
		else if(word[l]=='t')count = count+116*count1;
		else if(word[l]=='u')count = count+117*count1;
		else if(word[l]=='v')count = count+118*count1;
		else if(word[l]=='w')count = count+119*count1;
		else if(word[l]=='x')count = count+120*count1;
		else if(word[l]=='y')count = count+121*count1;
		else if(word[l]=='z')count = count+122*count1;

	}printf("\n%d",count);
	return 0;
}

int main(){
	char word[200];
	scanf("%s",word);
	hash(&word);


	return 0;
}
