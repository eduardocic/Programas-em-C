#include <stdio.h>
#include <stdlib.h>

typedef struct{
	// int idade;
	// float peso;
	unsigned bit;
} Carac_Fisica;


// void altera(Carac_Fisica b){

// 	b.idade = 10;
// 	b.peso = 100;
// }


int main(void){

	Carac_Fisica a;

	a.bit = 10;
	printf("O tamanha da estrutura é: %d\n\n", sizeof(a));
	printf("Imprime %d\n\n", a.bit);


	return 0;
}