#include <stdio.h>

/*****************************************************
 * O que será abordado aqui diz respeito ao que eu 
 * tenho visto no Kernel do Linux e também em estru-
 * turas de inicialização para driver (quando falando
 * de baixo nível). Algumas funcionalidades interes-
 * santes a mais têm sido incorporadas ao padrão C99+
 * os quais eu gostaria de abordar aos poucos.
 * 
 * -- A primeira delas diz respeito ao "Designated 
 *    Initializers". Material de estudo e referência
 *    pode ser visualizado nos seguintes sites:
 * 
 * 1. 'http://gcc.gnu.org/onlinedocs/gcc/Designated-Inits.html'
 * 2. 'https://www.geeksforgeeks.org/designated-initializers-c/'
 * 
 * Vamos aos exemplos.
 *****************************************************/
typedef struct {
    char *nome;
    int idade;
    float altura;
} pessoa;

int main(void){
/******************************************************
 * Esta primeira parte diz respeito à forma de inicia-
 * lizar um vetor de array.
 * 
 * -- No caso, a gente pode inicializar de acordo com
 *    a seguinte regra:
 *      a) escreva ‘[index] =’ or ‘[index]’ antes do 
 *         valor a ser atribuído a ele;
 *****************************************************/
int numeros[] = {1, 2, 3, [3 ... 9] = 10,
                 [10] = 80,
                  15, 
                 [22] = 400,
                 [31] = 50 }; 

/* Nessa configuração de inicialização do array de nome
   'numeros', perceba que na posição de index zero, ou 
   seja, numero[0] = 1; para a posição de index 1, será 
   o valor 2, ou seja, numero[1] = 2 etc. Eu posso fazer
   isso sem especificar o tamanho do array ou especifi-
   cando. No caso, eu deixei livre, ou seja 'numeros[]'.
   Poderia obviamente dizer que tem tamanho qualquer de
   forma que o restante dos termos todos seriam inicia-
   lizados como '0'.
   O resultado do array acima está apresentado abaixo */

printf("============================\n");
printf("Impressão do array 'numeros'\n\n");
for (int i = 0; i < (sizeof(numeros)/sizeof(int)); i++){
    printf("numeros[%d] = %d\n", i, numeros[i]);
}

/* Poderia ao invés de escrever o array conforme coloca-
   acima, escrever ele da forma como especificado sem o
   '='. Veja o exemplo abaixo.
   Nele eu trequei a ordem apenas de inicialização dos
   termos (veja os de index 31 e 22) e retirei os iguais */
int numeros2[] = {1, 2, 3, [3 ... 9]10,
                 [10]80,
                  15, 
                 [31]50,
                 [22]400}; 

printf("\n\n\n=============================\n");
printf("Impressão do array 'numeros2'\n\n");
for (int i = 0; i < (sizeof(numeros2)/sizeof(int)); i++){
    printf("numeros2[%d] = %d\n", i, numeros2[i]);
}

/******************************************************
 * O trabalho agora será voltado para a parte de inici-
 * alização de 'struct'. Ela se dará de uma forma dife-
 * rente mas bem direta: '.fieldname ='. Após o '=' a 
 * gente coloca apenas o que deseja instanciar.
 * 
 * Para a estrutura 'pessoa' definida logo acima, veja
 * como que funcionaria.
 *****************************************************/
pessoa p = { 
    .nome   = "Eduardo",
    .idade  = 30,
    .altura = 1.79        
};

printf("\n\n=====================================\n");
printf("Imprimindo os elementos da estrutura.\n");
printf("Nome:   %s\n", p.nome);
printf("Idade:  %d\n", p.idade);
printf("Altura: %.2f\n\n", p.altura);


/*A outra abordagem eu fui mais direto */
pessoa p2 = {"Eduardo", 20, 2.00};
printf("\n\n=====================================\n");
printf("Imprimindo os elementos da estrutura.\n");
printf("Nome:   %s\n", p2.nome);
printf("Idade:  %d\n", p2.idade);
printf("Altura: %.2f\n\n", p2.altura);
/* Maiores detalhes você pode pegar diretamente nos
   links já abordados acima. */
}

