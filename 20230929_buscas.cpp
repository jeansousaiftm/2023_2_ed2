#include<stdio.h>

bool buscaSequencial(int v[], int n, int x) { // O(n)

    for (int i = 0; i < n; i++) {
        if (v[i] == x) {
            return true;
        }
    }

    return false;

}

bool buscaBinaria(int v[], int n, int x) { // O(log n)

    int s = 0, e = n - 1;

    while (s <= e) {

        int m = (s + e) / 2;

        if (x == v[m]) {
            return true;
        } else if (x < v[m]) {
            e = m - 1;
        } else if (x > v[m]) {
            s = m + 1;
        }

    }

    return false;

}

int main() {

    int v[] = { 4, 5, 6, 7, 8, 10, 12, 15, 18 };
    int n = 9;

    printf("%d\n", buscaSequencial(v, n, 18));
    printf("%d\n", buscaSequencial(v, n, 1));
    printf("%d\n", buscaSequencial(v, n, 8));

    printf("%d\n", buscaBinaria(v, n, 18));
    printf("%d\n", buscaBinaria(v, n, 1));
    printf("%d\n", buscaBinaria(v, n, 8));

    return 0;
}
