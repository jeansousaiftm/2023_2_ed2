#include<stdio.h>

void imprimirVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void troca(int v[], int x, int y) {
    int aux = v[x];
    v[x] = v[y];
    v[y] = aux;
}

int bubbleSort(int v[], int p[], int n) {

    int t = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (p[v[j]] > p[v[j + 1]]) {
                troca(v, j, j + 1);
                //imprimirVetor(v, n);
                t++;
            }
        }
    }
    return t;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int v[n], p[n + 1], x;
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            p[x] = i;
        }
        printf("%d\n", bubbleSort(v, p, n));
    }

}
