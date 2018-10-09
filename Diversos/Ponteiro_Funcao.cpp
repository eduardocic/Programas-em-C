#include <iostream>
using namespace std;


// Função que realiza a SOMA de dois números inteiros.
int soma (int i, int j){
	return (i+j);
}


// Função que realiza a PRODUTO de dois números inteiros.
int produto (int i, int j){
	return (i*j);
}


// Função que recebe DOIS inteiros + um ponteiro para 
// função (que recebe DUAS variáveis do tipo inteiro e
// retorna um inteiro)
int opera (int i, int j, int (*op)(int, int)){
	return op(i, j);
}


int main(void){

	// Iniciação das variáveis.
	int i = 3;
	int j = 4;

	// =====================================================
	// Defino um ponteiro para função.
	//
	// No caso, o que a gente tem é um ponteiro (vide o '*')
	// que para caracterizar que é um ponteiro para função
	// está entre parênteses, ou seja, entre '(' e ')'.
	// Dessa forma, '(*ptr_funcao)' escrito dessa forma, 
	// significa dizer que é um ponteiro para função.
	// 
	// Este ponteiro em específico aponta para uma função, 
	// mas não são todas as classes de funções. São funções 
	// que recebem DOIS valores do tipo inteiros e 
	// retorna UM valor também do tipo inteiro.
	// =====================================================
	int (*ptr_funcao)(int, int);

	// =====================================================
	// Aqui eu faço o meu ponteiro apontar para a função
	// 'soma'. A função 'soma' é uma função que recebe 
	// dois valores do tipo inteiro e retorna um valor
	// do tipo inteiro.
	// =====================================================
	ptr_funcao = soma;
	cout << "A soma é: " << ptr_funcao(i, j) << endl;
	
	// =====================================================
	// Equivalentemente ao que foi feito com a função soma,
	// eu irei fazer o ponteiro agora apontar para a função 
	// 'produto'.
	// =====================================================
	ptr_funcao = produto;
	cout << "O produto é: " << ptr_funcao(i, j) << endl;
	cout << "\n";


	// =====================================================
	// No caso, eu faço as mesmas operaçõs acima por meio 
	// do acesso via função.
	cout << "SOMA " << opera(i, j, soma) << endl;
	cout << "PRODUTO: " << opera(i, j, produto) << endl;
	// =====================================================

	return 0;
}