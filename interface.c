#include <stdio.h>


int main () {
    printf("\033[H\033[J"); //limpa a tela antes de recarregar qualquer coisa

    int matriz[6][7];
    
    for (int i = 0; i < 7; i++) { // imprime os numeros
        printf(" %d", i+1);
    }

    printf("\n");

    for (int i = 0; i < 15; i++) {
        printf("_", matriz[0][i]); // impressao do teto da matriz
    }

    printf("\n");

    for(int i=0; i<6; i++){ 

        for(int j=0; j<7; j++){

            printf ("|", matriz[i][j]);
            printf ("_", matriz[i][j]); //impressao do tabuleiro

        }
        printf ("|\n");
    }
    return 0;
}
