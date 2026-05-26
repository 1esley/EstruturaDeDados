#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef IMPRESSORA_H
#define IMPRESSORA_H

#define TAM_MAX_FILA 100

typedef struct {
    char titulo[30];
    int prioridade;
} Papel;

typedef struct {
    Papel fila[TAM_MAX_FILA];
    int inicio;
    int fim;
    int quantidade;
} FilaImpressora;

void adicionaPedido();
void mostrarFila();


#endif