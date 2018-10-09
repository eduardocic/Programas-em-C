#include <iostream>

using namespace std;

// A função MAIN receberá dois argumentos:
//
// 1. argc (do tipo inteiro); e
// 2. *argv[] (do tipo char).
int main(int argc, char *argv[]){


	cout << "Quant. de entradas: " << argc << endl;
	// =================================================
	// No caso, a ideia de você receber um argumento
	// do tipo char. Caso você deseja a entrada de algum
	// número você tem de converter a string 
	// representativa do número em um número em si.
	//
	// No caso, eu irei apenas fazer a impressão das 
	// variáveis de entrada, inclusive a chamada da 
	//função;
	// =================================================
	for (int i = 0; i <= argc; i++){
		cout << argv[i] << endl;		
	}

	return 0;
}