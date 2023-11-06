#include<stdio.h>
#include<string.h>

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

bool buscaBinaria(char v[][101], int n, char x[101]) { // O(log n)

    int s = 0, e = n - 1;

    while (s <= e) {

        int m = (s + e) / 2;

        if (strcmp(x, v[m]) == 0) {
            return true;
        } else if (strcmp(x, v[m]) < 0) {
            e = m - 1;
        } else if (strcmp(x, v[m]) > 0) {
            s = m + 1;
        }

    }

    return false;

}

int main() {

    int n, m, r = 0;
    scanf("%d", &n);

    char dic[500][101], palavra[101];

    for (int i = 0; i < n; i++) {
        scanf("%s", dic[i]);
    }

    mergeSort(dic, n);

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%s", palavra);
        if (buscaBinaria(dic, n, palavra)) {
            r++;
        }
    }

    printf("%d", r);

    return 0;
}
