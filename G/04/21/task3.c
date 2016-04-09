#include <stdio.h>
#include <string.h>

#define	MAX_INTPUT_LENGHT 11
#define POSSIBLE_COMBINATIONS 2

char input[MAX_INTPUT_LENGHT];
int sum;

int lenght;
char combinations[10][20]={0};
int combinations_lenght = 0;
int arr[10]={0};

void get_combinations(int index);
void sort_combinations();
void print_combinations();

int main()
{
	scanf("%s",input);
	scanf("%d",&sum);

	lenght = strlen(input)-1;

	get_combinations(0);

	sort_combinations();

	print_combinations();

	return 0;
}

void get_combinations(int index)
{
	if (index >= lenght)
	{
		int i = 0,curr_sum = 0;

		if(arr[i] == 1)
		{
			curr_sum = (input[i] - '0') + (input[i+1] - '0');
		}
		else if(arr[i] == 2)
		{
			curr_sum = (input[i] - '0') - (input[i+1] - '0');
		}
		i += 2;

		while(arr[i-1] != 0)
		{
			if(arr[i-1] == 1)
			{
				curr_sum += (input[i] - '0');
			}
			else
			{
				curr_sum -= (input[i] - '0');
			}
			i++;
		}

		if(curr_sum == sum)
		{
			int counter = 0;
			combinations[combinations_lenght][counter++] = input[0];
			for(i = 0; i < lenght; i++)
			{
				if(arr[i] == 1)
				{
					combinations[combinations_lenght][counter++] = '+';
				}
				else
				{
					combinations[combinations_lenght][counter++] = '-';
				}
				combinations[combinations_lenght][counter++] = input[i+1];
			}

			combinations[combinations_lenght][counter++] = '=';
			combinations[combinations_lenght][counter] = sum + '0';			

			combinations_lenght++;
		}
	}
	else
	{
		int i;
		for (i = 1; i < POSSIBLE_COMBINATIONS+1; i++)
		{
			arr[index] = i;
			get_combinations(index + 1);
		}
	}
}

void print_combinations()
{
	int i;
	for (i = 0; i < combinations_lenght; ++i)
	{
		printf("%s\n", combinations[i]);
	}
	if(combinations_lenght == 0)
	{
		printf("-1\n");
	}
}

void sort_combinations()
{
	int a,b;
	char temp[20];

	for(a=0; a<combinations_lenght; ++a)
	{
        for(b=combinations_lenght-1; b>a; --b)
        {
            /*Сравняване на съседни елементи*/      
            if(strcmp(combinations[b-1],combinations[b]) < 0)
            {
                    strcpy(temp,combinations[b-1]);
                    strcpy(combinations[b-1],combinations[b]);
                    strcpy(combinations[b],temp);
            }
        }
    }
}
