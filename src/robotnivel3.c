#include <stdio.h>


int pontuarPosicao(int v1, int v2, int v3, int v4, int jogadorIA);

int avaliarTabuleiro(int matriz[6][7], int jogadorIA) {//essa função vai varrer as posições e vai chamar a função 
    int pontuacaoTotal = 0;                            //pontuar janela para pontuar cada posição.

    //varrendo coluna central
    for (int i = 0; i < 6; i++) {
        if (matriz[i][3] == jogadorIA) {
            pontuacaoTotal += 10;
        }
    }
    //varrendo colunas horizontais
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            pontuacaoTotal = pontuacaoTotal + pontuarPosicao
        (matriz[i][j], matriz[i][j+1],matriz[i][j+2],matriz[i][j+3], jogadorIA);
        }
    }

    //varrendo colunas verticais.
    for (int j = 0; j < 7; j++) {
        for (int i = 0; i < 3; i++) {
            pontuacaoTotal = pontuacaoTotal + pontuarPosicao
        (matriz[i][j],matriz[i+1][j],matriz[i+2][j],matriz[i+3][j],jogadorIA);
        }
    }

    //varrendo diagnoal principal
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            pontuacaoTotal = pontuacaoTotal + pontuarPosicao
        (matriz[i][j], matriz[i+1][j+1],matriz[i+2][j+2],matriz[i+3][j+3],jogadorIA);
        }
    }

    //varrendo diagonal secundaria
    for (int i = 5; i >= 3; i--) {
        for (int j = 0; j < 4; j++) {
            pontuacaoTotal = pontuacaoTotal + pontuarPosicao
        (matriz[i][j],matriz[i-1][j+1],matriz[i-2][j+2],matriz[i-3][j+3],jogadorIA);
        }
    }
    
    return pontuacaoTotal;
}

int pontuarPosicao(int v1, int v2, int v3, int v4, int jogadorIA) {
    int pontos = 0;
    int adversario;
    int countIA = 0;
    int countVazio = 0;
    int countAdv = 0;

    //identifica qual o adversario
    if (jogadorIA == 1) {
        adversario = 2;
    } else {
        adversario = 1;
    }

    //armazena os valores num vetor para facilitar 
    int casas[4];
    casas[0] = v1;
    casas[1] = v2;
    casas[2] = v3;
    casas[3] = v4;

    //conta quantas peças de cada tipo existem
    for (int i = 0; i < 4; i++) {
        if (casas[i] == jogadorIA) {
            countIA += 1;
        } else if (casas[i] == 0) {
            countVazio += 1;
        } else if (casas[i] == adversario) {
            countAdv += 1;
        }
    }

    //agora atribui a pontuação baseada nas posições mais vantajosas
    
    //peças iguais -prioridade maxima
    if (countIA == 4) {
        pontos += 1000;
    } 
    //peças de IA  e 1 espaço vazio -muito bom
    else if (countIA == 3 && countVazio == 1) {
        pontos += 100;
    } 
    //peças de IA e 2 espaços vazios -top
    else if (countIA == 2 && countVazio == 2) {
        pontos += 10;
    }

   //se o adversario está prestes a ganhar a IA precisa bloquear, saldo negativo para indicar perigo
    if (countAdv == 3 && countVazio == 1) {
        pontos -= 500;
    }

    return pontos;
}

int robotnivel3(int matriz[6][7], int jogadorIA) {
    int melhorPontuacao = -1000; //valor muito baixo para começar e facilitar a comparação
    int melhorColuna = 3; //começar pela coluna central, pois estrategicamnete esta no meio do tabuleiro

    //a logica linhaa/coluna vai ser invertida aqui para ser coluna/linha pois a coluna vai ser "fixa" momentaneamente e só a linha vai ser testada

    for (int col = 0; col < 7; col++) {//verifica se posição vazia e faz jogada hipotética para testar pontuações
        if (matriz[0][col] == 0) {
            int linhaDestaJogada = -1; // inicializamos para garantir a segurança da simulação
            for (int i = 5; i >= 0; i--) {
                if (matriz[i][col] == 0) {
                    matriz[i][col] = jogadorIA;
                    linhaDestaJogada = i; //faz jogada hipotetica para testar pontuação
                    break;
                }
            }

            //chama a função para avaliar tabuleiro
           if (linhaDestaJogada != -1) {
                int pontuacaoAtual = avaliarTabuleiro(matriz, jogadorIA);

                if (pontuacaoAtual > melhorPontuacao) {
                    melhorPontuacao = pontuacaoAtual;//se a pontuação encontrada na posição for maior do que a atual. atualiza a coluna
                    melhorColuna = col;//atualiza melhor coluna
                }

                matriz[linhaDestaJogada][col] = 0; //desfaz a jogada hipotética
            }
        }
    }
    return melhorColuna;// retorna a coluna vencedora na simulação
} 
