# 🎮 Ligue 4 (Connect 4) em C

> Projeto avaliativo da disciplina de Programação Imperativa - UFS 2025.2

![Language](https://img.shields.io/badge/Language-C-blue)
![Platform](https://img.shields.io/badge/Platform-Terminal-black)
![License](https://img.shields.io/badge/License-Academic-green)

## 📄 Sobre o Projeto

Este repositório contém a implementação do clássico jogo de tabuleiro **Ligue 4**, desenvolvida inteiramente em **Linguagem C** utilizando apenas bibliotecas-padrão. O jogo é executado via terminal e foi criado como parte das atividades avaliativas da disciplina de **Programação Imperativa**, ministrada pelo Prof. Adam Lucas Pinheiros da Silva, no Departamento de Computação da Universidade Federal de Sergipe (UFS).

O objetivo principal é aplicar conceitos de lógica de programação, manipulação de matrizes e construção de algoritmos de inteligência artificial simples.

## 🚀 Funcionalidades

O projeto está dividido em duas etapas de desenvolvimento, contemplando as seguintes modalidades e recursos:

### Modos de Jogo
* **👥 Humano vs. Humano:** Dois jogadores alternam turnos no mesmo computador.
* **👤 Humano vs. Computador:** O jogador enfrenta uma IA desenvolvida pela equipe.
* **🤖 Computador vs. Computador:** Simulação de uma partida entre duas IAs (sem interação do usuário).

### Níveis de Dificuldade da IA
Nos modos contra o computador, é possível selecionar o nível de inteligência:
1.  **Baixa:** O computador joga aleatoriamente.
2.  **Média:** O computador joga defensivamente (evita perder na próxima jogada).
3.  **Alta:** O computador joga estrategicamente, buscando a vitória ativamente.

## 🕹️ Regras do Jogo

O tabuleiro consiste em uma matriz de **6 linhas por 7 colunas**.
1.  O jogo inicia com o tabuleiro vazio.
2.  Cada jogador possui 21 fichas de uma cor distinta.
3.  Os jogadores escolhem alternadamente uma coluna para soltar sua ficha. A ficha ocupa a posição livre mais baixa daquela coluna (gravidade).
4.  **Vence** quem conseguir alinhar primeiro **4 fichas** consecutivas na horizontal, vertical ou diagonal.
5.  Se o tabuleiro encher sem vencedor, a partida termina em **empate**.

## 🛠️ Tecnologias Utilizadas

* **Linguagem C** (Padrão ANSI/ISO).
* **Bibliotecas:** Apenas bibliotecas nativas (`stdio.h`, `stdlib.h`, `time.h`, etc.), conforme requisito da disciplina.

## Compilação e execução:

Este projeto possui um `Makefile` para automatizar a compilação. Certifique-se de ter o `gcc` e o `make` instalados.

### Passo a passo:

1.  **Abra o terminal** na pasta raiz do projeto (ligue-quatro).
2.  **Compile o jogo** executando o comando:
    ```bash
    make
    ```
3.  **Execute o jogo** com o comando:
    ```bash
    ./jogo
    ```
    *(Ou utilize `make run` para compilar e rodar automaticamente)*.

4.  **Limpar arquivos temporários:**
    Para apagar o executável gerado, use:
    ```bash
    make clean
    ```

## 👥 Equipe de Desenvolvimento

Projeto desenvolvido pelos discentes:

* **[Arthur Nicolas](https://github.com/nicolassl12)**  
* **[Lauane Morais](https://github.com/LauaneMorais)** 
* **[Luiza Accioly](https://github.com/Acciolylu)** 

---
*Desenvolvido para a disciplina de Programação Imperativa (COMP0334) - UFS.*
