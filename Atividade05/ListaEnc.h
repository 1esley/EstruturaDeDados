#ifndef LISTAENC_H
#define LISTAENC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funcionario.h"

void inserir();
void imprimirTodos();
void buscar();
void remover();

void gerarCSV();
void carregarCSV();
void liberarLista();

#endif