#include <stdio.h>
#include "funcao.h"

static void imprime(){
    printf("Olá, estou dentro da função 'imprime'\n\n");
}

void imprime2(){

    printf("Chamarei dentro desta função a função 'imprime()'\n\n");
    imprime();
}