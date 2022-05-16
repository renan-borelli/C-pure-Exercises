#include <stdlib.h>
#include "qtd_nos.h"

struct contador{
    int nos;
    int internos;
};

void soma_nos(NoArvore *raiz, struct contador *c_nos){//Na entrada é dado o contador da soma de nós igual a 0.
    if(raiz!=NULL){ //Se árvore não vazia, vai até o nó mais a esquerda e vai somando até o nó mais a direita.
        soma_nos(raiz->esq, c_nos);
        c_nos->nos = c_nos->nos + 1; //Armazena no contador
        soma_nos(raiz->dir, c_nos);
    }
}

void soma_internos(NoArvore *raiz, struct contador *c_intern){
    if(raiz!=NULL){ //Se árvore não vazia, percorre os nós.
        if(raiz->esq!=NULL || raiz->dir!=NULL ){ //Caso não seja um nó folha, soma no contador.
            c_intern->internos = c_intern->internos + 1;
        }
        soma_internos(raiz->esq, c_intern); //Percorre à esquerda.
        soma_internos(raiz->dir, c_intern); //Percorre à direita.
    }
}

int numero_nos(NoArvore *raiz){
    struct contador *c_nos = malloc(sizeof(struct contador)); //Inicia o contador em 0.
    c_nos->nos = 0;
    soma_nos(raiz, c_nos);
    int result = c_nos->nos;
    free(c_nos);
    return result;
}

int numero_nos_folha(NoArvore *raiz){
    if(raiz == NULL)
        return 0;
    if(raiz->esq == NULL && raiz->dir == NULL) //Faz a soma a partir de cada nó folha retornando 1 caso exista.
        return 1;
    return numero_nos_folha(raiz->esq) + numero_nos_folha(raiz->dir); //Retorna o somatório de cada um para os nós folha à esquerda e direita da árvore.
}

int numero_nos_internos(NoArvore *raiz){
    struct contador *c_intern = malloc(sizeof(struct contador)); //Inicia o contador em 0.
    c_intern->internos = 0;
    soma_internos(raiz, c_intern);
    int result = c_intern->internos;
    free(c_intern);
    return result;
}
