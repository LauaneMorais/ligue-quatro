#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    int tabuleiro[6][7] = {    // caso teste = colunas disponiveis[1, 2, 4, 5, 7]
        {0, 0, 1, 0, 0, 1, 0}, // caso teste = colunas indisponiveis[3, 6]
        {0, 0, 2, 0, 0, 2, 0}, 
        {0, 0, 2, 0, 0, 2, 0}, 
        {0, 0, 1, 1, 0, 1, 0}, 
        {0, 0, 2, 2, 0, 2, 0}, 
        {1, 0, 1, 1, 2, 1, 2}};

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
        if(i== jogada && espacos > 0){
            printf("Essa coluna [%d] esta disponivel para jogada!\n", i+1);
            break;
        }
        else if(i == jogada && espacos == 0){
            printf("Essa coluna [%d] nao esta disponivel para jogada!\n", i+1);
            break;
        }
    }

    return 0;
}