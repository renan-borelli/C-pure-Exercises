#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"

int main() {
    int i=65, count;
    int vencedor[8];
    int gols1, gols2;
    for(count=0; count<8;count++){
        scanf("%d", &gols1);
        scanf("%d", &gols2);
        if(gols1>gols2){
            vencedor[count]=i;
        }
        else{
            vencedor[count]=i+1;
        }
        i=i+2;
    }
    i=0;
    for(count=0; count<4;count++){
        scanf("%d", &gols1);
        scanf("%d", &gols2);
        if(gols1>gols2){
            vencedor[count]=vencedor[count+i];
        }
        else{
            vencedor[count]=vencedor[count+i+1];
        }
        i++;
    }
    i=0;
    for(count=0; count<2;count++){
        scanf("%d", &gols1);
        scanf("%d", &gols2);
        if(gols1>gols2){
            vencedor[count]=vencedor[count+i];
        }
        else{
            vencedor[count]=vencedor[count+i+1];
        }
        i++;
    }
    scanf("%d", &gols1);
    scanf("%d", &gols2);
    count=0;
    if(gols1>gols2){
        printf("%c", vencedor[count]);
    }
    else{
        printf("%c", vencedor[count+1]);
    }

    return 0;
}
