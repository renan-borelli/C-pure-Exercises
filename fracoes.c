#include "fracoes.h"

Fracao simplifyFracao(Fracao Fresult){
    int resto=1;
    int num = Fresult.numerador;
    int den = Fresult.denominador;
    while(resto!=0){
        resto = num%den;
        num = den;
        den = resto;
    }
    Fresult.numerador = Fresult.numerador/num;
    Fresult.denominador = Fresult.denominador/num;
    return Fresult;
}


Fracao somar(Fracao f1, Fracao f2) {
    Fracao Fresult;
    Fresult.numerador = f1.numerador * f2.denominador + f2.numerador * f1.denominador;
    Fresult.denominador = f1.denominador*f2.denominador;
    return simplifyFracao(Fresult);
}

Fracao somar_vetor(Fracao f[], int n_fracoes) {
    int i;
    for(i=0;i<n_fracoes-1;i++){
        f[i+1]=somar(f[i], f[i+1]);
    }
    return simplifyFracao(f[n_fracoes-1]);
}

Fracao multiplicar(Fracao f1, Fracao f2) {
    Fracao Fresult;
    Fresult.numerador = f1.numerador*f2.numerador;
    Fresult.denominador = f1.denominador*f2.denominador;
    return simplifyFracao(Fresult);
    
}

Fracao multiplicar_vetor(Fracao f[], int n_fracoes) {
    int i;
    for(i=0;i<n_fracoes-1;i++){
        f[i+1]=multiplicar(f[i], f[i+1]);
    }
    return simplifyFracao(f[n_fracoes-1]);
}