#include <stdlib.h>
#include "abb_sucessor_antecessor.h"

void acha_ant(NoArvore* raiz, int chave, NoArvore** ant, NoArvore** suc)
{
    if(raiz==NULL) //Caso raiz vazia, retorna.
        return ;
    acha_ant(raiz->esq, chave, ant, suc); //Recursividade para varrer os nós pra esq
    if(raiz && raiz->chave < chave) 
    {
        *ant = raiz; //Com os nós em ordem crescente guarda o predecessor à chave
    }
    acha_ant(raiz->dir, chave, ant, suc);
}


void acha_suc(NoArvore* raiz, int chave, NoArvore** ant, NoArvore** suc)
{
    if(raiz==NULL) //Caso raiz vazia, retorna.
        return ;
    acha_suc(raiz->esq, chave, ant, suc); //Recursividade para varrer os nós pra esq
    if(raiz&&raiz->chave > chave)
    {
        if((!*suc) || (*suc) && (*suc)->chave > raiz->chave) //Guarda o nó que é maior que chave mas menor que o sucessor avaliado anteriormente
                *suc = raiz;
    }
    acha_suc(raiz->dir, chave, ant, suc);
}


int sucessor(NoArvore *raiz, int chave) {
    NoArvore* ant = NULL, *suc = NULL;
    acha_suc(raiz, chave, &ant, &suc);
    if(suc != NULL){
        return suc->chave;
    }
    return -1;
}

int antecessor(NoArvore *raiz, int chave) {
    NoArvore* ant = NULL, *suc = NULL;
    acha_ant(raiz, chave, &ant, &suc);
    if(ant != NULL){
        return ant->chave;
    }
    return -1;
}
