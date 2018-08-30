#ifndef DRIVER_H
#define DRIVER_H

/*************************************************
 * Quantidade de funções que quero utilizar no meu
 * driver.
 ************************************************/
typedef enum {
    FUN_FATORIAL,
    FUN_QUADRADO,
    END
} FUNCOES_t;

/***********************************************
 * Ponteiro para Função.
 * 
 * Este ponteiro em específico é para funções
 * que recebem um inteiro e retorna um inteiro.
 **********************************************/
typedef int (*ptr_p_Funcao)(int parametro);

/***********************************************
 * Estrutura de dados.
 **********************************************/
typedef struct{
    char *ID;
    ptr_p_Funcao *funcoes;
} meu_driver;

/***********************************************
 * Funções do driver.
 **********************************************/
void addDevice(meu_driver *_driver, char *_Nome);
void exeDriver(meu_driver *_p, FUNCOES_t _fun, int _valor);

#endif