#include "FilaDin.h"

// Ponteiros de inicio e fim da fila
NoFila *frente = NULL;
NoFila *fim    = NULL;

// Enfileirar
void enfileirar() {
    NoFila *novo = (NoFila *) malloc(sizeof(NoFila));

    if (novo == NULL) {
        printf("\nErro de memoria.\n");
        return;
    }

    printf("\nValor: ");
    scanf("%d", &novo->valor);

    novo->proximo = NULL;

    if (fim == NULL) {
        frente = novo;
        fim = novo;
    } else {
        fim->proximo = novo;
        fim = novo;
    }
    
    printf("\nEnfileirado!\n");
}

// Desenfileirar (remove a frente)
void desenfileirar() {
    if (frente == NULL) {
        printf("\nFila vazia.\n");
        return;
    }

    NoFila *temp = frente;

    printf("\nRemovido da frente:\n");
    printf("Valor: %d\n", temp->valor);

    frente = frente->proximo;

    if (frente == NULL) {
        fim = NULL;
    }

    free(temp);
}

// Ver o primeiro da fila sem remover
void verFrente() {
    if (frente == NULL) {
        printf("\nFila vazia.\n");
        return;
    }

    printf("\nFrente da fila:\n");
    printf("Valor: %d\n", frente->valor);
}

// Imprimir toda a fila (da frente ao fim)
void imprimirFila() {
    NoFila *aux = frente;

    if (aux == NULL) {
        printf("\nFila vazia.\n");
        return;
    }

    printf("\n=== FILA (frente -> fim) ===\n");

    while (aux != NULL) {
        printf("\nValor: %d\n", aux->valor);
        aux = aux->proximo;
    }
}

// Liberar memoria da fila
void liberarFila() {
    NoFila *aux = frente;
    NoFila *temp;

    while (aux != NULL) {
        temp = aux;
        aux = aux->proximo;
        free(temp);
    }

    frente = NULL;
    fim    = NULL;
}
