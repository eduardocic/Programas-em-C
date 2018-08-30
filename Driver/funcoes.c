#include <stdio.h>
#include "funcoes.h"

int fatorial(int n){

    if ( n == 0 ){
        
        printf("Fatorial é: %d\n", 1);
        return 1;
    }
    else {
        int fat = 1;
        for (int i = 1; i <= n ; i++){
            fat = fat*i;
        }
        printf("Fatorial é: %d\n", fat);
        return fat;
    }
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
