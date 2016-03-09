#include <stdio.h>

char text[200];

struct occurance_t
{
    int amount;
    long hash;
};
long hash(char word)
{
    long value=42;
    int len, i;
    len = strlen(text);
	for(i = 0;i<len;i++)
	{
		value=value+text[i] * (i+1);
	}
	return value;
}

int main()
{
    struct occurance_t word[3000];
    int i = 0,ii = 0,top = 0;
    for(i=0;i<3000;i++)
    {
        word[i].amount = 0;
        word[i].hash = 0;
    }
    while(1)
    {
        scanf("%s", text);
        if(text[0] == 'v' && text[1] == 's' && text[2] == 'm' && text[3] == 'i' && text[4] == 's' && text[5] == 'a' && text[6] == 'l' ) break;
        word[i].hash = hash(text);
        for(ii=0;word[ii].hash != 0;ii++)
        {
            if(word[i].hash == word[ii].hash) word[i].amount++;
        }
        i++;
    }
    for(i=0;word[i].hash != 0;i++)
    {
        if(word[i].amount > word[top].amount) top=i;
    }
    printf("%d %d",word[top].amount, word[top].hash);
    return 0;
}
