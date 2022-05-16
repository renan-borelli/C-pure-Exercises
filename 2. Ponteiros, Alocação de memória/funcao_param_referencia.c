#include "funcao_param_referencia.h"

void funcao(int a, int b, int *resultado) {
    int i, j;
    *resultado = 0;
    for(i=1;i<a+1;i++){
        for(j=1;j<b+1;j++){
            *resultado += ((i*j) + 10) * 5 * i;
        }
    }
}
