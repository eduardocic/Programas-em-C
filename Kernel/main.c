#include <stdio.h>
#include "teste.h"

int main(void){

    int a, b;
    a = 10;
    b = 20;

    printf("O resultado é: %d\n", soma(a, b));
    printf("O resultado é: %d\n", produto(a, b));
    return 0;
}