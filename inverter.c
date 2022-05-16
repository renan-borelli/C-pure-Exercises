#include <stdlib.h>
#include "inverter.h"

LinkedNode* inverter_lista(LinkedNode *inicio) {
    LinkedNode *anterior, *atual;
    if(inicio != NULL)
    {
        anterior = inicio;
        atual = inicio->next;
        inicio = inicio->next;
        anterior->next = NULL;
        while(inicio != NULL)
        {
            inicio = inicio->next;
            atual->next = anterior;
            anterior = atual;
            atual = inicio;
        }
        inicio = anterior;
    }
    return inicio;
}