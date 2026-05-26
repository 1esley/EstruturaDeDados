#include "Fila.h"

// Ponteiros de inicio e fim da fila
NoFila *frente = NULL;
NoFila *fim    = NULL;

// Enfileirar funcionario
void enfileirar() {
    NoFila *novo = (NoFila *) malloc(sizeof(NoFila));

    if (novo == NULL) {
        printf("\nErro de memoria.\n");
        return;
    }

    printf("\nNome: ");
    scanf(" %[^\n]", novo->dado.nome);

    printf("Rua: ");
    scanf(" %[^\n]", novo->dado.end.rua);

    printf("Numero: ");
    scanf("%d", &novo->dado.end.numero);

    printf("CPF: ");
    scanf(" %[^\n]", novo->dado.dp.cpf);

    printf("Estado civil: ");
    scanf(" %[^\n]", novo->dado.dp.estadoCivil);

    printf("Cargo: ");
    scanf(" %[^\n]", novo->dado.prof.cargo);

    printf("Salario: ");
    scanf("%f", &novo->dado.prof.salario);

    novo->proximo = NULL;

    if (fim == NULL) {
        frente = novo;
        fim    = novo;
    } else {
        fim->proximo = novo;
        fim = novo;
    }

    printf("\nFuncionario enfileirado!\n");
}

// Desenfileirar (remove a frente)
void desenfileirar() {
    if (frente == NULL) {
        printf("\nFila vazia.\n");
        return;
    }

    NoFila *temp = frente;

    printf("\nRemovido da frente:\n");
    printf("Nome: %s\n", temp->dado.nome);
    printf("CPF: %s\n", temp->dado.dp.cpf);
    printf("Cargo: %s\n", temp->dado.prof.cargo);

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
    printf("Nome: %s\n", frente->dado.nome);
    printf("Endereco: %s, %d\n", frente->dado.end.rua, frente->dado.end.numero);
    printf("CPF: %s\n", frente->dado.dp.cpf);
    printf("Estado civil: %s\n", frente->dado.dp.estadoCivil);
    printf("Cargo: %s\n", frente->dado.prof.cargo);
    printf("Salario: %.2f\n", frente->dado.prof.salario);
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
        printf("\nNome: %s\n", aux->dado.nome);
        printf("Endereco: %s, %d\n", aux->dado.end.rua, aux->dado.end.numero);
        printf("CPF: %s\n", aux->dado.dp.cpf);
        printf("Estado civil: %s\n", aux->dado.dp.estadoCivil);
        printf("Cargo: %s\n", aux->dado.prof.cargo);
        printf("Salario: %.2f\n", aux->dado.prof.salario);
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
