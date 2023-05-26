#include<stdio.h>


struct No {
    int valor;
    No *proximo;
};

struct Lista {
    No *cabeca, *cauda;
    int n;

    Lista () {
        cabeca = cauda = NULL;
        n = 0;
    }

    int tamanho() {
        return n;
    }

    bool vazia() {
        return (cabeca == NULL);
    }

    void inserirInicio(int numero) {
        No *novo = new No();
        novo->valor = numero;

        if(vazia()) {
            novo->proximo = NULL;
            cabeca = novo;
            cauda = novo;
        }else {
            novo->proximo = cabeca;
            cabeca = novo;
        }
        n++;
    }

    void inserirFinal(int numero) {
        No *novo = new No();
        novo->valor = numero;

        if(vazia()) {
            novo->proximo = NULL;
            cabeca = novo;
            cauda = novo;
        }else {
            novo->proximo = NULL;
            cauda->proximo = novo;
            cauda = novo;
        }
        n++;
    }


    void removerInicio() {
        No *aux = cabeca;
        if(!vazia()) {
            if(tamanho() == 1) {
                cabeca = NULL;
                cauda = NULL;
                delete(aux);
            }else {
                cabeca = aux->proximo;
                delete(aux);
            }
        }
        n--;
    }

    void removerFinal() {
        No *aux = cabeca;
        if(!vazia()) {
            if(tamanho() == 1) {
                cabeca = NULL;
                cauda = NULL;
                delete(aux);
            }else {
                No *penultimo = cabeca;
                while(penultimo->proximo != cauda) {
                    penultimo = penultimo->proximo;
                }
                delete(cauda);
                penultimo->proximo = NULL;
                cauda = penultimo;
            }
        }
        n--;
    }

        void imprimir() {
            No *aux = cabeca;

            while(aux != NULL) {
                printf("%d\n", aux->valor);
                aux = aux->proximo;
            }
        }

        void removerSegundo() {
            if(tamanho() == 2) {
                removerFinal();
            }else if (tamanho() > 2){
                No *aux = cabeca->proximo;
                cabeca->proximo = aux->proximo;
                delete(aux);
                n--;
            }
        }
        void inserirTamanho() {
            inserirFinal(tamanho());
        }

        void removerN(int n) {
            for(int index = 0; index < n; index++) {
                removerFinal();
                n--;
            }
        }

        void inserirN(int n) {
            for(int index = 1; index <= n; index++) {
                inserirFinal(index);
            }
        }

        void inserirPenultima(int n) {
            if (tamanho() > 1) {
                No *penultimo = cabeca;
                while (penultimo->proximo != cauda) {
                    penultimo = penultimo->proximo;
                }
                No *novo = new No();
                novo->valor = n;
                novo->proximo = cauda;
                penultimo->proximo = novo;
            }
    }

};







int main()

{

    Lista l;

    l.inserirInicio(2);
    l.inserirInicio(3);
    l.inserirInicio(4);
    l.inserirFinal(5);
    //l.imprimir();
    //l.removerN(2);
    //l.removerSegundo();
    //l.inserirTamanho();
    l.inserirN(3);
    l.inserirPenultima(0);
    l.imprimir();





return 0;


}
