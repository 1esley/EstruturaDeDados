#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef PILHAESTNPI_H
#define PILHAESTNPI_H

#define TAM_MAX_PILHA 100

typedef struct {
    int dados[TAM_MAX_PILHA];
    int topo;
} PilhaNPI;

void empilharNPI(int valor);
int desempilharNPI();
void imprimirPilhaNPI();
void calcularNPI();

#endif