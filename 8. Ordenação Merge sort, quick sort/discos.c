#include "discos.h"

int checkRepetido(Disco* v, int len, int c){
    int a = -12345;
    for(int i=0;i<len-1;i++){
        for(int j=i+1; j<len; j++){
            if(v[j].preco==v[i].preco && v[j].preco!=a){
                c = c - 1;
            }
        }
        a = v[i].preco;
    }
    return c;
}

void swapC(Disco* v, int a, int b)
{
    int t = v[a].codigo;
    v[a].codigo = v[b].codigo;
    v[b].codigo = t;
}

int * partic3(Disco *v, int l, int r, int c[]){
    int pivo = v[r].codigo;
    int pivo_preco = v[r].preco;
    int i, first = l-1;
    int comp = 0;
    for(i=l; i<r; i++){
        comp = comp + 1;
        if(v[i].preco<pivo_preco){
            first++;
            int tmp = v[first].preco;
            v[first].preco = v[i].preco;
            v[i].preco = tmp;
            int tmp1 = v[first].codigo;
            v[first].codigo = v[i].codigo;
            v[i].codigo = tmp1;
        }
        if(v[i].preco==pivo_preco && v[i].codigo<pivo){
            first ++;
            int tmp1 = v[first].codigo;
            v[first].codigo = v[i].codigo;
            v[i].codigo = tmp1;
            int tmp = v[first].preco;
            v[first].preco = v[i].preco;
            v[i].preco = tmp;
        }
    }
    first++;
    v[r].preco = v[first].preco;
    v[first].preco = pivo_preco;
    v[r].codigo = v[first].codigo;
    v[first].codigo = pivo;
    c[0]=comp;
    c[1]=first;
    return c;
}

int * partic2(Disco *v, int l, int r, int c[]){
    int pivo = v[r].codigo;
    int pivo_preco = v[r].preco;
    int i, first = l-1;
    int comp = 0;
    for(i=l; i<r; i++){
        comp = comp + 1;
        if(v[i].codigo>pivo){
            first++;
            int tmp = v[first].codigo;
            v[first].codigo = v[i].codigo;
            v[i].codigo = tmp;
            int tmp1 = v[first].preco;
            v[first].preco = v[i].preco;
            v[i].preco = tmp1;
        }
    }
    first++;
    v[r].codigo = v[first].codigo;
    v[first].codigo = pivo;
    v[r].preco = v[first].preco;
    v[first].preco = pivo_preco;
    c[0]=comp;
    c[1]=first;
    return c;
}

int * partic(Disco *v, int l, int r, int c[]){
    int pivo = v[r].codigo;
    int pivo_preco = v[r].preco;
    int i, first = l-1;
    int comp = 0;
    for(i=l; i<r; i++){
        comp = comp + 1;
        if(v[i].codigo<pivo){
            first++;
            int tmp = v[first].codigo;
            v[first].codigo = v[i].codigo;
            v[i].codigo = tmp;
            int tmp1 = v[first].preco;
            v[first].preco = v[i].preco;
            v[i].preco = tmp1;
        }
    }
    first++;
    v[r].codigo = v[first].codigo;
    v[first].codigo = pivo;
    v[r].preco = v[first].preco;
    v[first].preco = pivo_preco;
    c[0]=comp;
    c[1]=first;
    return c;
}

int qSort3(Disco *v, int l, int r, int c[] ){
    if(l<r){
        partic3(v, l, r, c);
        c[2] = c[2] + c[0];
        int pivot = c[1];
        qSort3(v, l, pivot-1, c);
        qSort3(v, pivot+1, r, c);
    }
    else{
        return c[2];
    }
}

int qSort2(Disco *v, int l, int r, int c[] ){
    if(l<r){
        partic2(v, l, r, c);
        c[2] = c[2] + c[0];
        int pivot = c[1];
        qSort2(v, l, pivot-1, c);
        qSort2(v, pivot+1, r, c);
    }
    else{
        return c[2];
    }
}

int qSort1(Disco *v, int l, int r, int c[] ){
    if(l<r){
        partic(v, l, r, c);
        c[2] = c[2] + c[0];
        int pivot = c[1];
        qSort1(v, l, pivot-1, c);
        qSort1(v, pivot+1, r, c);
    }
    else{
        return c[2];
    }
}

int quicksort(Disco *v, int n, int tipo) {
    int c[]={0, 0, 0};
    int comp = 0;
    if(tipo==1){
        comp = qSort1(v, 0, n-1, c);
    }
    else if(tipo==2){
        comp = qSort2(v, 0, n-1, c);
    }
    else{
        comp = qSort3(v, 0, n-1, c);
        //comp = checkRepetido(v, n-1, comp);
/*        int i=0, j=1;
        while(i<n-1){
            while(j<n){
                if(v[j].preco==v[i].preco && v[j].codigo<v[i].codigo){
                    swapC(v, i, j);
                    comp = comp -1;
                }
                j = j+1;
            }
            i=i+1;
            j=i+1;
        }*/
    }
    return comp;
}
