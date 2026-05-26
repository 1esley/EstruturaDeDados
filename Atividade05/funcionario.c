#include "Funcionario.h"

void atualizarFuncionario(Funcionario *lista) {

    char cpfBusca[20];
    bool encontrado = false;

    printf("Digite o CPF do funcionario que deseja atualizar: ");
    scanf("%s", cpfBusca);

    Funcionario *atual = lista;

    while(atual != NULL) {

        if(strcmp(atual->dp.cpf, cpfBusca) == 0) {

            encontrado = true;

            printf("\nFuncionario encontrado!\n");

            printf("Novo nome: ");
            scanf(" %[^\n]", atual->nome);

            printf("Nova rua: ");
            scanf(" %[^\n]", atual->end.rua);

            printf("Novo numero da casa: ");
            scanf("%d", &atual->end.numero);

            printf("Novo estado civil: ");
            scanf("%s", atual->dp.estadoCivil);

            printf("Novo cargo: ");
            scanf(" %[^\n]", atual->prof.cargo);

            printf("Novo salario: ");
            scanf("%f", &atual->prof.salario);

            printf("\nFuncionario atualizado com sucesso!\n");

            return;
        }

        atual = atual->prox;
    }

    if(!encontrado) {
        printf("\nFuncionario nao encontrado!\n");
    }
}