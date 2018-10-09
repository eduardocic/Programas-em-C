#include <stdio.h>
#include <stdlib.h>


typedef enum { 
	Homem   = 0,
    Mulher  = 1
} Genero;


typedef struct {
	Genero    gen;
	int       idade;
	float     altura;
} Eduardo;


void inicia (Eduardo *edu){

	edu->gen    = Homem;
	edu->idade  = 30;
	edu->altura = 1.79;
}


void printa (Eduardo *edu){
	// Seta o gênero
	if ((edu->gen == Mulher)){
		printf("É mulher\n");
	}
	else{
		printf("É homem\n");
	}

	// printa a idade
	printf("A idade é: %d\n", edu->idade);

	// printa a altura
	printf("A altura é: %.2f\n", edu->altura);
}


int main(void){
	// -------------------------------------------------
	// Criação de uma espaço de memória que aloca a 
	// 'struct' específico no referido espaço.
	//
	// 1. Tentativa por ponteiro.
	// -------------------------------------------------
	Eduardo *edu = malloc(sizeof(Eduardo));
	printf("\n\n");

	inicia(edu);
	printa(edu);

	printf("\n\n");


	// -------------------------------------------------
	// 2. Tentativa por construção direta da instância.
	Eduardo edu;
	printf("\n\n");

	inicia(&edu);
	printa(&edu);

	printf("\n\n");

	printf("O valor não muda: %d\n\n", edu.idade);

	return 0;
}