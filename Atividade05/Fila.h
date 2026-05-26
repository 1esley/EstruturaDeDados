#ifndef FILA_H
#define FILA_H

#include "Funcionario.h"

// No da fila
typedef struct NoFila {
    Funcionario dado;
    struct NoFila *proximo;
} NoFila;

void enfileirar();
void desenfileirar();
void verFrente();
void  imprimirFila();
void liberarFila();

#endif