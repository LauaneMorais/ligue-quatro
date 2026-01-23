#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    // matriz pra representar o tabuleiro
    int matriz[6][7];

    // [ENTRADA] (1) -> peças vermelhas e (2) -> peças amarelas
    
    // leitura das jogadas
    for(int i=0; i<6; i++){
        for(int j=0; j<7; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    
    int cont1, cont2;

    // for para contar repetição nas linhas(horizontal)!!!
    for(int i=0; i<6; i++){
        cont1 = 0; // essas inicializações sao necessarias para que o contador nao fique com valores apos o fim do laço j
        cont2 = 0;
        for(int j=0; j<6; j++){
            if((matriz[i][j] == 1) && (matriz[i][j] == matriz[i][j+1])){
                cont1++;
            }
            else if((matriz[i][j] == 2) && (matriz[i][j] == matriz[i][j+1])){
                cont2++;
            }
            else{ // serve para evitar que sequencia 1 1 2 1 1 seja atribuida como ponto
                cont1 = 0;
                cont2 = 0;
            }

            if(cont1 >= 3){
                printf("Jogador 1 venceu na horizontal!\n");
                return 0; // esse return 0 é para evitar que o programa teste os outros casos e tava dando bug de print com o break
            }
            else if(cont2 >= 3){
                printf("Jogador 2 venceu na horizontal!\n");
                return 0;
            }
        }
    }

    // for para contar repetição nas colunas(vertical)!!!
    for(int i=0; i<7; i++){
        cont1 = 0;
        cont2 = 0;
        for(int j=0; j<5; j++){  
            if((matriz[j][i] == 1) && (matriz[j][i] == matriz[j+1][i])){
                cont1++; 
            }
            else if((matriz[j][i] == 2) && (matriz[j][i] == matriz[j+1][i])){
                cont2++;
            }
            else{
                cont1 = 0;
                cont2 = 0;
            }
            
            if(cont1 >= 3){
                printf("Jogador 1 venceu na vertical!\n");
                return 0;
            }
            else if(cont2 >= 3){
                printf("Jogador 2 venceu na vertical!\n");
                return 0;
            }
        }
    }

    return 0;
}