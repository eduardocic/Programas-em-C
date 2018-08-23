#include <stdio.h>
#include <stdlib.h>

/***********************************************
* Definindo uma célula. No caso eu estou 
* definindo da forma mais direta possível. Você
* pode fazer da forma padrão. que é especificada
* como
*
*  struct reg {
*       int         conteudo; 
*       struct reg *prox;
*  };
*
* typedef struct reg celula;
***********************************************/
typedef struct reg {
      int         conteudo; 
      struct reg *prox;
} celula;


/**********************************************
* Esta função é responsável por imprimir os 
* os conteúdos das listas.
*
* o 'Lista' -- Lista Encadeada.
***********************************************/
void imprime (celula *Lista) {
   if (Lista != NULL) {
      printf ("O conteúdo é: %d\n", Lista->conteudo);
      printf ("O endereço é: %p\n\n", Lista->prox);
      imprime (Lista->prox);
   }
}


/**********************************************
* Esta função insere uma nova celula
* em uma lista encadeada. A nova celula
* tem conteudo x e é inserida entre a
* celula p e a célula seguinte.
* (Supõe-se que p != NULL.)
***********************************************/
void insere (int x, celula *p) {
   celula *nova;

   nova           = (celula *)malloc(sizeof (celula));
   nova->conteudo = x;
   nova->prox     = p->prox;
   p->prox        = nova;
}


/***********************************************
* 
* 
* 
* Cabeça da lista.
* 
* 
***********************************************/
celula *cabecaLista (int x) { 
    celula *cabeca;

    cabeca->centeudo = x;
    cabeca->prox     = NULL;

    return cabeca;
}

/***********************************************
* Fazendo a minha modificação, quero inserir um 
* elemento na cabeça da lista. Dessa forma, eu
* irei criar a minha própria função. Esta função
* retorna o endereço de uma estrutura do tipo
* 'celula' na qual indicará o primeiro elemento
* da minha Lista.
***********************************************/
celula *insereHead (int x, celula *p) {
    celula *nova;

    nova           = (celula *)malloc(sizeof (celula));
    nova->conteudo = x;
    nova->prox     = p;
}


celula *endereco(celula *p){
    return (p->prox);
}



void encontraUltimo (celula *p){

    if( (p->prox) != NULL){
        printf("Não\n");
        encontraUltimo(endereco(p));
    }
}


int main (void) {

    celula a, b;

    a.conteudo = 10;
    a.prox     = &b;
    b.conteudo = 20;
    b.prox     = NULL;


    celula *beta;
    beta = insereHead(30, &a);


    imprime(beta);

    teste(beta);
    // teste(beta);
    // teste(&a);
    // teste(&b);
    // printf("\n\n");
    // if(b.prox == NULL){
    //     printf("É o último mesmo\n");
    // }

    return 0;
}
