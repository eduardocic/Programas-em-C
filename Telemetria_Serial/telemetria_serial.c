#include <stdio.h>

/*******************************************************
 *   Este programa utiliza das variáveis para análise
 * de telemetria de sistema. No caso, o que a gente
 * recebe é um calhamaço de bytes. É importante, então
 * que a gente faça a gestão desses dados de forma a 
 * que os dados recebidos sejam incorporados de maneira
 * precisa nos seus respectivos valores.
 * 
 *   A ideia é, em C, fazer a caracterização dos valo-
 * res que chegam. No caso, os valores chegam como trem
 * de bytes e a ideia é separar esse conjunto e colocar
 * todos os parâmetros dentro da sua métrica. No caso, 
 * o pessoalusa o 'memcpy' para copiar e depois nominar
 * os parâmetros de acordo com os dados enviados.
 * 
 *   A ideia é passar um numero real e verificar se eu
 * consigo realmente reconstruir o mesmo número lá na 
 * frente.
 * 
 * 
 * Eduardo H. Santos.
 * 13 de Nov. 2018
 *******************************************************/

/* Union para caracterização de parâmetros do tipo 
 * 'float'. No caso, se fosse um aceleração eu precisa-
 * ria de parâmetros tais que abarcassem dentro dos 
 * 32 bits (representação do float)*/
typedef union {
    float real;
    unsigned char byte[sizeof(float)];
} acel;


/* Estrutura de dados que salva os paremetros do sistema
 * recebido. No caso, eu poderia encadear um monte de in-
 * formação dentro da estrutura de dados. No caso, se 
 * fosse, por exemplo, um acelerômetro com dados passados
 * via serial, eu teria que pegar os bites de cada um 
 * desses dados e remetê-los ao sistema sem maiores
 * problemas */
typedef struct{
    acel X;
    acel Y;
    acel Z;
    int index;
} dado;


int main(void){ 
    /* Valores lidos pelo acelerômetro, e que são passados
     * para o microcontrolador. A ideia é quebrar esse 
     * número float em seus respectivos bytes. Em seguida,
     * enviar esses números para uma porta Serial que em 
     * seguida lerá esses núremos na outra ponta.*/
    float acel_x = 1.234;
    float acel_y = -0.982;
    float acel_z = 0.00007;

    /* Criação da estrutura para envio */
    dado send;
    
    /* Quebra do número do tipoo 'float' */
    send.X.real = acel_x;
    send.Y.real = acel_y;
    send.Z.real = acel_z;

    /* Apenas para pegar os valores e verificar se realmente
     * houve a quebra doos bytes de acordo com o que preconiza
     * a 'union' */
    printf("\n\nAceleração 'X' é: %f \n", send.X.real);
    printf("bit 0 de X: %.2X\n",     send.X.byte[0]);
    printf("bit 1 de X: %.2X\n",     send.X.byte[1]);
    printf("bit 2 de X: %.2X\n",     send.X.byte[2]);
    printf("bit 3 de X: %.2X\n\n\n", send.X.byte[3]);

    printf("Aceleração 'Y' é: %f \n", send.Y.real);
    printf("bit 0 de Y: %.2X\n",     send.Y.byte[0]);
    printf("bit 1 de Y: %.2X\n",     send.Y.byte[1]);
    printf("bit 2 de Y: %.2X\n",     send.Y.byte[2]);
    printf("bit 3 de Y: %.2X\n\n\n", send.Y.byte[3]);

    printf("Aceleração 'Z' é: %f \n", send.Z.real);
    printf("bit 0 de Z: %.2X\n",     send.Z.byte[0]);
    printf("bit 1 de Z: %.2X\n",     send.Z.byte[1]);
    printf("bit 2 de Z: %.2X\n",     send.Z.byte[2]);
    printf("bit 3 de Z: %.2X\n\n\n", send.Z.byte[3]);

    /*****************************************************
     * Criação da estrutura para recebimento 
     * 
     * Aqui poderia ser utilizado alguma estratégia com 
     * o memcpy. Isso possibilitaria criar uma estratégia
     * de verificação dos bits enviados e recebidos.
     ****************************************************/
    dado rec;

    /* Após esses bytes serem recebidos em uma outra 
     * a ideia é fazer valer esses números de tal forma
     * que agora você pode reconstruir os mesmo */
    rec.X.byte[0] = send.X.byte[0];
    rec.X.byte[1] = send.X.byte[1];
    rec.X.byte[2] = send.X.byte[2];
    rec.X.byte[3] = send.X.byte[3];

    rec.Y.byte[0] = send.Y.byte[0];
    rec.Y.byte[1] = send.Y.byte[1];
    rec.Y.byte[2] = send.Y.byte[2];
    rec.Y.byte[3] = send.Y.byte[3];

    rec.Z.byte[0] = send.Z.byte[0];
    rec.Z.byte[1] = send.Z.byte[1];
    rec.Z.byte[2] = send.Z.byte[2];
    rec.Z.byte[3] = send.Z.byte[3];

    printf("\nApós recebido, imprime X: %f\n", rec.X.real);
    printf("Após recebido, imprime Y: %f\n", rec.Y.real);
    printf("Após recebido, imprime Z: %f\n\n", rec.Z.real);

    return 0;
}