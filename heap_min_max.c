#include <stdio.h>
#include <stdlib.h>

int main() {
    int len;
    scanf("%d", &len);
    int *vet = malloc(sizeof(int)*len);
    for(int i=0; i<len; i++){
        scanf("%d", &vet[i]);
    }
    int type = 0;
    for(int i=0; i<len-1; i++){ //Analisa heap_min e caso ache inconsistência, iguala type a 2 (heap_max)
        if(vet[(i-1)/2]>vet[i]){
            type = 2;
        }
    }
    for(int j=0; j<len; j++){
        if(vet[(j-1)/2] < vet[j]){ //Analisa heap_max e caso ache inconsistência, se type = 2, imprime 0 e retorna, se type = 0, iguala type a 1 (heap_min)
            if(type==2){
                printf("0\n");
                free(vet);
                return 0;
            }
            type = 1;
        }
    }
    printf("%d\n", type); //Caso não haja inconsistências tanto no primeiro laço quanto no segundo, imprime o valor de type e retorna
    free(vet);
    return 0;
}