#include <stdio.h>

int verificarDiagonaisPrincipais (int matriz [6][7]){

    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){

        if(matriz[i][j]!=0 
            && matriz[i][j]==matriz[i+1][j+1]
            &&matriz[i][j]==matriz[i+2][j+2]
            && matriz[i][j]==matriz[i+3][j+3]){

                return matriz[i][j];
            }

        }
    }
}

int verificarDiagonaisSecundarias (int matriz [6][7]){

    for(int i=5;i>=3;i--){
        for(int j=0;j<4;j++){

        if(matriz[i][j]!=0 
            && matriz[i][j]==matriz[i-1][j+1]
            &&matriz[i][j]==matriz[i-2][j+2]
            && matriz[i][j]==matriz[i-3][j+3]){

                return matriz[i][j];
            }

        }
    }
}



