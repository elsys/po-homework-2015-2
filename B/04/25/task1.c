#include<stdio.h>
#include<string.h>
int helper = 1;
void first_check(char*);
void second_check(char*);
void publishing_house(char*);


int main (){
	char ISBN13[20];
	scanf("%s", ISBN13);
	first_check(ISBN13);
	second_check(ISBN13);
	printf("%d", helper);	
	if(helper!=0)publishing_house(ISBN13);
return 0;
}


void first_check(char *ISBN13){
	if(ISBN13[0] != '9' || ISBN13[1] != '7' || (ISBN13[2] != '8' && ISBN13[2] != '9'))
	helper = 0;
}


void second_check(char *ISBN13){
	int length=0;
	int i;
	for(i=0; i<strlen(ISBN13); i++){
		if(ISBN13[i]<='9' && ISBN13[i]>='0'){
			length++;		
		}
	}
	if(length != 13) helper = 0;

}

void publishing_house(char*ISBN13){
	int i;
	for(i=0; i<strlen(ISBN13); i++){
	if(ISBN13[i]=='6'&& ISBN13[i-1]=='4' && ISBN13[i-2]=='3'&& ISBN13[i-3]=='3' && ISBN13[i-4]=='3'&& ISBN13[i-5]=='9')	
	printf("\nBluebridge");
	if(ISBN13[i]=='3'&& ISBN13[i-1]=='8' && ISBN13[i-2]=='5'&& ISBN13[i-3]=='5' && ISBN13[i-4]=='5') 
	printf("\nAlyson Books");
	if(ISBN13[i]=='0'&& ISBN13[i-1]=='1' && ISBN13[i-2]=='2'&& ISBN13[i-3]=='4') 
	printf("\nFUNimation Productions, Ltd.");	
	if(ISBN13[i]=='1'&& ISBN13[i-1]=='0') 
	printf("\nPyramid Books");
  }
}
