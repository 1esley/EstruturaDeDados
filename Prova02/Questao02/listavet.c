#include "ListaVet.h"
#define MAX_FUNCIONARIOS 100

Funcionario listaFunc[MAX_FUNCIONARIOS];
int totalFunc = 0;

void carregarCSVEst() {
    FILE *arq = fopen("funcionarios.csv", "r");

    if (arq == NULL) {
        return;
    }

    fscanf(arq, "Nome;Rua;Numero;CPF;EstadoCivil;Cargo;Salario\n");

    while (totalFunc < MAX_FUNCIONARIOS &&
           fscanf(arq, " %49[^;];%49[^;];%d;%19[^;];%19[^;];%29[^;];%f\n", 
            listaFunc[totalFunc].nome, 
            listaFunc[totalFunc].end.rua, &listaFunc[totalFunc].end.numero, 
            listaFunc[totalFunc].dp.cpf, listaFunc[totalFunc].dp.estadoCivil, 
            listaFunc[totalFunc].prof.cargo, &listaFunc[totalFunc].prof.salario) == 7){
        totalFunc++;
    }

    fclose(arq);
}

//Inserir func
void inserirEst() {
    if (totalFunc >= MAX_FUNCIONARIOS) return;

    printf("\nNome: ");
    scanf(" %[^\n]", listaFunc[totalFunc].nome);

    printf("Rua: ");
    scanf(" %[^\n]", listaFunc[totalFunc].end.rua);

    printf("Numero: ");
    scanf("%d", &listaFunc[totalFunc].end.numero);

    printf("CPF: ");
    scanf(" %[^\n]", listaFunc[totalFunc].dp.cpf);

    printf("Estado civil: ");
    scanf(" %[^\n]", listaFunc[totalFunc].dp.estadoCivil);

    printf("Cargo: ");
    scanf(" %[^\n]", listaFunc[totalFunc].prof.cargo);

    printf("Salario: ");
    scanf("%f", &listaFunc[totalFunc].prof.salario);

    totalFunc++;
}

//mostar todos
void imprimirTodosEst() {
    for (int i = 0; i < totalFunc; i++) {
        printf("\nNome: %s", listaFunc[i].nome);
        printf("\nEndereco: %s, %d", listaFunc[i].end.rua, listaFunc[i].end.numero);
        printf("\nCPF: %s", listaFunc[i].dp.cpf);
        printf("\nEstado civil: %s", listaFunc[i].dp.estadoCivil);
        printf("\nCargo: %s", listaFunc[i].prof.cargo);
        printf("\nSalario: %.2f\n", listaFunc[i].prof.salario);
    }
}

//buscar func
void buscarEst() {
    char cpf[20];

    printf("\nDigite CPF: ");
    scanf(" %[^\n]", cpf);

    for (int i = 0; i < totalFunc; i++) {
        bool igual = true;

        for (int j = 0; cpf[j] != '\0' || listaFunc[i].dp.cpf[j] != '\0'; j++) {
            if (cpf[j] != listaFunc[i].dp.cpf[j]) {
                igual = false;
                break;
            }
        }

        if (igual) {
            printf("\nEncontrado:\n");
            printf("%s\n", listaFunc[i].nome);
            return;
        }
    }

    printf("\nNao encontrado.\n");
}

//remover func
void removerEst() {
    char cpf[20];

    printf("\nCPF para remover: ");
    scanf(" %[^\n]", cpf);

    for (int i = 0; i < totalFunc; i++) {
        int igual = 1;

        for (int j = 0; cpf[j] != '\0' || listaFunc[i].dp.cpf[j] != '\0'; j++) {
            if (cpf[j] != listaFunc[i].dp.cpf[j]) {
                igual = 0;
                break;
            }
        }

        if (igual) {
            for (int k = i; k < totalFunc - 1; k++) {
                listaFunc[k] = listaFunc[k + 1];
            }
            totalFunc--;
            printf("\nRemovido!\n");
            return;
        }
    }

    printf("\nNao encontrado.\n");
}

//arquivo
void gerarCSVEst() {
    FILE *arq = fopen("funcionarios.csv", "w");

    if (arq == NULL) return;

    fprintf(arq, "Nome;Rua;Numero;CPF;EstadoCivil;Cargo;Salario\n");

    for (int i = 0; i < totalFunc; i++) {
        fprintf(arq, "%s;%s;%d;%s;%s;%s;%.2f\n", 
            listaFunc[i].nome, 
            listaFunc[i].end.rua, listaFunc[i].end.numero, 
            listaFunc[i].dp.cpf, listaFunc[i].dp.estadoCivil, 
            listaFunc[i].prof.cargo, listaFunc[i].prof.salario);
    }

    fclose(arq);
    printf("\nCSV gerado!\n");
}