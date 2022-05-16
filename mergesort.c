#include "heapsort.h"
#include "funcao_comparar.h"

void mHeap(ItemVetor *v, int n, int j, int*c){
    int l = 1 + 2*j;
    int r = 2 + 2*j;
    int max = j;
    
    if(l<n || r<n){
        *c = *c + 1;
    }
    if(l<n && r<n){
        *c = *c + 1;
    }
    if(comparar(v[l], v[max])>0 && l<n){
        max = l;
    }
    if(comparar(v[r], v[max])>0 && r<n){
        max = r;
    }
    if(max!=j){
        ItemVetor tmpV = v[j];
        v[j] = v[max];
        v[max] = tmpV;
        mHeap(v, n, max, c);
    }
}

int heapsort(ItemVetor *v, int n) {
    if(n<=1){
        return 0;
    }
    int c=0;
    for(int i=(n/2)-1; i>-1; i--){
        mHeap(v, n, i, &c);
    }
    for(int j=n-1; j>0; j--){
        ItemVetor tmpV = v[j];
        v[j] = v[0];
        v[0] = tmpV;
        mHeap(v, j, 0, &c);
    }
    return c;
}