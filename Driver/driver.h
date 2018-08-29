#ifndef DRIVER_H
#define DRIVER_H

/***********************************************
 * Ponteiro para Função.
 * 
 * No caso, perceba o ponteiro 'ptr_p_Funcao'
 * apontará para uma função que recebe um parâ-
 * metrod do tipo 'void' e retornará um parâme-
 * tro do tipo 'char'.
 **********************************************/
typedef int (*ptr_p_Funcao)(int parametro);


/**********************************************
 * Estrutura do meu_driver
 *
 * Tem-se como entrada os parâmetros:
 *   1. int (não precisa de maiores explicações);
 *   2. Um ponteito para um ponteiro de funções
 *   (ou seja, ele pega o endereço de um ponte-
 *    iro);
 *   3. um ponteiro para função.
 *********************************************/
typedef struct{
    int ID;
    ptr_p_Funcao *funcoes;
    ptr_p_Funcao funcao_inicia;
} meu_driver;


/**********************************************
 * Retorna um endereço de um uma estrutura
 * do tipo 'meu_driver' 
 *********************************************/
meu_driver* pegaDriverGenerico(void);

#endif