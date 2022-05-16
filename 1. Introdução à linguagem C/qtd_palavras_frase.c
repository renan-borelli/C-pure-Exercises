#include "qtd_palavras_frase.h"
#include <stdio.h>

void imprimir_qtd_palavras(char texto[]) {
    int i=0;
    int qnt_words = 1;
    int qnt_chars = 0;
    while(texto[qnt_chars]!='\0'){
        if(texto[i]==' ' && texto[i+1]!=' ' && texto[i+1]!='\0'){
            
            qnt_words++;
        }
        if(texto[i]==' ' && texto[i+1]=='.'){
            qnt_words--;
        }
        if(texto[i]=='.'){
            printf("%d\n", qnt_words);
            qnt_words=0;
        }
        qnt_chars++;
        i++;
    }
}
