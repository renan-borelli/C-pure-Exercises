#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"

int Balanceado(char exp[])
{
    int contador = 0, i=0;
 
    while (exp[i])
    {
        if(exp[i] == '{' || exp[i] == '(' || exp[i] == '['){
            contador++;
        }
        if(exp[i] == '}' || exp[i] == ')' || exp[i] == ']'){
            contador--;
        }
        i++;
        if(contador<0){
            return 0;
        }
    }
    if (contador != 0)
        return 0;
    else
        return 1;
}

int main() {
    char expr[104];
    gets(expr);
    if(Balanceado(expr)){
        printf("SIM");
    }
    else{
        printf("NAO");
    }
    return 0;
}
