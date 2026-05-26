#include <stdio.h>
#include <stdlib.h>
#ifndef FILACIRC_H
#define FILACIRC_H
#define TAM_MAX_FILA 100


typedef struct {
    int dados[TAM_MAX_FILA];
    int inicio;
    int fim;
    int quantidade;
} FilaCirc;

void enfileirarCirc();
void desenfileirarCirc();
void imprimirFilaCirc();

#endif