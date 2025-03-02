#include <stdio.h>

int main() {

    printf("\033[H\033[J"); //limpa a tela antes de recarregar qualquer coisa

    int matriz[6][7] = {0}; //correcao para a matriz nao inicializar com lixo de memoria

    //tesdtando pecinhas aleatorias
    matriz[5][0] = 1; 
    matriz[5][1] = 2; 
    matriz[4][0] = 2; 

    printf("\n");
    for (int i = 0; i < 7; i++) {
        printf("  %d ", i+1);
    }
    printf("\n");

    
    for(int i = 0; i < 6; i++) { 
        
        
        for(int j = 0; j < 7; j++) {
            
            printf("|"); 

            if(matriz[i][j] == 0) {
                //verificacao de espaco vazio para adicionar um elemento 
                printf(" . "); 
            }
            else if(matriz[i][j] == 1) {
                printf("\033[31m O \033[0m"); //vermelho
            }
            else if(matriz[i][j] == 2) {
                printf("\033[33m O \033[0m"); //amarelo
            }
        }
        
        
        printf("|\n");
    }

    // chao do tabuleiro
    printf("-----------------------------\n");

    return 0;
}