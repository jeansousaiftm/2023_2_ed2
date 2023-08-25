#include<stdio.h>

void conquista(int v[], int s, int m, int e, int o) {
    int i = s, j = m + 1, k = 0;
    int tmp[(e - s) + 1];
    while (i <= m && j <= e) {
        if (o == 1) {
            if (v[i] < v[j]) {
                tmp[k++] = v[i++];
            } else {
                tmp[k++] = v[j++];
            }
        } else {
            if (v[i] > v[j]) {
                tmp[k++] = v[i++];
            } else {
                tmp[k++] = v[j++];
            }
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
}

void divisao(int v[], int s, int e, int o) {
    if (s < e) {
        int m = (s + e) / 2;
        divisao(v, s, m, o);
        divisao(v, m + 1, e, o);
        conquista(v, s, m, e, o);
    }
}

void mergeSort(int v[], int n, int o) {
    divisao(v, 0, n - 1, o);
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
    mergeSort(pares, up, 1);
    for (int i = 0; i < up; i++) {
        printf("%d\n", pares[i]);
    }
    mergeSort(impares, ui, 2);
    for (int i = 0; i < ui; i++) {
        printf("%d\n", impares[i]);
    }
    return 0;
}
