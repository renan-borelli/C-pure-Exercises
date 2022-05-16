#include <stdio.h>

int main(){
    int tamVet;
    int vetor[tamVet];
    scanf("%d", &tamVet);
    int i;
    for(i=0; i<tamVet; i++){
        scanf("%d", &vetor[i]);
    }
    int atual=0, maior=0, seq=0;
    for(i=0; i<tamVet; i++){
        if(vetor[i]<vetor[i+1] && i!=tamVet-1){ 
          seq++;
          if(seq>maior){
            maior=seq;
            atual = i-maior+1;
          }
        }
        else{
          seq = 0;
        }
    }
    for(i=atual; i<(maior+atual+1); i++){
        printf("%d ",vetor[i]);   
    
    }
    return 0;
}
