#include<stdio.h>

void imprimirVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void conquista(int v[], int s, int m, int e) {
    int i = s, j = m + 1, k = 0;
    int tmp[(e - s) + 1];
    while (i <= m && j <= e) {
        if (v[i] < v[j]) {
            tmp[k++] = v[i++];
        } else {
            tmp[k++] = v[j++];
        }
    }
    while (i <= m) {
        tmp[k++] = v[i++];
    }
    while (j <= e) {
        tmp[k++] = v[j++];
    }
    for (i = s, k = 0; i <= e; i++, k++) {
        v[i] = tmp[k];
    }
    imprimirVetor(v, 8);
}

void divisao(int v[], int s, int e) {
    printf("ms %d %d\n", s, e);
    if (s < e) {
        int m = (s + e) / 2;
        divisao(v, s, m);
        divisao(v, m + 1, e);
        conquista(v, s, m, e);
    }
}

void mergeSort(int v[], int n) {
    divisao(v, 0, n - 1);
}

int main() {
    int v[] = { 4, 3, 5, 1, 6, 8, 2, 7 };
    imprimirVetor(v, 8);
    mergeSort(v, 8);
    imprimirVetor(v, 8);
    return 0;
}
