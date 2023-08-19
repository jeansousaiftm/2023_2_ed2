#include<stdio.h>

void insertionSort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int x = v[i], j;
        for (j = i - 1; j >= 0 && v[j] > x; j--) {
            v[j + 1] = v[j];
        }
        v[j + 1] = x;
    }
}

int main() {

    int v[3], c[3];

    for (int i = 0; i < 3; i++) {
        scanf("%d", &v[i]);
        c[i] = v[i];
    }

    insertionSort(v, 3);

    for (int i = 0; i < 3; i++) {
        printf("%d\n", v[i]);
    }

    printf("\n");

    for (int i = 0; i < 3; i++) {
        printf("%d\n", c[i]);
    }

    return 0;
}
