#include <stdio.h>
#include "vitoria.h"

// Funcoes auxiliares (internas) para diagonais
int checarDiagonais(int matriz[6][7], int jogador) {
    // Diagonal Principal (descendo para direita)
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            if(matriz[i][j] == jogador && 
               matriz[i+1][j+1] == jogador &&
               matriz[i+2][j+2] == jogador &&
               matriz[i+3][j+3] == jogador){
                return 1;
            }
        }
    }
    // Diagonal Secundaria (subindo para direita - ou descendo para esquerda)
    for(int i=5; i>=3; i--){
        for(int j=0; j<4; j++){
            if(matriz[i][j] == jogador &&
               matriz[i-1][j+1] == jogador &&
               matriz[i-2][j+2] == jogador &&
               matriz[i-3][j+3] == jogador){
                return 1;
            }
        }
    }
    return 0;
}

int vitoria(int tabuleiro[6][7], int jogador){
    int cont;

    // verifica horizontal
    for(int i=0; i<6; i++){
        cont = 0;
        for(int j=0; j<6; j++){
            if(tabuleiro[i][j] == jogador && tabuleiro[i][j+1] == jogador){
                cont++;
            } else {
                cont = 0;
            }
            if(cont >= 3) {
                printf("Jogador [%d] venceu na horizontal!\n", jogador);
                return 1;
            }
        }
    }

    // verifica vertical
    for(int i=0; i<7; i++){
        cont = 0;
        for(int j=0; j<5; j++){  
            if(tabuleiro[j][i] == jogador && tabuleiro[j+1][i] == jogador){
                cont++; 
            } else {
                cont = 0;
            }
            if(cont >= 3){
                printf("Jogador [%d] venceu na vertical!\n", jogador);
                return 1;
            }
        }
    }

    // chamando a funcao auxiliar das diagonais
    if(checarDiagonais(tabuleiro, jogador)) {
        printf("Jogador [%d] venceu na diagonal!\n", jogador);
        return 1;
    }

    int espaco_vazio = 0;
    for(int i=0; i<6; i++){
        for(int j=0; j<7; j++){
            if(tabuleiro[i][j] == 0){
                espaco_vazio = 1;
                break;
            }
        }
    }

    if(espaco_vazio == 0){
        printf("Houve um empate, fim de jogo!\n");
        return 2;
    }

    return 0; // Jogo continua
}