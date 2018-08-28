#include <stdio.h>
#include "funcao.h"

/*************************************************
 * A função do tipo 'static void' só funciona 
 * dentro do arquivo no qual ele foi definido.
 * 
 * Se olharmos bem a ideia proposta, funciona
 * basicamente como uma função do tipo
 * 'private' em C++. A gente irá fazer um teste 
 * com duas funções que estão escritas no arquivo
 * 'funcao.c'.
 * 
 * Se você abrir o arquivo verá que existem duas
 * funções declaradas.
 *   1. imprime  -- de retorno 'static void'; e
 *   2. imprime2 -- de retorno 'void'.
 * 
 * Como a função 'imprime' está definida em um 
 * outro arquivo (no caso, no arquivo 'funcao.c')
 * qualquer chamada por esta função será dita como
 * impossibilitada. No entanto, se eu chamar por
 * uma função que já está definida no arquivo 
 * 'funcao.c' ela irá aparecer perfeitamente.
 * 
 * Vamos ao teste.
 *************************************************/

int main(void){

    printf("Estou dentro do arquivo principal.\n\n");

    /* No caso, se eu chamar a função 'imprime'
       haverá um problema no meu compilador */
    /* imprime(); --- dará problema. */
    imprime2();

    printf("---------------------------------------\n");
    printf("Depois de fazer a alteração no Makefile\n");
    printf("---------------------------------------\n\n");
    return 0;
}
