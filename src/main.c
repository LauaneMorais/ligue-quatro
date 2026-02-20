#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "robotnivel1.h"
#include "verificarcolunas.h"
#include "vitoria.h"
#include "display.h" 
#include "robotnivel2.h"
#include "robotnivel3.h"

int main()
{
    
    srand(time(NULL));

    int tabuleiro[6][7] = {0};
    int modo_de_jogo;
    int jogada;

    
    // limpa o que estiver na tela nates de começar uma rodada
    limparTela(); 
    printf("1 -> PLAYER VS. PLAYER\n");
    printf("2 -> PLAYER VS. ROBO\n");
    printf("3 -> ROBO VS. ROBO\n");
    
    printf("Escolha o modo de jogo: ");
    scanf("%d", &modo_de_jogo);
    
    int nivelRobo1 = 1, nivelRobo2 = 1; 
    
    if (modo_de_jogo == 2) {
        printf("\nEscolha o nivel do robô (1-Baixa, 2-Media, 3-Alta): ");
        scanf("%d", &nivelRobo1);
    } 
    else if (modo_de_jogo == 3) {
        printf("\nEscolha o nivel do robô I (1-Baixa, 2-Media, 3-Alta): ");
        scanf("%d", &nivelRobo1);
        printf("Escolha o nivel do robô II (1-Baixa, 2-Media, 3-Alta): ");
        scanf("%d", &nivelRobo2);
    }

    int jogador = 1;

    while(1){
        
        limparTela();
        imprimirTabuleiro(tabuleiro); 
        // ------------------------------------

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
            else {
                printf("Jogada do Robo (Nivel %d)!\n", nivelRobo1);
                
                if (nivelRobo1 == 3) jogada = robotnivel3(tabuleiro, jogador);
                else if (nivelRobo1 == 2) jogada = robotnivel2(tabuleiro, jogador);
                else jogada = robotnivel1();
                
                verificarcolunas(tabuleiro, jogada, jogador);
            }

            sleep(1);
        }

        else if(modo_de_jogo == 3){
            
            int nivelAtual = (jogador == 1) ? nivelRobo1 : nivelRobo2;
            printf("Jogada do Robo[%d] (Nivel %d)!\n", jogador, nivelAtual);
            
            if (nivelAtual == 3) jogada = robotnivel3(tabuleiro, jogador);
            else if (nivelAtual == 2) jogada = robotnivel2(tabuleiro, jogador);
            else jogada = robotnivel1();
            
            printf("Robo escolheu a coluna -> [%d]\n", jogada);
            verificarcolunas(tabuleiro, jogada, jogador);

            sleep(1);
        }

        else{
            printf("Modo de jogo nao reconhecido, digite novamente: ");
        }

        // verifica vitoria APOS jogar
        int resultado = vitoria(tabuleiro, jogador);

        if(resultado == 1){
            limparTela();              
            imprimirTabuleiro(tabuleiro); 

            printf("PARABÉNS! JOGADOR %d VENCEU!\n", jogador);
            printf("\nPressione ENTER para sair...");
            getchar(); getchar(); // primeiro enter limpa, o segundo sai do jogo
            break;
        }
        else if(resultado == 2){
            limparTela();              
            imprimirTabuleiro(tabuleiro); 
            
            printf("EMPATE! O TABULEIRO ENCHEU.\n");
            getchar(); getchar();
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