#include "PilhaDin.h"

// Topo da pilha
NoPilha *topo = NULL;

// Empilhar funcionario
void empilhar() {
    NoPilha *novo = (NoPilha *) malloc(sizeof(NoPilha));

    if (novo == NULL) {
        printf("\nErro de memoria.\n");
        return;
    }

    printf("\nValor: ");
    scanf("%d", &novo->valor);

    novo->anterior = topo;
    topo = novo;

    printf("\nFuncionario empilhado!\n");
}

// Desempilhar (remove o topo)
void desempilhar() {
    if (topo == NULL) {
        printf("\nPilha vazia.\n");
        return;
    }

    NoPilha *temp = topo;

    printf("\nRemovido do topo:\n");
    printf("Valor: %d\n", temp->valor);

    topo = topo->anterior;
    free(temp);
}

// Ver o topo sem remover
void verTopo() {
    if (topo == NULL) {
        printf("\nPilha vazia.\n");
        return;
    }

    printf("\nTopo da pilha:\n");
    printf("Valor: %d\n", topo->valor);
}

// Imprimir toda a pilha (do topo a base)
void imprimirPilha() {
    NoPilha *aux = topo;

    if (aux == NULL) {
        printf("\nPilha vazia.\n");
        return;
    }

    printf("\n=== PILHA (topo -> base) ===\n");

    while (aux != NULL) {
        printf("Valor: %d\n", aux->valor);
        aux = aux->anterior;
    }
}

// Liberar memoria da pilha
void liberarPilha() {
    NoPilha *aux = topo;
    NoPilha *temp;

    while (aux != NULL) {
        temp = aux;
        aux = aux->anterior;
        free(temp);
    }

    topo = NULL;
}