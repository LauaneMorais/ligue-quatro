#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "robotnivel1.h"
#include "verificarcolunas.h"
#include "vitoria.h"

int main(int argc, char const *argv[])
{
    
    srand(time(NULL));

    int tabuleiro[6][7] = {0};
    int modo_de_jogo;
    int jogada;

    printf("1 -> PLAYER VS. PLAYER\n");
    printf("2 -> PLAYER VS. ROBO\n");
    printf("3 -> ROBO VS. ROBO\n");

    printf("Escolha o modo de jogo: ");
    scanf("%d", &modo_de_jogo);

    int jogador = 1;

    while(1){
        
        if(modo_de_jogo == 1){
            printf("Jogada do Player[%d]: ", jogador);
            scanf("%d", &jogada);
            verificarcolunas(tabuleiro, jogada, jogador);
        }
        else if(modo_de_jogo == 2){
            if(jogador == 1){
                printf("Jogada do Player[%d]: ", jogador);
                scanf("%d", &jogada);
                verificarcolunas(tabuleiro, jogada, jogador);
            }
            else{
                printf("Jogada do Robo!\n");
                jogada = robotnivel1();
                printf("O Robo escolheu a coluna -> [%d]\n", jogada);
                verificarcolunas(tabuleiro, jogada, jogador);
            }
        }
        else if(modo_de_jogo == 3){
            printf("Jogada do Robo[%d]!\n", jogador);
            jogada = robotnivel1();
            printf("Robo[%d] escolheu a coluna -> [%d]\n", jogada);
            verificarcolunas(tabuleiro, jogada, jogador);
        }
        else{
            printf("Modo de jogo nao reconhecido, digite novamente: ");
        }
        
        if(vitoria(tabuleiro, jogador) == 1){
            // o print da funcao vitoria acontece aqui e acaba o while por conta da vitoria
            break;
        }
        else if(vitoria(tabuleiro, jogador) == 2){
            // print informando empate
            break;
        }

        if(jogador == 1){
            jogador = 2;
        }
        else{
            jogador = 1;
        }

    }

    return 0;
}
