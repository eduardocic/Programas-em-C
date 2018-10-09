#include <stdio.h>
#include <string.h>
#include "funcoes.h"
#include "driver.h"

int main(void){

    meu_driver driver1;

    addDevice(&driver1, "Eduardo");
    exeDriver(&driver1, FUN_QUADRADO, 4);
    exeDriver(&driver1, FUN_FATORIAL, 5);
    return 0;
}