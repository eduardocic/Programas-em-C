#include <stdio.h>
#include "funcoes.h"


/****************************************************************** 
 * Criação de uma UNION no sentido de compartilhar o mesmo espaço
 * de memória para dados do tipo 'float' e 'int' com estruturas
 * do tipo 'unsigned char'. Em cima dessas estruturas que eu 
 * faço o shift de bits de forma a caber todos os dados que chegam
 * separados por nibble em um único unsigned char 
 *
 * Eduardo H. Santos.
 * 04/12/2018
 ******************************************************************/
typedef union{
    float d_f;
    unsigned char d_c[sizeof(float)];
} float_d;

typedef union{
    int d_i;
    unsigned char d_c[sizeof(float)];
} int_d;


int main(void){
	
    /************************************************************/
    /* Leitura de arquivo '*.txt' */
    FILE *p_read;
	p_read = fopen("mydata.txt", "r");

    if ( !p_read ){
        printf("Arquivo 'mydata.txt' não pode ser aberto.\n");
    }

    /* Escrita em arquivo '*.txt' */
    FILE *p_write;
    p_write = fopen("saida.txt","w");

    if(!p_write){
        printf("Arquivo 'saida.txt' não pode ser criado.\n");
    }
    /************************************************************/


    char flag;
    int  i = 0;
    unsigned char buffer[20];
    float_d flutuante;
    int_d   inteiro;

    do{
	/* pega caracter a caracter */
        flag = fgetc(p_read);

	/* Se tiver espaço no original ou mesmo algum tipo de 		   vírgula, eu simplesmente não leio */
        if (flag == ' '){
        }
	
	/* Faço a conversão do valor 'char' lido para 'hexa' e
           vou preenchendo o buffer */
        else {
            buffer[i] = CharToHex(flag);
            i++;
        }  
 
        /* Se chegar no limite da linha estipulada, a ideia é
           é realizar o ajuste dos parâmetros das 'nibbles' */
        if ( i == 12){
            inteiro.d_c[0]   = (buffer[ 0] << 4) | buffer[ 1];
            inteiro.d_c[1]   = (buffer[ 2] << 4) | buffer[ 3];
            flutuante.d_c[0] = (buffer[ 4] << 4) | buffer[ 5];
            flutuante.d_c[1] = (buffer[ 6] << 4) | buffer[ 7];
            flutuante.d_c[2] = (buffer[ 8] << 4) | buffer[ 9];
            flutuante.d_c[3] = (buffer[10] << 4) | buffer[11];

	    /* Fiz a justaposição dos números à direita.	
	       No caso eu deixeo um único espaço entre eles,
	       no caso de aparecer algum número negativo */
            fprintf(p_write, "%5d",  inteiro.d_i);
            fprintf(p_write, "%10f\n",  flutuante.d_f);
        }

	/* Se tiver a pulada de linha, eu começo tudo novamente */
        if (flag == '\n'){
            i = 0;
        }
    }
    while( flag != EOF);

    fclose(p_read);
    fclose(p_write);

    return 0;
}
