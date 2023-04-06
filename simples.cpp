#include <stdio.h>

struct No {
    int valor;
    No *prox;
};

struct lista {
    No *cabeca, *cauda;
    int n;

    lista() {
        cabeca = cauda = NULL;
        n = 0;
    }
    bool vazia() {
        return (cabeca == NULL);
    }

    int tamanho() {
        return n;
    }

    void inserirInicio(int numero) {
        No *novo = new No();
        novo->valor = numero;

        if(vazia()) {
            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        }else {
            novo->prox = cabeca;
            cabeca = novo;
        }
        n++;
    }

    void inserirFinal(int numero) {
        No *novo = new No();
        novo->valor = numero;
        if(vazia()) {
            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        }else {
            novo->prox = NULL;
            cauda->prox = novo;
            cauda = novo;
        }
        n++;
    }

    void apagarInicio() {
        if(!vazia()) {
            if(tamanho() == 1) {
                No *aux = cabeca;
                cabeca = NULL;
                cauda = NULL;
                delete(aux);
            }else {
                No *aux = cabeca;
                cabeca = cabeca->prox;
                delete(aux);
            }
        }
        n--;
    }

    void apagarFinal() {
        if(!vazia()) {
            if(tamanho() == 1) {
                No *aux = cabeca;
                cabeca = NULL;
                cauda = NULL;
                delete(aux);
            }else {
                No *penultimo = cabeca;
                while(penultimo->prox != cauda) {
                    penultimo = penultimo->prox;
                }
                delete(cauda);
                cauda = penultimo;
                cauda->prox = NULL;
            }
        }
        n--;
    }

    bool existe(int numero) {
        No *proximo = cabeca;
        int cont = 0;
        while(proximo != cauda->prox) {
            if(proximo->valor == numero) {
                cont++;
            }
            proximo = proximo->prox;
        }
        if(cont > 0) {
            return true;
        }else {
            return false;
        }
    }

    void inserirApenas(int numero) {
        if(!existe(numero)) {
            inserirFinal(numero);
        }
    }

  /*  void apagarN(int numero) {
        No *aux = cabeca;
        while(aux != cauda->prox) {
            if(aux == cabeca) {
                apagarInicio();

            }else if(aux == cauda) {
                apagarFinal();
            }else {
                No *anterior = cabeca;
                while(anterior != cauda->prox) {
                    if(anterior->prox == aux) {
                        anterior->prox = aux->prox;
                        delete(anterior);
                        anterior = anterior->prox;
                    }
                }
            }
            n--;
            aux = aux->prox;
        }
    }
*/

void apagarTodos(int numero) {
    No* atual = cabeca;
    No* anterior = NULL;
    while (atual != NULL) {
        if (atual->valor == numero) {
            // removemos o nó atual
            if (anterior == NULL) {
                cabeca = atual->prox;
                delete atual;
                atual = cabeca;
            } else {
                anterior->prox = atual->prox;
                delete atual;
                atual = anterior->prox;
            }
            n--;
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
}

    void imprimir() {
    No *aux = cabeca;
        do {
            printf("%d\n", aux->valor);
            aux = aux->prox;
        }while(aux !=cauda->prox);
    }


};

int main() {

    lista l;
    l.inserirInicio(5);
    l.inserirInicio(7);
    l.inserirInicio(9);
    l.inserirFinal(11);
    l.inserirFinal(10);
    l.apagarTodos(11);
    l.imprimir();


return 0;
}
