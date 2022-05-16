#include "ordenar.h"
#include "funcao_comparar.h"

int model(char v1[], char v2[]){ //Compara lexicograficamente os vetores de caracteres char por char afim de desempatar a ordenação e retorna 1 para item2>item1, -1 para o contrário e 0 caso iguais.
    int i=0;
    while(1){
        if(v1[i]>v2[i]){
            return 1;
        }
        else if(v1[i]<v2[i]){
            return -1;
        }
        else{
            if(v1[i+1]=='\0' && v2[i+1]=='\0'){
                return 0;
            }
            else if(v1[i+1]=='\0' && v2[i+1]!='\0'){
                return -1;
            }
            else if(v1[i+1]!='\0' && v2[i+1]=='\0'){
                return 1;
            }
            i = i+1;
        }
    }
}

int planet(char v1[], char v2[]){ //Compara lexicograficamente os vetores de caracteres char por char
    int i=0;
    while(1){
        if(v1[i]>v2[i]){
            return 1;
        }
        else if(v1[i]<v2[i]){
            return -1;
        }
        else{
            if(v1[i+1]=='\0' && v2[i+1]=='\0'){
                return 0;
            }
            else if(v1[i+1]=='\0' && v2[i+1]!='\0'){
                return -1;
            }
            else if(v1[i+1]!='\0' && v2[i+1]=='\0'){
                return 1;
            }
            i = i+1;
        }
    }
}


int autonomy(int v1, int v2){ //Compara os valores inteiros de cada item assim como feito na questão ordenacao.c
    if(v1>v2){
        return 1;
    }
    else if(v1==v2){
        return 0;
    }
    else{
        return -1;
    }
}

int comparar(ItemVetor item1, ItemVetor item2) {
    if(autonomy(item1.autonomia, item2.autonomia) == 1){ //Testamos as comparações seguindo a ordem autonomia > planeta > modelo em questão de prioridade
        return 1;
    }
    else if(autonomy(item1.autonomia, item2.autonomia) == -1){
        return -1;
    }
    else{
        if(planet(item1.planeta, item2.planeta) == 1){
            return 1;
        }
        else if(planet(item1.planeta, item2.planeta) == -1){
            return -1;
        }
        else{
            return(model(item1.modelo, item2.modelo));
        }
    }
}