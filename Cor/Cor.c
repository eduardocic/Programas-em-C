#include <stdio.h>

#define VERMELHO   "\x1b[31m"
#define VERDE      "\x1b[32m"
#define AMARELO    "\x1b[33m"
#define AZUL       "\x1b[34m"
#define MAGENTA    "\x1b[35m"
#define CIANO      "\x1b[36m"
#define RESET      "\x1b[0m"

#define trace(cor, ...) {printf(cor "%s", __VA_ARGS__); printf(RESET);}

int main () {

    /****************************************************************
    * Fazendo a impressão do sistema de tal forma a alterar as cores.
    * 
    * No caso, a gente apresentará o texto na cor especificada e 
    * depois a gente reseta a cor. 
    ****************************************************************/
    printf(VERMELHO  "Este texto é VERMELHO!"  RESET "\n");
    printf(VERDE     "Este texto é VERDE!"     RESET "\n");
    printf(AMARELO   "Este texto é AMARELO!"   RESET "\n");
    printf(AZUL      "Este texto é AZUL!"      RESET "\n");
    printf(MAGENTA   "Este texto é MAGENTA!"   RESET "\n");
    printf(CIANO     "Este texto é CIANO"      RESET "\n");

    /****************************************************************
    * Apresentação da cor por meio da MACRO 'trace' lá de cima.
    ****************************************************************/ 
    trace(AZUL, "Eduardo \n");

    return 0;
}