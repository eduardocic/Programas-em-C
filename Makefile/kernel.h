#ifndef KERNEL_H   
#define KERNEL_H

#define SUCESSO 1
#define FALHA   0

#define QNT_PROCESSO 2

/* Ponteiro para função */
typedef int (*ptrFuncao)(int a, int b);

/* Estrutura de dados */
typedef struct {
    ptrFuncao funcao;
    int prioridade;
} Processo;

/* Operações do Kernel */
char KernelInit();
char KernelAdd(ptrFuncao _funcao, int _priority, Processo *ptr);
void KernelLoop(Processo *pilha);


#endif