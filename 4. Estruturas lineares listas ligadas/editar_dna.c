#include <stdlib.h>
#include "editar_dna.h"

void liberar(LinkedNode *a, LinkedNode *b){
    if(a == b){
        return;
    }
    liberar(a->next, b);
    free(a);
}

int comparar(char a, char b){
    if((a == 'C' && b == 'G') || (a == 'G' && b == 'C') || (a == 'A' && b == 'T') || (a == 'T' && b == 'A'))
        return 1;
    else
        return 0;
}

LinkedNode *verifica(LinkedNode *dna, LinkedNode *seq){
    while(dna != NULL){
        if(!comparar(dna->data, seq->data)){
            return NULL;
        }
        else if(seq->next == NULL){
            return dna;
        }
        dna = dna->next;
        seq = seq->next;
    }
    return NULL;
}

LinkedNode *editar_dna(LinkedNode *dna_original, LinkedNode *seq_edicao){
    LinkedNode *remover, *prox, *atual;

    while(remover = verifica(dna_original, seq_edicao)){
        prox = remover->next;
        liberar(dna_original->next, remover->next);
        dna_original->data = prox->data;
        dna_original->next = prox->next;
        liberar(prox, prox->next);
    }
    atual = dna_original;
    while(atual != NULL){
        if((remover = verifica(atual->next, seq_edicao))){
            prox = remover->next;
            liberar(atual->next, remover->next);
            atual->next = prox;
        }
        else{
            atual = atual->next;
        }
    }

    return dna_original;
}
