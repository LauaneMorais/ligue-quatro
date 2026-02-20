#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

    // limpa o que estiver na tela antes de começar
    limparTela(); 
    printf("1 -> PLAYER VS. PLAYER\n");
    printf("2 -> PLAYER VS. ROBO\n");
    printf("3 -> ROBO VS. ROBO\n");
    
    // validação do modo de jogo
    do {
        printf("Escolha o modo de jogo: ");
        if (scanf("%d", &modo_de_jogo) != 1) {
            printf("Erro: Digite apenas numeros!\n");
            while(getchar() != '\n'); //limpa buffer
            modo_de_jogo = 0; 
        } else if (modo_de_jogo < 1 || modo_de_jogo > 3) {
            printf("Erro: Opção inválida! Escolha 1, 2 ou 3.\n");
        }
    } while (modo_de_jogo < 1 || modo_de_jogo > 3);
    
    int nivelRobo1 = 1, nivelRobo2 = 1; 
    
    if (modo_de_jogo == 2) {
        //validacao do nivel do robo
        do {
            printf("\nEscolha o nível do robô (1-Baixa, 2-Média, 3-Alta): ");
            if (scanf("%d", &nivelRobo1) != 1) {
                printf("Erro: Digite apenas numeros!\n");
                while(getchar() != '\n');
                nivelRobo1 = 0;
            } else if (nivelRobo1 < 1 || nivelRobo1 > 3) {
                printf("Erro: Nível invalido! Escolha 1, 2 ou 3.\n");
            }
        } while (nivelRobo1 < 1 || nivelRobo1 > 3);
    } 
    else if (modo_de_jogo == 3) {
        do {
            printf("\nEscolha o nível do robô 1 (1-Baixa, 2-Média, 3-Alta): ");
            if (scanf("%d", &nivelRobo1) != 1) {
                printf("Erro: Digite apenas numeros!\n");
                while(getchar() != '\n');
                nivelRobo1 = 0;
            } else if (nivelRobo1 < 1 || nivelRobo1 > 3) {
                printf("Erro: Nível invalido! Escolha 1, 2 ou 3.\n");
            }
        } while (nivelRobo1 < 1 || nivelRobo1 > 3);

        do {
            printf("Escolha o nível do robô 2 (1-Baixa, 2-Média, 3-Alta): ");
            if (scanf("%d", &nivelRobo2) != 1) {
                printf("Erro: Digite apenas numeros!\n");
                while(getchar() != '\n');
                nivelRobo2 = 0;
            } else if (nivelRobo2 < 1 || nivelRobo2 > 3) {
                printf("Erro: Nível invalido! Escolha 1, 2 ou 3.\n");
            }
        } while (nivelRobo2 < 1 || nivelRobo2 > 3);
    }

    int jogador = 1;

    while(1){
        
        limparTela();
        imprimirTabuleiro(tabuleiro); 
        // ------------------------------------

        if(modo_de_jogo == 1){
            printf("Jogada do Player[%d]: ", jogador);
            if (scanf("%d", &jogada) != 1) {
                printf("Erro: Entrada inválida! Digite apenas números.\n");
                while(getchar() != '\n'); // limpa buffer do teclado
                printf("Pressione ENTER para tentar novamente...");
                getchar(); 
                continue;
            }
            int sucesso = verificarcolunas(tabuleiro, jogada, jogador);
            if (sucesso == 0) {
                printf("Pressione ENTER para tentar novamente...");
                while(getchar() != '\n'); 
                getchar(); // pausa a tela
                continue;
            }
        }
        
        else if(modo_de_jogo == 2){
            if(jogador == 1){
                printf("Jogada do Player[%d]: ", jogador);
                if (scanf("%d", &jogada) != 1) {
                    printf("Erro: Entrada inválida! Digite apenas números.\n");
                    while(getchar() != '\n');
                    printf("Pressione ENTER para tentar novamente...");
                    getchar();
                    continue;
                }
                int sucesso = verificarcolunas(tabuleiro, jogada, jogador);
                if (sucesso == 0) {
                    printf("Pressione ENTER para tentar novamente...");
                    while(getchar() != '\n');
                    getchar();
                    continue;
                }
            }
            else{
                printf("Jogada do Robô (nível %d)!\n", nivelRobo1);
                
                // escolhendo a ia
                if (nivelRobo1 == 3) jogada = robotnivel3(tabuleiro, jogador);
                else if (nivelRobo1 == 2) jogada = robotnivel2(tabuleiro, jogador);
                else jogada = robotnivel1();
                
                printf("O Robô escolheu a coluna -> [%d]\n", jogada);
                int sucesso = verificarcolunas(tabuleiro, jogada, jogador);
                if (sucesso == 0) continue;
            }
        }
        else if(modo_de_jogo == 3){

            int nivelAtual = (jogador == 1) ? nivelRobo1 : nivelRobo2;
            printf("Jogada do Robô[%d] (nível %d)!\n", jogador, nivelAtual);
            
            // escolhendo a ia
            if (nivelAtual == 3) jogada = robotnivel3(tabuleiro, jogador);
            else if (nivelAtual == 2) jogada = robotnivel2(tabuleiro, jogador);
            else jogada = robotnivel1();
            
            printf("O Robô escolheu a coluna -> [%d]\n", jogada);
            int sucesso = verificarcolunas(tabuleiro, jogada, jogador);
            if (sucesso == 0) continue;
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