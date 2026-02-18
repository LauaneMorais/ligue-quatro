    #include <stdio.h>

    int main() {

        int matriz[6][7] = {0}; //correcao para a matriz nao inicializar com lixo de memoria
        int jogadorAtual = 1;   // 1 é vermelho e 2 é amareo
        int jogada;             
        int jogadasTotal = 0;   

        while(1) {
            
        
            printf("\033[H\033[J"); //limpa a tela antes de recarregar qualquer coisa

            printf("\n");
            for (int i = 0; i < 7; i++) {
                printf("  %d ", i+1);
            }
            printf("\n");

            for(int i = 0; i < 6; i++) { 
                for(int j = 0; j < 7; j++) {
                    printf("|"); 
                    if(matriz[i][j] == 0) {
                        //verificacao de espaco vazio para adicionar um elemento 
                        printf(" . "); 
                    }
                    else if(matriz[i][j] == 1) {
                        printf("\033[31m O \033[0m");
                    }
                    else if(matriz[i][j] == 2) {
                        printf("\033[33m O \033[0m");
                    }
                }
                printf("|\n");
            }
            // chao do tabuleiro
            printf("-----------------------------\n");

            // verifica se foi empate e o tabuleiro esta cheio
            if (jogadasTotal >= 42) {
                printf("empate\n");
                break;
            }

            // interacao com usuario
            printf("jogador %d, escolha uma coluna entre 1 e 7: ", jogadorAtual);
            scanf("%d", &jogada);
            jogada -= 1; 

            // validacao de coluna
            if (jogada < 0 || jogada > 6) {
                printf("coluna invalida\n");
                getchar(); getchar(); 
                continue;
            }


            if (matriz[0][jogada] != 0) {
                printf("coluna cheia\n");
                getchar(); getchar();
                continue;
            }

            
            for(int k=5; k>=0; k--){
                if(matriz[k][jogada] == 0){
                    matriz[k][jogada] = jogadorAtual; 
                    jogadasTotal++;
                    
                    if (jogadorAtual == 1) {
                        jogadorAtual = 2;
                    } else {
                        jogadorAtual = 1;
                    }
                    break; 
                }
            }
        }

        return 0;
    }