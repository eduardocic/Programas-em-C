#include <stdio.h>

int main(void){

    /* Variáveis do meu sistema */
    float ib, ic, ie;
    float Vth, Rth;
    float Vcc;
    float Re, Rc;
    float Vc, Ve, Vce;
    int beta;

    /* A ideia é fazer variar o 'beta' para verificar
       como que se comporta a tensão Vce */
    
    Vcc = 10;
    Re  = 1000;
    Rc  = 3600;

    Rth = (2200*10000)/(2200 + 10000);
    Vth = (2200*Vcc)/(2200 + 10000);


    printf("--------------------------------------------------\n");
    printf("|     ib     |    ie     |    Ve     |   Vce    |\n");
    printf("-------------------------------------------------\n");
    for (beta = 100 ; beta <= 500 ; beta++){
        ib  = (Vth - 0.7)/(Rth + Re*beta);
        ie  = (beta + 1)*ib;
        Vc  = Vcc - Rc*ib*(beta);
        Ve  = Re*ie;
        Vce = Vc - Ve;
        printf("   %f    %f    %f    %f   \n", ib, ie, Ve, Vce);
    }
}