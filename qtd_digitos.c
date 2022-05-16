#include "qtd_digitos.h"

int quantidade_digitos(int numero) {
    int qntde_digs = 0;
    int controle_laco=1;
    if(numero<=9){
        return 1;
    }
    while(controle_laco<=numero){
        controle_laco = controle_laco*10;
        qntde_digs++;
    }
    return qntde_digs;
}