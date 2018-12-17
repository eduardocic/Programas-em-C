#include <stdio.h>

int AND (int x, int y){
    return (x & y);
}

int OR (int x, int y){
    return (x | y);
}

int XOR (int x, int y){
    return (x ^ y);
}

void printBinario(int a){
    int k;

    printf("0 b ");
    for (int i = (sizeof(int)*8 - 1); i >= 0; i--){
        k = a >> i;
        if (k & 1){
            printf("1");
        }
        else{
            printf("0");
        }

        // Deixa um espaço após a apresentação de 4 bits.
        if ( i%4 == 0){
            printf(" ");
        }
    }
}

int maiorUnitario(int a){
    int flag = 0;

    for (int i = (sizeof(int)*8 - 1); i >= 0; i--){
        flag = a >> i;
        if (flag & 1){
            return i;
        }
    }   
}
  
#define MASK_UM   0xFFFF
#define MASK_ZERO 0x0000

int main(void){
    int numero  = 0x35B0;
    int divisor = 0x0013;
    int quosciente = 0;
    int resto;

    // Pegando o maior unitário do sistema.
    int maiorDivisor = maiorUnitario(divisor);
    int maiorNumero  = maiorUnitario(numero);

    // Iniciação do CRC.
    // -----------------
    int intermed;
    int bit;
    int subtrador;
    int flag = 0;


    printf("----------------------------------\n");
    // 1º Parte
    // ---------
    // Pegar a quantidade de bits necessária para fazer o cálculo
    // comparativo entre os dois numeros
    intermed = numero >> (maiorNumero - maiorDivisor);

    for ( int j = 0; j <= (maiorNumero - maiorDivisor); j++ ){
    // 2º Parte
    // ---------
    // Verifica se o número é maior igual o divisor.
    // Se sim, a gente divide ele de maneira inteira, faz 
    // o cálculo do resto e adiona um ao quosciente. 
    // Caso negativo, a gente não adiciona um ao número e pega um
    // outro valor do sistema.
        if ( intermed >= divisor ){
            subtrador = AND(divisor, MASK_UM);
            resto     = XOR(intermed, subtrador);
            // resto     = intermed - subtrador;
            quosciente  = quosciente << 1;
            quosciente |= 1;    

            printf("Intermed:  ");
            printBinario(intermed); printf("\n");
            printf("Subtrador: ");
            printBinario(subtrador); printf("\n");
            printf("Resto:     "); 
            printBinario(resto); printf("\n");
        }
        else{
            subtrador = AND(divisor, MASK_ZERO);
            resto     = XOR(intermed, subtrador);
            quosciente  = quosciente << 1;
            quosciente |= 0;  
    
            printf("Intermed:  ");
            printBinario(intermed); printf("\n");
            printf("Subtrador: ");
            printBinario(subtrador); printf("\n");
            printf("Resto:     "); 
            printBinario(resto); printf("\n");
        }

        // 3º Parte
        // ---------
        // Pegar o próximo bit da número a ser dividido.
        int alpha;
        flag += 1;
        bit   = numero >> (maiorNumero - (maiorDivisor + flag));
        alpha = bit >> 1;
        alpha = alpha << 1;
        bit   = bit - alpha;
        resto = (resto << 1) | bit;
        intermed = resto;

        printf("Próximo bit: %u\n", bit);
        printf("Resto ar.: ");
        printBinario(resto);  printf("\n");
        printf("Quosc.   : ");
        printBinario(quosciente);  printf("\n\n");
        printf("------------------------------------------------------\n");
    }

    printf("\nResultado Final\n");
    printf("---------------\n\n");

    printf("Quosciente..: ");
    printBinario(quosciente);  printf("\n");
    printf("CRC.........: ");
    resto = resto >> 1;
    printBinario(resto);  printf("\n");
    printf("\n\n");
    return 0;
}