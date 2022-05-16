#include "mergesort_string.h"

int lexic(LinkedNode *c1, LinkedNode *c2){ //Realiza uma comparação entre as palavras da lista ligada
    char*word1 =  c1->data;
    char*word2 =  c2->data;
    while(*word1 && *word1==*word2){
        word1++;
        word2++;
    }
    if(*word1 - *word2 > 0){ //Caso a palavra c1 seja maior que a c2, retorna 1
        return 1;
    }
    return 0; //Demais casos, retorna 0
}

LinkedNode *merge(LinkedNode *h1, LinkedNode *h2, int*c){ //Aqui realizamos o algoritmo de merge para os nós da lista por recursividade
    if(h1==NULL){
        return h2;
    }
    else if(h2==NULL){
        return h1;
    }
    *c = *c + 1;
    LinkedNode *menor;
    if(lexic(h1, h2)==0){ //Nessa etapa há a comparacao lexicografica para decidir a ordem e alterar
        menor = h1;
        menor->next = merge(h1->next, h2, c);
    }
    else{
        menor = h2;
        menor->next = merge(h1, h2->next, c);
    }
    return menor; //Obtido o menor dos nos, podemos retornar para a funcao que organiza a lista
}

LinkedNode *mSort(LinkedNode *inicio, int *c){ //Funcao recursiva padrao de mergesort como utilizada nos exercicios anteriores do tema apenas acrescidas algumas restricoes
    if(inicio == NULL || inicio->next == NULL){
        return inicio;
    }
    LinkedNode *tmp1 = inicio;
    LinkedNode *tmp2 = inicio->next;
    while(tmp2!=NULL && tmp2->next!=NULL){
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
        tmp2 = tmp2->next;
    }
    tmp2 = tmp1->next;
    tmp1->next = NULL;
    tmp1 = inicio;

    LinkedNode *half1 = tmp1;
    LinkedNode *half2 = tmp2;
    half1 = mSort(half1, c);
    half2 = mSort(half2, c);
    return merge(half1, half2, c);
}

LinkedNode *mergesort(LinkedNode *inicio, int *comparacoes) { //Algoritmo para mergesort de strings com lista ligada (simplesmente)
    *comparacoes = 0;
    return mSort(inicio, comparacoes);
}