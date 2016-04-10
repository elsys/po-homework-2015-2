#include <stdio.h>
#include <string.h>

struct ISBN13
{
	char ISBN[20];
	int EAN, group, publisher, title, checksum, len;
};

int check_EAN(int EAN);
int check_checksum(struct ISBN13 *ISBN);
int check_len(struct ISBN13 *ISBN);
void publisher_print(int publisher);

int main()
{
	struct ISBN13 isbn;
	fgets(isbn.ISBN , 20 , stdin);
	sscanf(isbn.ISBN,"%d-%d-%d-%d-%d",&isbn.EAN,&isbn.group,&isbn.publisher,&isbn.title,&isbn.checksum);

	if( check_EAN(isbn.EAN) == 1 && check_checksum(&isbn) == 1 && check_len(&isbn) == 1 )
		{
			printf("1");
			publisher_print(isbn.publisher);
		}
	else printf("0");

	return 0;
}

int check_EAN(int EAN)
{
	if(EAN == 978 || EAN == 979) return 1;
	else return 0;
}

int check_checksum(struct ISBN13 *ISBN)
{
	int check = 0, x = 1, l = strlen(ISBN->ISBN), count = 0, chk = ISBN->checksum;
	for(int i=0; i<l && count < 12 ;i++)
	{
		while((ISBN->ISBN[i]-'0') < 0 || (ISBN->ISBN[i]-'0') > 9) i++;
		count ++;
		check += (ISBN->ISBN[i]-'0')*x;
		if(x==1) x = 3;
		else if(x==3) x = 1;
	}

	if(chk == 10-(check%10)) return 1;
	else return 0;
}

int check_len(struct ISBN13 *ISBN)
{
	int len = 0, l = strlen(ISBN->ISBN);
	for(int i=0; i<l ;i++)
	{
		if((ISBN->ISBN[i]-'0') >= -1 && (ISBN->ISBN[i]-'0') < 10) len ++;
	}
	if(len == 13) return 1;
	else return 0;
}

void publisher_print(int publisher)
{
	switch(publisher)
	{
		case 933346: { printf("\nBluebridge"); break; } 
		case 55583: { printf("\nAlyson Books"); break; }
		case 4210: { printf("\nFUNimation Productions, Ltd."); break; }
		case 01: { printf("\nPyramid Books"); break; }
	}
}
