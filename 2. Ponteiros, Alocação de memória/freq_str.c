#include "freq_str.h"

void frequencia_string(const char *str, const char *texto, int *qtd) {
    int size_txt = 0, size_str = 0;
    while (str[size_str]!='\0') {
        size_str += 1;
    }
    while (texto[size_txt]!='\0') {
        size_txt += 1;
    }
    char strlower[size_str], txtlower[size_txt];
    int i, j, a, contador;

    *qtd = 0;

    for(i=0; i<size_txt;i++){
        a=i;
        contador=0;
        for(j=0; j<size_str; j++){
            if(texto[a]==str[j]){
                contador++;
            }
            else if(texto[a]>str[j] && texto[a]-32==str[j]){
                contador++;
            }
            else if(texto[a]<str[j] && texto[a]+32==str[j]){
                contador++;
            }
            a++;
            if(contador==size_str){
                *qtd +=1;
            }
        }
    }
}
