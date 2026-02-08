# --- Variaveis de compilação ---
CC = g++
CFLAGS = -Wall -g
STD = -std=c++20

# --- Variaveis para arquivos do código fonte ---
zynes 	:= src/main.cpp
nes 	:= src/core/nes.cpp src/core/nes.h
bus 	:= src/core/bus.cpp src/core/bus.h
cpu 	:= src/core/cpu.cpp src/core/cpu.h

all_files := $(zynes) $(nes) $(bus) $(cpu)

# Regra principal para gerar o executável
zynes:
	$(CC) $(CFLAGS) $(STD) -o zynes $(all_files)

# Limpeza dos arquivos compilados
clean:
	rm -f *.o zynes
