#include<stdio.h>

void troca(int v[], int x, int y) {
    int aux = v[x];
    v[x] = v[y];
    v[y] = aux;
}

int bubbleSort(int v[], int n) {
    int t = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (v[j] > v[j + 1]) {
                troca(v, j, j + 1);
                t++;
            }
        }
    }
    return t;
}

int main() {
    int c;
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        int n;
        scanf("%d", &n);
        int v[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", &v[j]);
        }
        printf("Optimal train swapping takes %d swaps.\n", bubbleSort(v, n));
    }
    return 0;
}
