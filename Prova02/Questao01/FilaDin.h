#ifndef FILADIN_H
#define FILADIN_H
#include <stdio.h>
#include <stdlib.h>

// No da fila
typedef struct NoFila {
    int valor;
    struct NoFila *proximo;
} NoFila;

void enfileirar();
void desenfileirar();
void verFrente();
void imprimirFila();
void liberarFila();

#endif