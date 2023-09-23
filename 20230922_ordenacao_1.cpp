#include<stdio.h>
#include<string.h>

void troca(char v[][101], int x, int y) {
    char aux[101];
    strcpy(aux, v[x]);
    strcpy(v[x], v[y]);
    strcpy(v[y], aux);
}

void imprimirVetor(char v[][101], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s", v[i]);
    }
}

void bubbleSort(char v[][101], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (strcmp(v[j], v[j + 1]) > 0) {
                troca(v, j, j + 1);
            }
        }
    }
}

void selectionSort(char v[][101], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(v[i], v[j]) > 0) {
                troca(v, i, j);
            }
        }
    }
}

void insertionSort(char v[][101], int n) {
    for (int i = 1; i < n; i++) {
        char x[101];
        strcpy(x, v[i]);
        int j;
        for (j = i - 1; j >= 0 && strcmp(v[j], x) > 0; j--) {
            strcpy(v[j + 1], v[j]);
        }
        strcpy(v[j + 1], x);
    }
}

void conquista(char v[][101], int s, int m, int e) {
    int i = s, j = m + 1, k = 0;
    char tmp[(e - s) + 1][101];
    while (i <= m && j <= e) {
        if (strcmp(v[i], v[j]) < 0) {
            strcpy(tmp[k++], v[i++]);
        } else {
            strcpy(tmp[k++], v[j++]);
        }
    }
    while (i <= m) {
        strcpy(tmp[k++], v[i++]);
    }
    while (j <= e) {
        strcpy(tmp[k++], v[j++]);
    }
    for (i = s, k = 0; i <= e; i++, k++) {
        strcpy(v[i], tmp[k]);
    }
}

void divisao(char v[][101], int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        divisao(v, s, m);
        divisao(v, m + 1, e);
        conquista(v, s, m, e);
    }
}

void mergeSort(char v[][101], int n) {
    divisao(v, 0, n - 1);
}

int main() {

    int i = 0, opcao;
    FILE *f = fopen("nomes2.txt", "r+");
    char tmp[1000][101];

    while (fgets(tmp[i++], 100, f));

    do {

        printf("1.Bubble\n");
        printf("2.Selection\n");
        printf("3.Insertion\n");
        printf("4.Merge\n");
        printf("5.Sair\n");

        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                bubbleSort(tmp, 1000);
                imprimirVetor(tmp, 1000);
                break;
            case 2:
                selectionSort(tmp, 1000);
                imprimirVetor(tmp, 1000);
                break;
            case 3:
                insertionSort(tmp, 1000);
                imprimirVetor(tmp, 1000);
                break;
            case 4:
                mergeSort(tmp, 1000);
                imprimirVetor(tmp, 1000);
                break;
        };

    } while (opcao != 5);

    return 0;
}
