#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Funcionario.h"
#include "Pilha.h"
#include "Fila.h"
#include "ListaEnc.h"
// #include "ListaVet.h"

// -- Menu da Lista Encadeada --
void menuLista() {
    int op;

    do {
        printf("\n=== LISTA ===\n");
        printf("1. Inserir funcionario\n");
        printf("2. Listar todos\n");
        printf("3. Buscar por CPF\n");
        printf("4. Remover por CPF\n");
        printf("5. Salvar CSV\n");
        printf("0. Voltar\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1: inserir();      break;
            case 2: imprimirTodos(); break;
            case 3: buscar();       break;
            case 4: remover();      break;
            case 5: gerarCSV();     break;
            case 0: break;
            default: printf("\nOpcao invalida.\n");
        }

    } while (op != 0);
}

// -- Menu da Pilha --
void menuPilha() {
    int op;

    do {
        printf("\n=== PILHA ===\n");
        printf("1. Empilhar funcionario\n");
        printf("2. Desempilhar (remover topo)\n");
        printf("3. Ver topo\n");
        printf("4. Imprimir pilha inteira\n");
        printf("0. Voltar\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1: empilhar();     break;
            case 2: desempilhar();  break;
            case 3: verTopo();      break;
            case 4: imprimirPilha(); break;
            case 0: break;
            default: printf("\nOpcao invalida.\n");
        }

    } while (op != 0);
}

// -- Menu da Fila --
void menuFila() {
    int op;

    do {
        printf("\n=== FILA ===\n");
        printf("1. Enfileirar funcionario\n");
        printf("2. Desenfileirar (remover frente)\n");
        printf("3. Ver frente\n");
        printf("4. Imprimir fila inteira\n");
        printf("0. Voltar\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1: enfileirar();    break;
            case 2: desenfileirar(); break;
            case 3: verFrente();     break;
            case 4: imprimirFila();  break;
            case 0: break;
            default: printf("\nOpcao invalida.\n");
        }

    } while (op != 0);
}

// -- Menu Principal --
int main() {
    carregarCSV();

    int op;

    do {
        printf("\n====== MENU PRINCIPAL ======\n");
        printf("1. Lista\n");
        printf("2. Pilha\n");
        printf("3. Fila\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1: menuLista(); break;
            case 2: menuPilha(); break;
            case 3: menuFila();  break;
            case 0:
                gerarCSV();
                liberarLista();
                liberarPilha();
                liberarFila();
                printf("\nSaindo...\n");
                break;
            default: printf("\nOpcao invalida.\n");
        }

    } while (op != 0);

    return 0;
}
