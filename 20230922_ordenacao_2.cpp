#include<stdio.h>
#include<string.h>

struct Time {

    char sigla[4];
    int golsPro, golsContra;
    int vitorias, empates, derrotas;

    Time() {
        golsPro = 0;
        golsContra = 0;
        vitorias = 0;
        empates = 0;
        derrotas = 0;
    }

    int pontos() {
        return vitorias * 3 + empates;
    }

    int saldo() {
        return golsPro - golsContra;
    }

    void imprimir() {
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               sigla, pontos(), vitorias, empates, derrotas,
               saldo(), golsPro, golsContra);
    }

    int compara(Time time2) {
        if (pontos() > time2.pontos()) {
            return -1;
        } else if (pontos() < time2.pontos()) {
            return 1;
        } else {
            if (vitorias > time2.vitorias) {
                return -1;
            } else if (vitorias < time2.vitorias) {
                return 1;
            } else {
                if (saldo() > time2.saldo()) {
                    return -1;
                } else if (saldo() < time2.saldo()) {
                    return 1;
                } else {
                    if (golsPro > time2.golsPro) {
                        return -1;
                    } else if (golsPro < time2.golsPro) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        }
    }

};

void conquista(Time v[], int s, int m, int e) {
    int i = s, j = m + 1, k = 0;
    Time tmp[(e - s) + 1];
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

void divisao(Time v[], int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        divisao(v, s, m);
        divisao(v, m + 1, e);
        conquista(v, s, m, e);
    }
}

void mergeSort(Time v[], int n) {
    divisao(v, 0, n - 1);
}

void troca(Time v[], int x, int y) {
    Time aux = v[x];
    v[x] = v[y];
    v[y] = aux;
}

void bubbleSort(Time v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Qual o par estou comparando no momento
        for (int j = 0; j < n - 1; j++) {
            if (v[j].compara(v[j + 1]) > 0) {
                troca(v, j, j + 1);
            }
        }
    }
}

void selectionSort(Time v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i].compara(v[j]) > 0) {
                troca(v, i, j);
            }
        }
    }
}

void insertionSort(Time v[], int n) {
    for (int i = 1; i < n; i++) {
        Time x = v[i];
        int j;
        for (j = i - 1; j >= 0 && v[j].compara(x) > 0; j--) {
            v[j + 1] = v[j];
        }
        v[j + 1] = x;
    }
}

void imprimirTabela(Time times[], int ultimoTime) {
    printf("Time\tP\tV\tE\tD\tSG\tGP\tGC\n");
    for (int i = 0; i < ultimoTime; i++) {
        times[i].imprimir();
    }
}

int main() {

    FILE *f = fopen("dados.txt", "r+");

    Time times[12];
    int ultimoTime = 0;

    char time1[4], time2[4];
    int gols1, gols2, pos1, pos2;

    while (fscanf(f, "%s %dX%d %s", time1, &gols1, &gols2, time2) != EOF) {
        pos1 = -1;
        pos2 = -1;
        for (int i = 0; i < ultimoTime; i++) {
            if (strcmp(times[i].sigla, time1) == 0) {
                pos1 = i;
                break;
            }
        }
        if (pos1 == -1) {
            strcpy(times[ultimoTime].sigla, time1);
            pos1 = ultimoTime;
            ultimoTime++;
        }

        for (int i = 0; i < ultimoTime; i++) {
            if (strcmp(times[i].sigla, time2) == 0) {
                pos2 = i;
                break;
            }
        }
        if (pos2 == -1) {
            strcpy(times[ultimoTime].sigla, time2);
            pos2 = ultimoTime;
            ultimoTime++;
        }

        if (gols1 > gols2) {
            times[pos1].vitorias++;
            times[pos2].derrotas++;
        } else if (gols2 > gols1) {
            times[pos1].derrotas++;
            times[pos2].vitorias++;
        } else {
            times[pos1].empates++;
            times[pos2].empates++;
        }

        times[pos1].golsPro += gols1;
        times[pos1].golsContra += gols2;

        times[pos2].golsPro += gols2;
        times[pos2].golsContra += gols1;

        //printf("%s %dX%d %s\n", time1, gols1, gols2, time2);
    }

    int opcao;

    do {

        printf("1.Bubble\n");
        printf("2.Selection\n");
        printf("3.Insertion\n");
        printf("4.Merge\n");
        printf("5.Sair\n");

        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                bubbleSort(times, 12);
                imprimirTabela(times, 12);
                break;
            case 2:
                selectionSort(times, 12);
                imprimirTabela(times, 12);
                break;
            case 3:
                insertionSort(times, 12);
                imprimirTabela(times, 12);
                break;
            case 4:
                mergeSort(times, 12);
                imprimirTabela(times, 12);
                break;
        };

    } while (opcao != 5);

    return 0;
}
