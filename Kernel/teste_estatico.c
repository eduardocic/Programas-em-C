#include <stdio.h>

int estatico (){
    static int i = 0;
    i++;
    return i;
}

int main(void){

    for (int k=0; k < 10 ;k++){
        printf("O valor é: %d\n", estatico());
    }

    printf("\n\n");
    return 0;
}