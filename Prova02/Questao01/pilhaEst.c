#include "PilhaEst.h"

Pilha pilhaEst = {
    .topo = -1
};

// Empilhar
void empilharEst() {

    if(pilhaEst.topo == TAM_MAX_PILHA - 1) {
        printf("Pilha cheia!\n");
        return;
    }

    int valor;

    printf("\nDigite o valor: ");
    scanf("%d", &valor);

    pilhaEst.topo++;
    pilhaEst.dados[pilhaEst.topo] = valor;

    printf("Valor %d inserido na pilha.\n", valor);
}

// Desempilhar
void desempilharEst() {

    if(pilhaEst.topo == -1) {
        printf("Pilha vazia!\n");
        return;
    }

    int removido = pilhaEst.dados[pilhaEst.topo];

    pilhaEst.topo--;

    printf("Valor %d removido da pilha.\n", removido);
}

// Mostrar pilha
void imprimirPilhaEst() {

    if(pilhaEst.topo == -1) {
        printf("Pilha vazia!\n");
        return;
    }

    printf("Pilha:\n");

    int i;

    for(i = pilhaEst.topo; i >= 0; i--) {
        printf("%d\n", pilhaEst.dados[i]);
    }
}