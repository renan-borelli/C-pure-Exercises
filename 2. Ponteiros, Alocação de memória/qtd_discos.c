#include "qtd_discos.h"

#include <stdlib.h>

void *quantidade_discos(char **discos, int n_discos, int **quantidade_por_fabricante) {
    *quantidade_por_fabricante =malloc(sizeof(int) *4);
    int i;
    int a=0, b=0, c=0, d=0;
    for(i=0;i<n_discos;i++){
        if(discos[i][7]==65){
            a+=1;
        }
        if(discos[i][7]==66){
            b+=1;
        }
        if(discos[i][7]==67){
            c+=1;
        }
        if(discos[i][7]==68){
            d+=1;
        }
    }
    (*quantidade_por_fabricante)[0] = a;
    (*quantidade_por_fabricante)[1] = b;
    (*quantidade_por_fabricante)[2] = c;
    (*quantidade_por_fabricante)[3] = d;
}
