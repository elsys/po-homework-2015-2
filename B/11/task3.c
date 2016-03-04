#include <stdio.h>
#include <math.h>

int main() {
	int n;
	float a,b,c,D,x;

	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%f", &c);

	D = b * b - 4 * a * c;
	printf("%f", D);
	if (D > 0)
		n = 2;

	else if (D == 0)
		n = 1;
	else
		n = 0;

	if (n == 2){
		x=(-b + sqrt(D)) / 2 * a;
		printf("\nx1=%f",x);
		x=(-b - sqrt(D)) / 2 * a;
		printf("\nx2=%f",x);
	}
	else if (n == 1)
		printf("\n x=%f", -b / 2 * a);
	else
		printf("\nnqma realni koreni");

	return 0;
}
