#include <stdio.h>
#include "kernel.h"

Processo pilha[QNT_PROCESSO];

/* Protótipo de funções */
int soma(int a, int b){
    return (a+b);
}

int produto(int a, int b){
    return (a*b);
}

int main(void){
    char a;

    a = KernelInit();
    printf("Se houver sucesso %c!!\n", a);
    
    a = KernelAdd(soma, 10, &pilha[0]);
    printf("Se houver sucesso na adição %c!!\n", a);

    a = KernelAdd(produto, 10, &pilha[1]);
    printf("Se houver sucesso no produto %c!!\n", a);
    printf("foi\n");

    KernelLoop(pilha);
    return 0;
}


