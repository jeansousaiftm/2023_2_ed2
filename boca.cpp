#include<stdio.h>
#include<string.h>

struct Competidor {

    int competidor, problemas, tempo;

    Competidor() {
        problemas = 0;
        tempo = 0;
    }

    int resolver(int _tempo, int tentativas) {
        problemas++;
        tempo += _tempo;
        if (tentativas > 1) {
            tempo += (tentativas - 1) * 20;
        }
    }

    void imprimir() {
        printf("%d %d %d\n", competidor, problemas, tempo);
    }

    int compara(Competidor c2) {
        if (problemas > c2.problemas) {
            return -1;
        } else if (problemas < c2.problemas) {
            return 1;
        } else {
            if (tempo < c2.tempo) {
                return -1;
            } else if (tempo > c2.tempo) {
                return 1;
            } else {
                if (competidor < c2.competidor) {
                    return -1;
                } else if (competidor > c2.competidor) {
                    return 1;
                } else {
                    return 0;
                }
            }
        }
    }

};

void conquista(Competidor v[], int s, int m, int e) {
    int i = s, j = m + 1, k = 0;
    Competidor tmp[(e - s) + 1];
    while (i <= m && j <= e) {
        if (v[i].compara(v[j]) < 0) {
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
}

void divisao(Competidor v[], int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        divisao(v, s, m);
        divisao(v, m + 1, e);
        conquista(v, s, m, e);
    }
}

void mergeSort(Competidor v[], int n) {
    divisao(v, 0, n - 1);
}

int main() {

    Competidor competidores[1000];
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        competidores[i].competidor = i + 1;
    }

    for (int i = 0; i < m; i++) {
        int c, t, tt;
        char p;
        scanf("%d %c %d %d", &c, &p, &t, &tt);
        competidores[c - 1].resolver(t, tt);
    }

    mergeSort(competidores, n);

    for (int i = 0; i < n; i++) {
        competidores[i].imprimir();
    }

    return 0;
}
