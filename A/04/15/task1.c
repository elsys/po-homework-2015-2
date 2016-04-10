#include <stdio.h>
#include <string.h>

struct publisher_t{
	char publisher[40];
	char publisherNumber[10];
};
struct isbn_t{
	char prefix[4];
	char registration_group[2];
	char publisher[10];
	char publicationElement[10];
	int checksum;
};

int strToInt(char *string);
int calculateSum(struct isbn_t isbn);

int main(){
	int i=0;
	char *curtoken, isbnstr[20];
	struct isbn_t isbn;
	struct publisher_t publishers[4]={{"Bluebridge", "933346"}, {"Alyson Books", "55583"}, {"FUNimation Productions, Ltd.", "4210"}, {"Pyramid Books", "01"}};
	scanf("%s", isbnstr);
	
	if(strlen(isbnstr)!=17){
		printf("0");
		return 0;
	}
	
	for(i=0; i<17; i++){
		if((isbnstr[i]<'0' || isbnstr[i]>'9') && isbnstr[i]!='-'){
			printf("0");
			return 0;
		}
	}
	
	i=0;
	curtoken=strtok(isbnstr, "-");
	while(curtoken!=NULL)
	{
		switch(i){
			case 0:
			strcpy(isbn.prefix,curtoken);
			break;
			case 1:
			strcpy(isbn.registration_group,curtoken);
			break;
			case 2:
			strcpy(isbn.publisher,curtoken);
			break;
			case 3:
			strcpy(isbn.publicationElement,curtoken);
			break;
			case 4:
			isbn.checksum=strToInt(curtoken);
			break;
			
		}
		i++;
		curtoken=strtok(NULL, "-");
	}
	if(strcmp(isbn.prefix, "978")!=0 && strcmp(isbn.prefix, "979")!=0){
		printf("0");
		return 0;
	}
	if(isbn.checksum!=calculateSum(isbn)){
		printf("0");
		return 0;
	}
	else{
		printf("1");
		for(i=0; i<4; i++){
			if(strcmp(isbn.publisher, publishers[i].publisherNumber)==0){
				printf("\n%s", publishers[i].publisher);
				break;
			}
		}
	}
	return 0;
}

int strToInt(char *string){
	int i, mult=1, result=0;
	for(i=strlen(string)-1; i>=0; i--){
		if(string[i]<'0' || string[i] > '9'){
			return -1;
		}
		result+=mult*(string[i]-'0');
		mult*=10;
	}
	return result;
}

int calculateSum(struct isbn_t isbn){
	int result=0, i, l, even=0;
	for(i=0; i<5; i++){
		switch(i){
			case 0:
			for(l=0; l<strlen(isbn.prefix); l++){
				if(even==0){
					result+=(isbn.prefix[l]-'0');
					even=1;
				}
				else{
					result+=3*(isbn.prefix[l]-'0');
					even=0;
				}
			}
			break;
			case 1:
			for(l=0; l<strlen(isbn.registration_group); l++){
				if(even==0){
					result+=(isbn.registration_group[l]-'0');
					even=1;
				}
				else{
					result+=3*(isbn.registration_group[l]-'0');
					even=0;
				}
			}
			break;
			case 2:
			for(l=0; l<strlen(isbn.publisher); l++){
				if(even==0){
					result+=(isbn.publisher[l]-'0');
					even=1;
				}
				else{
					result+=3*(isbn.publisher[l]-'0');
					even=0;
				}
			}
			break;
			case 3:
			for(l=0; l<strlen(isbn.publicationElement); l++){
				if(even==0){
					result+=(isbn.publicationElement[l]-'0');
					even=1;
				}
				else{
					result+=3*(isbn.publicationElement[l]-'0');
					even=0;
				}
			}
			break;
		}
		//printf("\n%d", result);
	}
	result=10-(result%10);
	if(result==10){
		result = 0;
	}
	return result;
}
