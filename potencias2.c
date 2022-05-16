/*Leia uma sequência de n inteiros e mostre quantos são potências de 2*/

#include <stdio.h>

int main(){
    float novo_num = 0;
    int qntd_nums = 0;
    int potencias2 = 0;
    scanf("%d", &qntd_nums);
    int i;
    for(i=0; i<qntd_nums; i++){
        scanf("%f", &novo_num);
        while(novo_num>1){
            novo_num = novo_num/2;
            if(novo_num==1){
                potencias2++;
            }
        }
    }
    printf("%d\n", potencias2);

}
