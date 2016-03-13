#include <stdio.h>
#include<string.h>


long hash(char *word);
struct occurance_t{
    long hash;
	int count;
};

int main()
{
    struct occurance_t words[3000];
    int i=0,k=0;
    char word[200];
    for (i = 0 ;i < 3000;i++){
			words[i].count = 1;
			words[i].hash = 0;
    }
    for (i = 0 ;i < 3000;i++){
        scanf("%s", word);
        if( word[0] == 'v' &&
            word[1] == 's' &&
            word[2] == 'm' &&
            word[3] == 'i' &&
            word[4] == 's' &&
            word[5] == 'a' &&
            word[6] == 'l' ){
					break;
            }

		words[i].hash = hash(word);
		k++;
    }
    int j ,c,d;
    for(i=0;i<k;i++){
        for( j=0;j<k;j++){
                if (j != i)
            if(words[j].hash==words[i].hash)
                words[i].count++;
        }
    }
    for ( c = 0 ; c < ( k - 1 ); c++)
  {
    for ( d = 0 ; d < k - c - 1; d++)
    {
     if (words[d].count < words[d+1].count){
        int swap = words[d].count;
        words[d].count  = words[d+1].count;
        words[d+1].count= swap;
        long swap1  = words[d].hash;
       words[d].hash  = words[d+1].hash;
        words[d+1].hash= swap1;
      }
    }
  }
   printf("%d %ld",words[0].count,words[0].hash);

    return 0;
}
long hash(char *word){
    int i,p;
    int hash=42;
    for(i=1,p=0;p<strlen(word);i++,p++){
        hash=hash+word[p]*i;

    }
    return hash;

}

