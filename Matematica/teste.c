#include <stdio.h>
#include "matematica.h"

int main(){

    /* Teste para fatorial */
    for( int i = 0 ; i < 10 ; i++ ){
        printf("O fatorial de %d é %d\n", i, fatorial(i));
    }
    printf("\n\n");
    
    return 0;
}