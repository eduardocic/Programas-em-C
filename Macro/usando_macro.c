#include <stdio.h>
#include <string.h>

// *******************************************************
// Utilizando "Variadic Macros". Eu encontrei uma 
// explicação a respeito dess termo no link abaixo:
//
// https://gcc.gnu.org/onlinedocs/cpp/Variadic-Macros.html
//
// *******************************************************
#define Trace(...) printf("\n%s %d\n\n", __VA_ARGS__);


// *******************************************************
// Aqui estou utilizando uma macro que eu vi no site
// da Microsoft no link abaixo:
//
// https://msdn.microsoft.com/pt-br/library/b0084kay.aspx
// 
// Especificamente falando ela retorna o nome da função
// que foi chamada.
//
// No mesmo site é possível verificar a existência de 
// outras Macros.
// *******************************************************
char *exemplo(int a){  
    printf("De dentro da função. Seu nome :'%s'\n", __func__);  

    return (char *)__func__;
} 

int main(void){

    /*****************************************************
    * A primeira parte eu irei apenas chamar a função de
    * nome 'exemplo'.
    *****************************************************/
    char nome_da_funcao[50];
    strcpy(nome_da_funcao, exemplo(5));
    printf("\nNo 'main', seu nome: %s\n", nome_da_funcao);


    /*****************************************************
    * Faço a impressão utilizando a Macro própria do Gcc.
    *****************************************************/
    printf("\nA data é %s\n", __DATE__);

    /*****************************************************
    * Faço a utilização do 'Variadic Macros' lá de cima.
    *****************************************************/
    Trace("Eduardo",20);

    return 0;
}