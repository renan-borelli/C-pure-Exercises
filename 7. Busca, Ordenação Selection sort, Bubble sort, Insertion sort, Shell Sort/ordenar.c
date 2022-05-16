#include "ordenar.h"
#include "funcao_comparar.h"

void ordenar_vetor(ItemVetor v[], int n) {
    int i;
    for (i = 0; i < n-1; i++) {
        ItemVetor menor = v[i];
        int j;
        for (j = i+1; j < n; j++){
            if(comparar(menor, v[j])>0){ //Para cada caso em que uma troca é necessária, armazenamos a v[i] que será trocada na variável temporária, substituimos v[i] pelo menor=v[j] e alteramos v[j] para o que era v[i] antes da substituição.
                ItemVetor tmp = v[i];
                menor = v[j];
                v[i] = menor;
                v[j] = tmp;
            }
        }
    }
}
