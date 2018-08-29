#include <stdio.h>
#include "driver.h"
#include "funcoes.h"

/*************************************************
 * Quantidade de funções que quero utilizar no meu
 * driver.
 ************************************************/
enum {
    FUN_FATORIAL,
    FUN_QUADRADO,
    // FUN_PRODUTO,
    END
};

/************************************************
 * Aloco na memória uma quantidade de espaço para
 * guardar o endereço das funções. 
 * Percebe que não é qualquer tipo de função, mas
 * funções do tipo definido no 'header'.
 ***********************************************/
ptr_p_Funcao stack_funcoes_Driver[END];

/************************************************
 * Efetivamente aloco espaço na memória para a
 * criação de uma estrutura do tipo 'meu_driver'.
 ***********************************************/
meu_driver driver;

/************************************************
 * Função que recebe um ponteiro para uma estru-
 * tura do tipo 'meu_driver' e inicializa a 
 * criança
 ***********************************************/
// void initID (void *parametro){
//     drv = (meu_driver *)parametro;
//     static int cont = 0;
//     cont++;

//     drv->ID = cont;
//     printf("Conseguiu iniciar com sucesso!!\n");
//     printf("Nr. de driver no sistema: %d\n\n", drv->ID);
// }


meu_driver* pegaDriverGenerico(meu_driver *_p){

    /* Direciona as funções */
    _p->funcoes = stack_funcoes_Driver;

    stack_funcoes_Driver[FUN_FATORIAL] = &fatorial;
    stack_funcoes_Driver[FUN_QUADRADO] = &quadrado;
    // stack_funcoes_Driver[FUN_PRODUTO]  = produto;
    // stack_funcoes_Driver[FUN_IMPRIME]  = printa;

    return &ptr;
}

void initDriver(meu_driver *_p, int a){
    _p->ID = a;
    // driver.funcao_inicia = pegaDriverGenerico;
}

void executa(meu_driver *_p, char _fun, int _valor){
    _p->funcoes[_fun](_valor);
}

