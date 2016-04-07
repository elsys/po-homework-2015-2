#include <stdio.h>
#include <string.h>

typedef struct{
	char equation[21];
}solutions_t;

void binaryplus(int*);
int two_to_the_power_of(int);
int search_combinations(char*, int, solutions_t*);
void sort_combinations(solutions_t*, int);
void print_combinations(solutions_t*, int, int);

int main()
{
	solutions_t solution[512];
	char input[10];
	int result, count_combinations;
	scanf("%s", input);
	scanf("%d", &result);
	count_combinations = search_combinations(input, result, solution);
	if(count_combinations)
	{
	sort_combinations(solution, count_combinations);
	print_combinations(solution, count_combinations, result);
	}
	else printf("-1");
	return 0;
}
void binaryplus(int *binary)
{
	int i = 1;
	binary[i]++;
	for(; i < 10; i++)
	{
		if(binary[i] >= 2) 
		{
			binary[i+1]++;
			binary[i] = 0;
		}
	}
}
int two_to_the_power_of(int n)
{
	int number = 1;
	for(int i = 0; i < n; i++)
		number *= 2;
	return number;
}
int search_combinations(char *input, int result, solutions_t *solution)
{
	int digits[10];
	int operations[10];
	int binary[10];
	int sum, i, j, k, max, counter = 0;

	max = two_to_the_power_of((int)strlen(input)-1);

	for(int i = 0; i < strlen(input); i++)
		digits[i] = input[i] - '0';
	for(i = 0; i < strlen(input); i++)
		binary[i] = 0;

	for(i = 0; i < max; i++)
	{
		sum = 0;
		for(j = 0; j < strlen(input); j++)
		{
			if(binary[j] == 1) operations[j] = digits[j]*(-1);
			else operations[j] = digits[j];
		}
		for(j = 0; j < strlen(input); j++)
			sum += operations[j];
		if(sum == result)
		{
			solution[counter].equation[0] = digits[0] + '0';
			for(j = 1, k = 1; j < strlen(input); j++, k += 2)
			{
				if(binary[j]) solution[counter].equation[k] = '-';
				else solution[counter].equation[k] = '+';
				solution[counter].equation[k+1] = digits[j] + '0';
			}
			solution[counter].equation[k] = '=';
			counter++;
		}
		binaryplus(binary);
	}
	return counter;
}
void sort_combinations(solutions_t *solution, int n)
{
	int i, j;
	solutions_t temp;
	for(i = 0; i < n; i++)
	{
		for(j = i; j < n; j++)
		{
			if(strcmp(solution[i].equation, solution[j].equation) < 0)
			{
				temp = solution[i];
				solution[i] = solution[j];
				solution[j] = temp;
			}
		}
	}
}
void print_combinations(solutions_t *solution, int n, int result)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(i) printf("\n");
		printf("%s%d", solution[i].equation, result);
	}
}
