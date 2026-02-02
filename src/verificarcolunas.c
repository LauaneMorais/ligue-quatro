#include <stdio.h>
#include "verificarcolunas.h"

void verificarcolunas(int tabuleiro[6][7], int jogada, int jogador)
{
    // em matrizes e vet, a contagem comeca do 0, mas para ficar melhor pro usuario, ele vai selecionar de 1 a 7

    jogada -= 1; // vai fazer com que seja melhor para o usuario visualizar as colunas de 1 a 7 e nao de 0 a 6

    int espacos;

    for(int i=0; i<7; i++){ 
        espacos = 0;
        for(int j=0; j<6; j++){
            if((i == jogada) && (tabuleiro[j][i] == 0)){
                espacos++;
            }
        }
        if(i == jogada && espacos > 0){
            printf("Jogada feita na coluna [%d] pelo Player %d!\n", i+1, jogador);
            for(int k=5; k>=0; k--){
                if(tabuleiro[k][i] == 0){
                    tabuleiro[k][i] = jogador; // sera colocado 1 ou 2 respresentando o numero do jogador
                    break;
                }
            }
            break;
        }
        else if(i == jogada && espacos == 0){
            printf("Essa coluna [%d] nao esta disponivel para jogada!\n", i+1);
            break;
        }
    }

}