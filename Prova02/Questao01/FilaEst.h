#include <stdio.h>
#include <stdlib.h>
#ifndef FILAEST_H
#define FILAEST_H
#define TAM_MAX_FILA 100


typedef struct {
    int dados[TAM_MAX_FILA];
    int inicio;
    int fim;
} FilaEst;

void enfileirarEst();
void desenfileirarEst();
void imprimirFilaEst();

#endif