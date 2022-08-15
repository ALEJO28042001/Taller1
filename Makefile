#*************************************************
#   Fecha: 2-Agosto 2022
#   Autor: Diego Bermúdez
#   Materia: Parallel & Distributin Computation
#   Tema:Taller1
#   Topico:Makefile
#*************************************************

GCC = gcc
FLAGS = -ansi -pedantic -Wall -std=c99
D_POSIX_C_SOURSE=199309L
MATHFLAG = -lm

PROGS = main

all: $(PROGS)

main:
	gcc main.c -lm
	#$(GCC) $(FLAGS) -c Taller1_lib.c
	#$(GCC) $(FLAGS) -o $@ $@.o Taller1_lib.o $(MATHFLAG)
	#$(GCC) $(FLAGS) -o main main.c -lm
clean:
	$(RM) *.o $(PROGRS)
	
