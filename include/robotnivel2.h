#ifndef ROBOTNIVEL2_H
#define ROBOTNIVEL2_H

/*
 ia nivel 2:

1) recebe o tabuleiro com as jogadas atuais

2) contador para ver a quantidade de jogadas do adversário 

3) SE tiver uma sequência de 3 peças do adversário (na diagonal, horizontal ou vertical), a ia vai jogar onde seria a 4° peça do adversário 

4) senão, vai jogar uma peça aleatória
 */

int robotnivel2(int tabuleiro[6][7], int jogadorIA);

#endif