#include <stdio.h>
#include <string.h>

int main () {
	char arr[21];

	int elem = 1, count, sum, point = 0, tmp;

	scanf ("%s", arr);

	if (arr[0] != '9') elem = 0;

	if (arr[1] != '7') elem = 0;

	if (arr[2] != '8' && arr[2] != '9') elem = 0;

	if (strlen (arr) != 17) elem = 0;

	for (count = 0, sum = 0; count < 17; count++) {
	if (arr[count] >= '0' && arr[count] <= '9') sum++;
	}

	if (sum != 13) elem = 0;

	for (count = 0, sum = 0; count < 15; count++) {
	if (arr[count] >= '0' && arr[count] <= '9') {
	if (point % 2 == 0) {sum = sum + (arr[count] - '0'); point++;}
	else {sum = sum + (arr[count] - '0') * (3); point++;}
	}
	}

	tmp = arr[16] - '0';

	sum = 10 - (sum % 10);

	if (sum != tmp) elem = 0;

	if (elem == 0) {
	printf ("0\n");
	return 0;
	}

	printf ("1\n");

	for (count = 0; count < 17; count++) {
	if (arr[count] == '9') {
	if (arr[count + 1] == '3') {
	if (arr[count + 2] == '3') {
	if (arr[count + 3] == '3') {
	if (arr[count + 4] == '4') {
	if (arr[count + 5] == '6') {
	if (arr[count - 1] == '-') {
	if (arr[count + 6] == '-') {
	printf ("Bluebridge\n");
	}
	}
	}
	}
	}
	}
	}
	}
	}

	for (count = 0; count < 17; count++) {
	if (arr[count] == '5') {
	if (arr[count + 1] == '5') {
	if (arr[count + 2] == '5') {
	if (arr[count + 3] == '8') {
	if (arr[count + 4] == '3') {
	if (arr[count - 1] == '-') {
	if (arr[count + 5] == '-') {
	printf ("Alyson Books\n");
	}
	}
	}
	}
	}
	}
	}
	}

	for (count = 0; count < 17; count++) {
	if (arr[count] == '4') {
	if (arr[count + 1] == '2') {
	if (arr[count + 2] == '1') {
	if (arr[count + 3] == '0') {
	if (arr[count - 1] == '-') {
	if (arr[count + 4] == '-') {
	printf ("FUNimation Productions, Ltd.\n");
	}
	}
	}
	}
	}
	}
	}

	for (count = 0; count < 17; count++) {
	if (arr[count] == '0') {
	if (arr[count + 1] == '1') {
	if (arr[count + 2] == '-') {
	if (arr[count - 1] == '-') {
	printf ("Pyramid Books\n");
	}
	}
	}
	}
	}

	return 0;
}
