#include <stdio.h>
#include <stdlib.h>
#include "display.h" 

void limparTela() {
    printf("\033[H\033[J");
}

void imprimirTabuleiro(int matriz[6][7]) {
    printf("\n");
    for (int i = 0; i < 7; i++) {
        printf("  %d ", i+1);
    }
    printf("\n");

    for(int i = 0; i < 6; i++) { 
        for(int j = 0; j < 7; j++) {
            printf("|"); 
            if(matriz[i][j] == 0) {
                printf(" . "); 
            }
            else if(matriz[i][j] == 1) {
                printf("\033[31m O \033[0m"); // vermelho
            }
            else if(matriz[i][j] == 2) {
                printf("\033[33m O \033[0m"); // amarelo
            }
        }
        printf("|\n");
    }
    printf("-----------------------------\n");
}