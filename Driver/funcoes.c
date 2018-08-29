#include <stdio.h>
#include "funcoes.h"

int fatorial(int n){
    int a = 1;

    if ( n = 0 ){
        printf("Fatorial é: %d\n", a);
        return a;
    }
    else {
        for (int i = 1; i <= n ; i++){
            a = a*i;
        }
        printf("Fatorial é: %d\n", a);
    }
    return a;
}

int quadrado(int n){
    printf("Quadrado é: %d\n", n*n);
    return n*n;
}


int produto(int n1, int n2) {
    printf("Produto é: %d\n", n1*n2);
    return n1*n2;
}


void printa(void) {
    printf("Olá, mundo\n\n");
}
