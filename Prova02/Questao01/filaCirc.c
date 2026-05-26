#include "FilaCirc.h"

FilaCirc filaCirc = {  
    .inicio = 0,
    .fim = -1,
    .quantidade = 0
};

// Enfileirar
void enfileirarCirc() {

    // Verificação de fila cheia
    if(filaCirc.quantidade == TAM_MAX_FILA) {
        printf("Fila cheia!\n");
        return;
    }

    int valor;

    printf("\nDigite o valor: ");
    scanf("%d", &valor);

    filaCirc.fim = (filaCirc.fim + 1) % TAM_MAX_FILA;
    filaCirc.dados[filaCirc.fim] = valor;
    filaCirc.quantidade++;

    printf("Valor %d inserido na fila.\n", valor);
}

// Desenfileirar
void desenfileirarCirc() {
    
    // Verificação de fila vazia
    if(filaCirc.quantidade == 0) {
        printf("Fila vazia!\n");
        return;
    }
    
    int removido = filaCirc.dados[filaCirc.inicio];
    
    filaCirc.inicio = (filaCirc.inicio + 1) % TAM_MAX_FILA;
    filaCirc.quantidade--;
    
    printf("Valor %d removido da fila.\n", removido);
}

// Mostrar fila
void imprimirFilaCirc() {

    // Verificação de fila vazia
    if(filaCirc.quantidade == 0) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Fila: ");

    int i;
    int pos = filaCirc.inicio;

    for(i = 0; i < filaCirc.quantidade; i++) {
        printf("%d ", filaCirc.dados[pos]);
        pos = (pos + 1) % TAM_MAX_FILA;
    }

    printf("\n");
}