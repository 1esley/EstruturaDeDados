#ifndef MATRIZ_H
#define MATRIZ_H
#define ERROR -999
#define LINHAS 3
#define COLUNAS 3
#include <stdio.h>


int getIndex(int posL, int posC);
void adicionarElemento(int vet[], int posL, int posC, int valor);
void zerarMatriz(int vet[]);
int buscarElemento(int vet[], int posL, int posC);
void mostarMatriz(int vet[]);
void somarMatrizes(int vet1[], int vet2[], int vet3[]);



#endif