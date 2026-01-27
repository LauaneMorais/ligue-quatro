#include <stdio.h>

int main(int argc, char const *argv[])
{
    // teste = apenas o jogador 1 esta jogando

    int tabuleiro[6][7] = {0};

    int jogada;

    printf("Escolha a coluna que ira jogar: ");

    scanf("%d", &jogada);
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
            printf("Essa coluna [%d] esta disponivel para jogada!\n", i+1);
            for(int k=5; k>=0; k--){
                if(tabuleiro[k][i] == 0){
                    tabuleiro[k][i] = 1; // sera colocado 1 pq apenas o jogador 1 esta jogando
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

    printf("%d", tabuleiro[5][jogada]); // so pra testar se a gravidade funcionou

    return 0;
}