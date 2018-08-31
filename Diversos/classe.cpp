#include <iostream>

using namespace std;


typedef enum{
	HOMEM   = 0,
	MULHER  = 1
} Genero;


typedef struct{
	Genero gen;
	int idade;
	float altura;
} Pessoa;


class Eduardo{
	public:
		Pessoa pessoa;
};


int main(void){
	
	Eduardo *p = new Eduardo;
	p->pessoa.idade = 10;
	cout << "A idade é " << p->pessoa.idade << endl;
	return 0;
}