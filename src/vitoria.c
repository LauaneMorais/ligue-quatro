#include <stdio.h>
#include "vitoria.h"

int vitoria(int tabuleiro[6][7], int jogador){
    
    int cont;

    // for para contar repetição nas linhas(horizontal)!
    for(int i=0; i<6; i++){
        cont= 0; // essas inicializações sao necessarias para que o contador nao fique com valores apos o fim do laço j
        for(int j=0; j<6; j++){
            if((tabuleiro[i][j] == jogador) && (tabuleiro[i][j] == tabuleiro[i][j+1])){
                cont++;
            }
            else{ // serve para evitar que sequencia 1 1 2 1 1 seja atribuida como ponto
                cont= 0;
            }

            if(cont >= 3){
                printf("Jogador [%d] venceu na horizontal!\n", jogador);
                return 1; // esse return 0 é para evitar que o programa teste os outros casos e tava dando bug de print com o break
            }
        }
    }

    // for para contar repetição nas colunas(vertical)!!!
    for(int i=0; i<7; i++){
        cont= 0;
        for(int j=0; j<5; j++){  
            if((tabuleiro[j][i] == jogador) && (tabuleiro[j][i] == tabuleiro[j+1][i])){
                cont++; 
            }
            else{
                cont = 0;
            }
            
            if(cont>= 3){
                printf("Jogador [%d] venceu na vertical!\n", jogador);
                return 1;
            }
        }
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

    return 0;
}