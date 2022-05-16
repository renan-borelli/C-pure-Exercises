#include <stdlib.h>
#include "abb_menor_maior.h"

int menor(NoArvore *raiz) {
    NoArvore *atual = raiz; //Guarda p nó da raiz
    while(atual->esq != NULL){ //Percorre a árvore até o nó mais a esquerda;
        atual = atual->esq;
    }
    return atual->chave;
}

int maior(NoArvore *raiz) {
    
    if(raiz == NULL){
        return -1;
    }
    
    int max = raiz->chave; // Semelhantemente ao anterior, guardamos o valor inicial da raiz
    int e_max = maior(raiz->esq); //Buscamos pela esquerda
    int d_max = maior(raiz->dir); //Buscamos pela direita
    if(e_max > max){
        max = e_max;
    }
    if(d_max > max){
        max = d_max;
    }
    return max;
}
