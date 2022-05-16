//#include "valor_freq.h"

int valor_frequente(int v[], int n) {
    int i, j;
    int mais_freq=0;
    int num_freq=0;
    for(i=0;i<n;i++){
        int count_freq=0;
        for(j=0;j<n;j++){
            if(v[i]==v[j]){
                count_freq++;
            }
        }
        if(count_freq>=mais_freq){
            mais_freq = count_freq;
            num_freq = v[i];
        }
    }
    return num_freq;
}
