#include "palavra.h"
#include <stdlib.h>

void substituir_palavra(char *texto, char *palavra1, char* palavra2) {
    int tam_p1=0;
    int tam_p2=0;
    int tamTxt=0;
    while(palavra1[tam_p1]!='\0'){
        tam_p1++;
    }
    while(palavra2[tam_p2]!='\0'){
        tam_p2++;
    }
    while(texto[tamTxt]!='\0'){
        tamTxt++;
    }
    int percorre_texto=0;
    int p1;
    int i,j;
    int validator_p1;
    while(texto[percorre_texto]!='\0'){
        validator_p1=0;
        for(p1=0;p1<tam_p1;p1++){
            if(texto[percorre_texto+p1]==palavra1[p1] && (texto[percorre_texto+tam_p1]==' ' || texto[percorre_texto+tam_p1]=='.')){
                validator_p1++;
            }
        }
        if(validator_p1==tam_p1){
            if(tam_p1==tam_p2){
                for(i=0;i<tam_p1;i++){
                    texto[percorre_texto+i]=palavra2[i];
                }
            }
            else if(tam_p1<tam_p2){
                for(j=tamTxt-1;j>percorre_texto-1;j--){
                    texto[j+tam_p2-tam_p1]=texto[j];
                }
                for(i=0;i<tam_p2;i++){
                    texto[percorre_texto+i]=palavra2[i];
                }
            }
            else if(tam_p1>tam_p2){
                for(p1=0;p1<tam_p2;p1++){
                    texto[percorre_texto+p1]=palavra2[p1];
                }
                for(i=percorre_texto;i<tamTxt-(tam_p1-tam_p2);i++){
                    texto[i+tam_p2]=texto[i+tam_p1];
                }
            }
        }
        percorre_texto++;
    }
}