#include <stdio.h>
#include <stdbool.h>

#define MAX_FUNCIONARIOS 100

//Structs
typedef struct {
    char rua[50];
    int numero;
} Endereco;

typedef struct {
    char cpf[20];
    char estadoCivil[20];
} DadosPessoais;

typedef struct {
    char cargo[30];
    float salario;
} DadosProfissionais;

typedef struct {
    char nome[50];
    Endereco end;
    DadosPessoais dp;
    DadosProfissionais prof;
} Funcionario;

Funcionario f[MAX_FUNCIONARIOS];
int totalFunc = 0;

void carregarCSV() {
    FILE *arq = fopen("funcionarios.csv", "r");

    if (arq == NULL) {
        return;
    }

    fscanf(arq, "Nome;Rua;Numero;CPF;EstadoCivil;Cargo;Salario\n");

    while (totalFunc < MAX_FUNCIONARIOS &&
           fscanf(arq, " %49[^;];%49[^;];%d;%19[^;];%19[^;];%29[^;];%f\n", 
            f[totalFunc].nome, 
            f[totalFunc].end.rua, &f[totalFunc].end.numero, 
            f[totalFunc].dp.cpf, f[totalFunc].dp.estadoCivil, 
            f[totalFunc].prof.cargo, &f[totalFunc].prof.salario) == 7){
        totalFunc++;
    }

    fclose(arq);
}

//Inserir func
void inserir() {
    if (totalFunc >= MAX_FUNCIONARIOS) return;

    printf("\nNome: ");
    scanf(" %[^\n]", f[totalFunc].nome);

    printf("Rua: ");
    scanf(" %[^\n]", f[totalFunc].end.rua);

    printf("Numero: ");
    scanf("%d", &f[totalFunc].end.numero);

    printf("CPF: ");
    scanf(" %[^\n]", f[totalFunc].dp.cpf);

    printf("Estado civil: ");
    scanf(" %[^\n]", f[totalFunc].dp.estadoCivil);

    printf("Cargo: ");
    scanf(" %[^\n]", f[totalFunc].prof.cargo);

    printf("Salario: ");
    scanf("%f", &f[totalFunc].prof.salario);

    totalFunc++;
}

//mostar todos
void imprimirTodos() {
    for (int i = 0; i < totalFunc; i++) {
        printf("\nNome: %s", f[i].nome);
        printf("\nEndereco: %s, %d", f[i].end.rua, f[i].end.numero);
        printf("\nCPF: %s", f[i].dp.cpf);
        printf("\nEstado civil: %s", f[i].dp.estadoCivil);
        printf("\nCargo: %s", f[i].prof.cargo);
        printf("\nSalario: %.2f\n", f[i].prof.salario);
    }
}

//buscar func
void buscar() {
    char cpf[20];

    printf("\nDigite CPF: ");
    scanf(" %[^\n]", cpf);

    for (int i = 0; i < totalFunc; i++) {
        bool igual = true;

        for (int j = 0; cpf[j] != '\0' || f[i].dp.cpf[j] != '\0'; j++) {
            if (cpf[j] != f[i].dp.cpf[j]) {
                igual = false;
                break;
            }
        }

        if (igual) {
            printf("\nEncontrado:\n");
            printf("%s\n", f[i].nome);
            return;
        }
    }

    printf("\nNao encontrado.\n");
}

//remover func
void remover() {
    char cpf[20];

    printf("\nCPF para remover: ");
    scanf(" %[^\n]", cpf);

    for (int i = 0; i < totalFunc; i++) {
        int igual = 1;

        for (int j = 0; cpf[j] != '\0' || f[i].dp.cpf[j] != '\0'; j++) {
            if (cpf[j] != f[i].dp.cpf[j]) {
                igual = 0;
                break;
            }
        }

        if (igual) {
            for (int k = i; k < totalFunc - 1; k++) {
                f[k] = f[k + 1];
            }
            totalFunc--;
            printf("\nRemovido!\n");
            return;
        }
    }

    printf("\nNao encontrado.\n");
}

//arquivo
void gerarCSV() {
    FILE *arq = fopen("funcionarios.csv", "w");

    if (arq == NULL) return;

    fprintf(arq, "Nome;Rua;Numero;CPF;EstadoCivil;Cargo;Salario\n");

    for (int i = 0; i < totalFunc; i++) {
        fprintf(arq, "%s;%s;%d;%s;%s;%s;%.2f\n", 
            f[i].nome, 
            f[i].end.rua, f[i].end.numero, 
            f[i].dp.cpf, f[i].dp.estadoCivil, 
            f[i].prof.cargo, f[i].prof.salario);
    }

    fclose(arq);
    printf("\nCSV gerado!\n");
}

// Main
int main() {
    int op;

    carregarCSV();

    do {
        printf("\n1-Inserir\n2-Remover\n3-Imprimir\n4-Buscar\n5-CSV\n0-Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1: inserir(); break;
            case 2: remover(); break;
            case 3: imprimirTodos(); break;
            case 4: buscar(); break;
            case 5: gerarCSV(); break;
        }

    } while (op != 0);

    return 0;
}