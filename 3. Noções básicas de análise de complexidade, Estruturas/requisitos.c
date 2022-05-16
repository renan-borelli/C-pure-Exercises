#include <stdlib.h>
#include "requisitos.h"

Disciplina *requisito_inicial(Disciplina *disciplina, int *qtd) {
    *qtd=0;
    Disciplina *verificada = NULL;
    while(disciplina->requisito!=NULL){
        verificada = disciplina->requisito;
        disciplina = verificada;
        *qtd=*qtd+1;
    }

    return verificada;
}
