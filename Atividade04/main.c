#include <stdio.h>
#include <stdlib.h>
#include "ListaEnc.h"

int main() {
    int opcao;

    do {
        printf("\n=== Sistema de Gerenciamento de Funcionarios ===\n");
        printf("1. Inserir funcionario\n");
        printf("2. Imprimir todos os funcionarios\n");
        printf("3. Buscar funcionario\n");
        printf("4. Atualizar funcionario\n");
        printf("5. Remover funcionario\n");
        printf("6. Gerar CSV\n");
        printf("7. Carregar CSV\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserir();
                break;
            case 2:
                imprimirTodos();
                break;
            case 3:
                buscar();
                break;
            case 4:
                atualizarFuncionario(inicio);
                break;
            case 5:
                remover();
                break;
            case 6:
                gerarCSV();
                break;
            case 7:
                carregarCSV();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    liberarLista();
    return 0;
}