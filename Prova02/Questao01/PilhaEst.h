#include <stdio.h>
#include <stdlib.h>
#ifndef PILHAEST_H
#define PILHAEST_H

#define TAM_MAX_PILHA 100

typedef struct {
    int dados[TAM_MAX_PILHA];
    int topo;
} Pilha;

void empilharEst();
void desempilharEst();
void imprimirPilhaEst();

#endif