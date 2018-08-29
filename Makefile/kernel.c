#include <stdio.h>
#include "kernel.h"

char KernelInit(){
    return SUCESSO;
}

char KernelAdd(ptrFuncao _funcao, int _priority, Processo *ptr){
    ptr->funcao     = _funcao;
    ptr->prioridade = _priority;
    return SUCESSO;
}

void KernelLoop(Processo *ptr){
    int a = 10;
    int b = 4;
    int c;
    int count = 5;
    
    while (count){
        for (int i = 0 ; i < QNT_PROCESSO ; i++){
            c = (ptr + i)->funcao(a, b);
            printf("Executou para %d\n", c);    
        }
        count-- ;
    }
    
    
}
