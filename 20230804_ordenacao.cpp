#include<stdio.h>

void troca(int v[], int x, int y) {
    int aux = v[x];
    v[x] = v[y];
    v[y] = aux;
}

void imprimirVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void bubbleSort(int v[], int n) {
    // Quantas vezes precisa executar a varredura
    // completa no bubble sort
    for (int i = 0; i < n - 1; i++) {
        // Qual o par estou comparando no momento
        for (int j = 0; j < n - 1; j++) {
            if (v[j] > v[j + 1]) {
                troca(v, j, j + 1);
                imprimirVetor(v, n);
            }
        }
    }
}

void selectionSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] > v[j]) {
                troca(v, i, j);
                imprimirVetor(v, n);
            }
        }
    }
}

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

    int v[] = { 3, 2, 5, 1, 6, 0, 3, 5 };
    int n = 8;

    imprimirVetor(v, n);
    //bubbleSort(v, n);
    selectionSort(v, n);

    return 0;
}
