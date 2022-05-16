#include "selectionsort.h"

LinkedNode *selection_sort(LinkedNode *inicio, int *trocas, int *comparacoes) {
    *trocas = 0;
    *comparacoes = 0;
    if(inicio==NULL){
        return NULL;
    }
    LinkedNode *comeca = inicio;
    LinkedNode *percorre;
    LinkedNode *menor;
    while(comeca->next){ //Percorremos cada item da lista começando pelo primeiro da Lista Ligada
        menor = comeca;
        percorre = comeca->next;
        while(percorre){ //Para cada um dos itens da lista fazemos a comparação
            *comparacoes = *comparacoes + 1;
            if(menor->data > percorre->data){ //Caso a condição seja satisfeita, sabemos que devemos fazer a troca
                menor = percorre;
            }
            percorre = percorre->next; //Segue o laço
        }
        if(comeca->data>menor->data){ //Aqui somamos as trocas em que comeca e menor são diferentes e realizamos as trocas das "chaves"/"datas"
            *trocas = *trocas + 1;
            int tmp = comeca->data;
            comeca->data = menor->data;
            menor->data = tmp;
        }
        comeca = comeca->next; //Vamos para o próximo item da lista ligada
    }
    return inicio;
}
