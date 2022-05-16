#include <stdio.h>
#include <stdlib.h>

int acha_char(int chr){ //Verifica pelo valor ASCII da letra se é uma dentre A até Z e retorna dentre 0 e 26 uma das possibilidades para a respectiva letra
    int achou = 0;
    int c = 65;
    while(c<91 && chr!=c){
      achou++;
      c++;
    }
    if(chr==c){
        return achou;
    }
    return 27;
}


void cSort(char *v, int n){ // Algoritmo de countingsort que cria um vetor para a frequência e contagem a partir das posições retornadas pela function acha_char e também armazena a string ordenada em um outro vetor para realizar a impressão
    if(v[0]=='\0'||v[1]=='\0'){
        return;
    }
    int *vet = malloc(sizeof(int)*27);
    for(int i=0; i<27; i++){
        vet[i] = 0;
    }
    for(int i=0; i<n; i++){
        int achou = acha_char(v[i]);
        vet[achou]++;
    }
    printf("[");
    for(int i=0; i<26; i++){
        if(i!=25){
            printf("%d ", vet[i]);
        }
        else{
            printf("%d]\n", vet[i]);
        }
    }
    for(int i=1; i<27; i++){
        vet[i] = vet[i]+vet[i-1];
    }
    printf("[");
    for(int i=0; i<26; i++){
        if(i!=25){
            printf("%d ", vet[i]);
        }
        else{
            printf("%d]\n", vet[i]);
        }
    }
    char resp[n], count;
    int index;
    for(int i=n-1; i>=0; i--){
        count = v[i];
        index = acha_char(v[i]);
        resp[vet[index] - 1] = count;
        vet[index]--;
    }
    for(int i=0; i<n; i++){
        if(resp[i+1]!='\0'){
            printf("%c", resp[i]);
        }
        else{
            printf("%c\n", resp[i]);
            break;
        }
    }
    free(vet);
}

int main() {
    int len = 0, count = 0;
    char *v = malloc(sizeof(int)*1004);
    scanf("%s", v);
    while(v[count]!='\0'){ // Achar tamanho da string para o countingsort
        len++;
        count++;
    }
    cSort(v, len);
    free(v);
    return 0;
}
