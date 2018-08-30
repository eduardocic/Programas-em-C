#include <stdio.h>
#include <string.h>
#include "driver.h"
#include "funcoes.h"


/* Função que adiciona os driver */
void addDevice(meu_driver *_driver, char *_Nome){

    strcpy(_driver->ID, _Nome);

    /* Crio um espaço na memória para guardar
       endereços das funções aos quais eu irei 
       utilizar */
    ptr_p_Funcao stack_funcoes_Driver[END];

    _driver->funcoes = stack_funcoes_Driver;
    stack_funcoes_Driver[FUN_FATORIAL] = &fatorial;
    stack_funcoes_Driver[FUN_QUADRADO] = &quadrado;
}


/* Função que executa o driver */
void exeDriver(meu_driver *_p, FUNCOES_t _fun, int _valor){
    _p->funcoes[_fun](_valor);
}