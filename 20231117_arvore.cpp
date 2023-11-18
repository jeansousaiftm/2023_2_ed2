#include<stdio.h>

struct No {

    int valor, a, n;
    No *esq, *dir;

    No() {
        valor = 0;
        a = 0;
        n = 0;
        esq = dir = NULL;
    }

    No(int _valor) {
        valor = _valor;
        a = 0;
        n = 0;
        esq = dir = NULL;
    }

    void atualizarAltura() {
        int aEsq = -1, aDir = -1;
        if (esq != NULL) {
            aEsq = esq->a;
        }
        if (dir != NULL) {
            aDir = dir->a;
        }
        a = ((aEsq > aDir) ? aEsq : aDir) + 1;
    }

    bool eFolha() {
        return esq == NULL && dir == NULL;
    }

    void imprimir() {
        /*for (int i = 0; i < n; i++) {
            printf("\t");
        }*/
        printf("[%d] a = %d n = %d\n", valor, a, n);
    }

};



struct Arvore {

    No *raiz;

    Arvore() {
        raiz = NULL;
    }

    bool vazia() {
        return raiz == NULL;
    }

    void inserir(int valor) { // O(log n)

        No *novo = new No(valor);

        if (vazia()) {
            raiz = novo;
            return;
        }

        inserir(raiz, novo);

    }

    void inserir(No *aux, No *novo) { // O(log n)
        if (novo->valor < aux->valor) {
            if (aux->esq == NULL) {
                novo->n = aux->n + 1;
                aux->esq = novo;
                aux->atualizarAltura();
                return;
            }
            inserir(aux->esq, novo);
        }
        if (novo->valor > aux->valor) {
            if (aux->dir == NULL) {
                novo->n = aux->n + 1;
                aux->dir = novo;
                aux->atualizarAltura();
                return;
            }
            inserir(aux->dir, novo);
        }
        aux->atualizarAltura();
    }

    bool buscar(int valor) { // O(log n)
        No *aux = raiz;
        while (aux != NULL) {
            if (valor == aux->valor) {
                return true;
            } else if (valor < aux->valor) {
                aux = aux->esq;
            } else if (valor > aux->valor) {
                aux = aux->dir;
            }
        }
        return 0;
    }

    void emOrdem(No *aux) { // O(n)
        if (aux != NULL) {
            emOrdem(aux->esq);
            aux->imprimir();
            emOrdem(aux->dir);
        }
    }

    void preOrdem(No *aux) { // O(n)
        if (aux != NULL) {
            preOrdem(aux->esq);
            preOrdem(aux->dir);
            aux->imprimir();
        }
    }

    void posOrdem(No *aux) { // O(n)
        if (aux != NULL) {
            aux->imprimir();
            posOrdem(aux->esq);
            posOrdem(aux->dir);
        }
    }

    void remover(int valor) { // O(log n)

        if (vazia()) {
            return;
        }

        remover(raiz, valor);

    }

    void remover(No *aux, int valor) { // O(log n)

        if (aux == NULL) {
            return;
        }

        if (aux->esq != NULL) {

            if (valor == aux->esq->valor) {

                No *remover = aux->esq;

                if (remover->eFolha()) {
                    delete(remover);
                    aux->esq = NULL;
                } else if (remover->esq == NULL) {
                    aux->esq = remover->dir;
                    delete(remover);
                    aux->esq->n = aux->n + 1;
                } else if (remover->dir == NULL) {
                    aux->esq = remover->esq;
                    delete(remover);
                    aux->esq->n = aux->n + 1;
                } else {
                    aux->esq = remover->esq;
                    No *aux2 = aux->esq;
                    while (aux2->dir != NULL) {
                        aux2 = aux2->dir;
                    }
                    aux2->dir = remover->dir;
                    delete(remover);
                    aux->esq->n = aux->n + 1;
                }

                raiz->a = atualizarAltura(raiz);
                atualizarNivel(raiz);
                return;
            }

        }

        if (aux->dir != NULL) {

            if (valor == aux->dir->valor) {

                No *remover = aux->dir;

                if (remover->eFolha()) {
                    delete(aux->dir);
                    aux->dir = NULL;
                } else if (remover->esq == NULL) {
                    aux->dir = remover->dir;
                    delete(remover);
                    aux->dir->n = aux->n + 1;
                } else if (remover->dir == NULL) {
                    aux->dir = remover->esq;
                    delete(remover);
                    aux->dir->n = aux->n + 1;
                } else {
                    aux->dir = remover->esq;
                    No *aux2 = aux->dir;
                    while (aux2->dir != NULL) {
                        aux2 = aux2->dir;
                    }
                    aux2->dir = remover->dir;
                    delete(remover);
                    aux->dir->n = aux->n + 1;

                }

                raiz->a = atualizarAltura(raiz);
                atualizarNivel(raiz);

                return;
            }

        }

        if (valor < aux->valor) {
            remover(aux->esq, valor);
        }
        if (valor > aux->valor) {
            remover(aux->dir, valor);
        }

    }

    int atualizarAltura(No *aux) { // O(n)
        if (aux != NULL) {
            int aEsq = atualizarAltura(aux->esq);
            int aDir = atualizarAltura(aux->dir);
            aux->a = ((aEsq > aDir) ? aEsq : aDir) + 1;
            return aux->a;
        }
        return -1;
    }

    void atualizarNivel(No *aux) { // O(n)
        if (aux == NULL) {
            return;
        }
        if (aux->esq != NULL) {
            aux->esq->n = aux->n + 1;
            atualizarNivel(aux->esq);
        }
        if (aux->dir != NULL) {
            aux->dir->n = aux->n + 1;
            atualizarNivel(aux->dir);
        }
    }

};

int main() {

    Arvore a;

    a.inserir(5);
    a.inserir(3);
    a.inserir(1);
    a.inserir(4);
    a.inserir(6);
    a.inserir(8);
    a.inserir(7);

    a.emOrdem(a.raiz);
    printf("---------------------\n");

    /*printf("%d\n", a.buscar(2));
    printf("%d\n", a.buscar(3));
    printf("%d\n", a.buscar(1));*/

    //a.remover(4);
    //a.remover(1);
    //a.remover(8);
    //a.remover(6);
    a.remover(3);

    a.emOrdem(a.raiz);
    //a.preOrdem(a.raiz);
    //a.posOrdem(a.raiz);

    return 0;
}
