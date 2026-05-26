#ifndef PILHADIN_H
#define PILHADIN_H
#include <stdio.h>
#include <stdlib.h>

// No da pilha
typedef struct NoPilha {
    int valor;
    struct NoPilha *anterior;
} NoPilha;

void empilhar();
void desempilhar();
void verTopo();
void imprimirPilha();
void liberarPilha();

#endif
