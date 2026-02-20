#include <stdio.h>

void resetarTabuleiro (int matriz[6][7]){

    for (int i=0;i<6;i++){
        for (int j=0;j<7;j++){
            matriz [i][j]=0;
        }

    }
}

void exibirTabuleiro (int matriz [6][7]){
    printf("\n");
    printf("  1   2   3   4   5   6   7\n");
    printf("-----------------------------\n");

    for (int i = 0; i < 6; i++) {
        printf("|");
        for (int j = 0; j < 7; j++) {
            if (matriz[i][j] == 0) {
                printf(" . |"); //se pá?
            } else {
                printf(" %d |", matriz[i][j]);
            }
        }
        printf("\n-----------------------------\n");
    }
}

int main(){
    int matriz [6][7];

    for (int i=0;i<6;i++){
        for (int j=0;j<7;j++){
            matriz [i][j]=0;
        }
}
exibirTabuleiro(matriz);
}