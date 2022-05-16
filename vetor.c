#include "vetor.h"
#include <stdlib.h>

int *expandir_vetor(const int *vetor, int n_compactado, int *n_expandido) {
    int i=1;
    *n_expandido = 0;
    while(i<n_compactado){
        *n_expandido += vetor[i];
        i += 2;
    }

    int j=0;
    i=0;
    int *vetor_expandido;
    vetor_expandido = (int*) malloc(*n_expandido*sizeof(int));
    while(j<n_compactado){
        int a=0;
        while(a<vetor[j+1]){
            vetor_expandido[i]=vetor[j];
            a++;
            i++;
        }
        j= j+2;
    }

    return vetor_expandido;
}
