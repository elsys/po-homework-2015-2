#include <stdio.h>
#include <string.h>

int main () 
{
	char arr[11];
	int sum, tmp;
	scanf ("%[^\n]s", arr);
	if (arr[2] < '0' || arr[2] > '5')
	{
		printf ("0");
		return 0;
	}
	if (arr[2] == '1') 
	{
		if (arr[3] < '0' || arr[3] > '2') {
			printf ("0");
			return 0;
		}
	}
	if (arr[2] == '3')
	{
		if (arr[3] < '0' || arr[3] > '2') 
		{
			printf ("0");
			return 0;
		}
	}
	if (arr[2] == '5') 
	{
		if (arr[3] < '0' || arr[3] > '2')
		{
			printf ("0");
			return 0;
		}
	}
	sum = (arr[4] - '0')*(10) + (arr[5] - '0');
	if (sum > 31) 
	{
		printf ("0");
		return 0;
	}
	sum = 0;
	sum = sum + ((arr[0] - '0') * 2);
	sum = sum + ((arr[1] - '0') * 4);
	sum = sum + ((arr[2] - '0') * 8);
	sum = sum + ((arr[3] - '0') * 5);
	sum = sum + ((arr[4] - '0') * 10);
	sum = sum + ((arr[5] - '0') * 9);
	sum = sum + ((arr[6] - '0') * 7);
	sum = sum + ((arr[7] - '0') * 3);
	sum = sum + ((arr[8] - '0') * 6);
	sum = sum % 11;
	tmp = arr[9] - '0';
	if (sum >= 10) 
		sum = 0;
	if (sum != tmp) 
	{
		printf ("0");
		return 0;
	}
	printf ("1");
	return 0;
}