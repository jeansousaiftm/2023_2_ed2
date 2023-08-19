#include<stdio.h>

void troca(int v[], int x, int y) {
    int aux = v[x];
    v[x] = v[y];
    v[y] = aux;
}

void selectionSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] > v[j]) {
                troca(v, i, j);
            }
        }
    }
}

void selectionSortDecrescente(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] < v[j]) {
                troca(v, i, j);
            }
        }
    }
}

int main() {
    int n, x, pares[100000], impares[100000], up = 0, ui = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x % 2 == 0) {
            pares[up++] = x;
        } else {
            impares[ui++] = x;
        }
    }
    selectionSort(pares, up);
    for (int i = 0; i < up; i++) {
        printf("%d\n", pares[i]);
    }
    selectionSortDecrescente(impares, ui);
    for (int i = 0; i < ui; i++) {
        printf("%d\n", impares[i]);
    }
    return 0;
}
