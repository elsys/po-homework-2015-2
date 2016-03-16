#include <stdio.h>
#include <stdlib.h>

void minmax (int *arr, int size, int *min, int *max) {
    int i = 0;

    *min = arr[0];
    *max = arr[0];

    for (i; i < size; i++) {
        if (*min < arr[i])
            *min = arr[i];

        if (*max > arr[i])
            *max = arr[i];

    }
}

int main()
{
    int dota[500], min, max, n, i = 0;

    scanf ("%d", &n);

    for (i; i < n; i++) {
        scanf ("%d", &dota[i]);

    }

    minmax (dota, n, &min, &max);

    printf("%d", min+max);

    return 0;
}
