#include "Pilha.h"

// No da pilha
typedef struct NoPilha {
    Funcionario dado;
    struct NoPilha *anterior;
} NoPilha;

// Topo da pilha
NoPilha *topo = NULL;

// Empilhar funcionario
void empilhar() {
    NoPilha *novo = (NoPilha *) malloc(sizeof(NoPilha));

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
    printf("Nome: %s\n", temp->dado.nome);
    printf("CPF: %s\n", temp->dado.dp.cpf);
    printf("Cargo: %s\n", temp->dado.prof.cargo);

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
    printf("Nome: %s\n", topo->dado.nome);
    printf("Endereco: %s, %d\n", topo->dado.end.rua, topo->dado.end.numero);
    printf("CPF: %s\n", topo->dado.dp.cpf);
    printf("Estado civil: %s\n", topo->dado.dp.estadoCivil);
    printf("Cargo: %s\n", topo->dado.prof.cargo);
    printf("Salario: %.2f\n", topo->dado.prof.salario);
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
        printf("\nNome: %s\n", aux->dado.nome);
        printf("Endereco: %s, %d\n", aux->dado.end.rua, aux->dado.end.numero);
        printf("CPF: %s\n", aux->dado.dp.cpf);
        printf("Estado civil: %s\n", aux->dado.dp.estadoCivil);
        printf("Cargo: %s\n", aux->dado.prof.cargo);
        printf("Salario: %.2f\n", aux->dado.prof.salario);
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