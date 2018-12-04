#include <stdio.h>

typedef union{
    float d_f;
    unsigned char d_c[sizeof(float)];
} float_d;

typedef union{
    int d_i;
    unsigned char d_c[sizeof(float)];
} int_d;

unsigned char CharToHex( char c )
{
    switch( c ) {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case 'a': case 'A': return 10;
        case 'b': case 'B': return 11;
        case 'c': case 'C': return 12;
        case 'd': case 'D': return 13;
        case 'e': case 'E': return 14;
        case 'f': case 'F': return 15;
    }
}

int main(void){

    /* Arquivo de leitura */
    FILE *p_read;
	p_read = fopen("mydata.txt", "r");

    if(!p_read){
        printf("Arquivo 'mydata.txt' aberto com sucesso\n");
        printf("-----------------------------------------\n\n");
    }

    /* Arquivo de escrita */
    FILE *p_write;
    p_write = fopen("saida.txt","w");

    if(!p_write){
        printf("Arquivo 'saida.txt' criado com sucesso\n");
        printf("-----------------------------------------\n\n");
    }

    char flag;
    int  i = 0;
    unsigned char buffer[20];
    float_d flutuante;
    int_d   inteiro;

    do{
        flag = fgetc(p_read);
        if (flag == ' '){
        }
        else {
            buffer[i] = CharToHex(flag);
            i++;
        }  
        if ( i == 12){
            inteiro.d_c[0] = (buffer[0] << 4) | buffer[1];
            inteiro.d_c[1] = (buffer[2] << 4) | buffer[3];
    
            flutuante.d_c[0] = (buffer[ 4] << 4) | buffer[ 5];
            flutuante.d_c[1] = (buffer[ 6] << 4) | buffer[ 7];
            flutuante.d_c[2] = (buffer[ 8] << 4) | buffer[ 9];
            flutuante.d_c[3] = (buffer[10] << 4) | buffer[11];

            fprintf(p_write, "%d  ",  inteiro.d_i);
            fprintf(p_write, "%f\n",  flutuante.d_f);
        }
        if (flag == '\n'){
            i = 0;
        }
    }
    while( flag != EOF);

    fclose(p_read);
    fclose(p_write);

    return 0;
}