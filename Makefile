# variaveis de compilação
CC = gcc
CFLAGS = -I include -Wall -Wextra

# lista de arquivos fonte e o nome do executável
SRC = src/main.c src/display.c src/robotnivel1.c src/robotnivel2.c src/verificarcolunas.c src/vitoria.c
OBJ = jogo

all: $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OBJ)

# roodar o jogo direto
run: all
	./$(OBJ)

# limpa executavel
clean:
	rm -f $(OBJ)