# Nome do compilador
CC = gcc

# Flags de compilação (avisos e padrões)
CFLAGS = -Wall -Wextra -std=c11

# Nome do executável final
TARGET = main

# Lista de arquivos objeto (.o)
OBJS = main.o grafo.o

# Regra principal: como gerar o executável
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Como compilar cada .c em .o
main.o: main.c grafo.h
	$(CC) $(CFLAGS) -c main.c

grafo.o: grafo.c grafo.h
	$(CC) $(CFLAGS) -c grafo.c

# Limpeza dos arquivos compilados
clean:
	rm -f $(OBJS) $(TARGET)
