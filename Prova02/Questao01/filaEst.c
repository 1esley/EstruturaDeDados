#include "FilaEst.h"

FilaEst filaEst = {  
    .inicio = 0,
    .fim = -1,
};

// Enfileirar
void enfileirarEst() {

    // Verificação de fila cheia
    if(filaEst.fim == TAM_MAX_FILA - 1) {
        printf("Fila cheia!\n");
        return;
    }

    int valor;

    printf("\nDigite o valor: ");
    scanf("%d", &valor);

    filaEst.fim++;
    filaEst.dados[filaEst.fim] = valor;

    printf("Valor %d inserido na fila.\n", valor);
}

// Desenfileirar
void desenfileirarEst() {
    
    // Verificação de fila vazia
    if(filaEst.inicio > filaEst.fim) {
        printf("Fila vazia!\n");
        return;
    }
    
    int removido = filaEst.dados[filaEst.inicio];
    
    filaEst.inicio++;
    
    printf("Valor %d removido da fila.\n", removido);
}

// Mostrar fila
void imprimirFilaEst() {

    // Verificação de fila vazia
    if(filaEst.inicio > filaEst.fim) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Fila: ");

    for(int i = filaEst.inicio; i <= filaEst.fim; i++) {
        printf("%d ", filaEst.dados[i]);
    }

    printf("\n");
}