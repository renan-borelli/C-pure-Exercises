#include <stdlib.h>
#include "lista.h"
#include "lista_espelhada.h"
#include "pilha.h"
#include "fila.h"

int espelho(LinkedNode** inicio, LinkedNode* fim)
{
    if(fim == NULL){
        return 1;
    }
    int boolean = espelho(inicio, fim->next) && ((*inicio)->data == fim->data);
    (*inicio) = (*inicio)->next;
    return boolean;
}

int verificar_lista(LinkedNode *lista) {
    if(espelho(&lista, lista)){
        return 1;
    }
    else{
        return 0;
    }
}
