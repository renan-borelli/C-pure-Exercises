#include <stdio.h>
#include <stdlib.h>

void merge(int v[], int a, int half, int b, int *comp) {
    int tam1 = half-a+1;
    int tam2 = b-half;
    int esq[tam1], dir[tam2];
    
    for (int i=0; i<tam1; i++){
        esq[i] = v[a+i];
    }
    for (int j=0; j<tam2; j++){
        dir[j] = v[half+1+j];
    }
    int i, j, k;
    i = 0;
    j = 0;
    k = a;
    while (i<tam1 && j<tam2){ //Aqui serão realizadas as comparações entre os elementos dos subvetores que serão mesclados e o resultado será passado por ponteiro
        *comp = *comp+1;
        if (esq[i]<=dir[j]){
            v[k] = esq[i];
            i++;
        }
        else{
            v[k] = dir[j];
            j++;
        }
        k++;
    }
    while (i<tam1){ //Aqui alteramos o vetor segundo os elementos do subvetor menor que a metade
        v[k] = esq[i];
        i++;
        k++;
    }
    while (j<tam2){ //Aqui alteramos o vetor segundo os elementos do subvetor maior que a metade
        v[k] = dir[j];
        j++;
        k++;
    }
}

void mergeSort(int v[], int a, int b, int *comp) {
    if(a < b){ //Aqui realizamos a "extração" dos subvetores a serem mesclados
        int half = a+(b-a)/2;
        mergeSort(v, a, half, comp);
        mergeSort(v, half+1, b, comp);
        merge(v, a, half, b, comp);
    }
}

int main() {
    int size;
    scanf("%d", &size);
    int *comp = malloc(sizeof(int));
    *comp = 0;
    if(size!=0){
        int* v=(int*) malloc(sizeof(int) * size);
        int i, num;
        for(i=0; i<size; i++){
            scanf("%d", &num);
            v[i]=num;
        }
        mergeSort(v, 0, size-1, comp);
        for(i=0; i<size; i++){
            if(i==size-1){
                printf("%d", v[i]);
                break;
            }
        printf("%d ", v[i]);
        }
        free(v);
    }
    printf("\n");
    int comparac = *comp;
    printf("Comparacoes: %d\n", comparac);
    free(comp);
    
    return 0;
}