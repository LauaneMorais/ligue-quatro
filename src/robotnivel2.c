#include <stdio.h>
#include "robotnivel2.h"
#include "robotnivel1.h"


int validarGravidade(int tabuleiro[6][7], int linha, int coluna) {
    
    //validaçoes para o robo nao tentar bloquear peças que nao são importantes
    if (tabuleiro[linha][coluna] != 0) return 0;
    if (linha == 5) return 1;
    if (tabuleiro[linha + 1][coluna] != 0) return 1;
    
    return 0; 
}

int robotnivel2(int tabuleiro[6][7], int jogadorIA) {
    int oponente = (jogadorIA == 1) ? 2 : 1; //se ia for 1, alvo é 2, vice versa
    int jogadasOponente = 0;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (tabuleiro[i][j] == oponente) jogadasOponente++;
        }
    }
    printf("IA II: Oponente já fez %d jogadas. Analisando...\n", jogadasOponente);


    //analisa se o jogador vai ganhar na vertical
    for (int j = 0; j < 7; j++) {
        for (int i = 0; i < 3; i++) { 
            if (tabuleiro[i+1][j] == oponente && 
                tabuleiro[i+2][j] == oponente && 
                tabuleiro[i+3][j] == oponente) {
                if (tabuleiro[i][j] == 0) { 
                    return j + 1;
                }
            }
        }
    }

    // se nenhum condicional for executado, realiza uma jogada aleatoria tal qual a IA I
    return robotnivel1(); 
}