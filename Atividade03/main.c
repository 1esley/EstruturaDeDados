#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

typedef struct Funcionario {
    char nome[50];
    Endereco end;
    DadosPessoais dp;
    DadosProfissionais prof;
    struct Funcionario *prox;
} Funcionario;

// cauda da lista
Funcionario *inicio = NULL;

void inserir() {
    Funcionario *novo = (Funcionario *) malloc(sizeof(Funcionario));

    if (novo == NULL) {
        printf("\nErro de memoria.\n");
        return;
    }

    printf("\nNome: ");
    scanf(" %[^\n]", novo->nome);

    printf("Rua: ");
    scanf(" %[^\n]", novo->end.rua);

    printf("Numero: ");
    scanf("%d", &novo->end.numero);

    printf("CPF: ");
    scanf(" %[^\n]", novo->dp.cpf);

    printf("Estado civil: ");
    scanf(" %[^\n]", novo->dp.estadoCivil);

    printf("Cargo: ");
    scanf(" %[^\n]", novo->prof.cargo);

    printf("Salario: ");
    scanf("%f", &novo->prof.salario);

    novo->prox = NULL;

    if (inicio == NULL) {
        inicio = novo;
    } else {
        Funcionario *aux = inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }

    printf("\nFuncionario inserido!\n");
}

void imprimirTodos() {
    Funcionario *aux = inicio;

    if (aux == NULL) {
        printf("\nNenhum funcionario.\n");
        return;
    }

    while (aux != NULL) {
        printf("\nNome: %s\n", aux->nome);
        printf("Endereco: %s, %d\n", aux->end.rua, aux->end.numero);
        printf("CPF: %s\n", aux->dp.cpf);
        printf("Estado civil: %s\n", aux->dp.estadoCivil);
        printf("Cargo: %s\n", aux->prof.cargo);
        printf("Salario: %.2f\n", aux->prof.salario);

        aux = aux->prox;
    }
}

void buscar() {
    char cpf[20];
    Funcionario *aux = inicio;

    printf("\nDigite o CPF: ");
    scanf(" %[^\n]", cpf);

    while (aux != NULL) {
        if (strcmp(cpf, aux->dp.cpf) == 0) {
            printf("\nEncontrado:\n");
            printf("Nome: %s\n", aux->nome);
            printf("Cargo: %s\n", aux->prof.cargo);
            return;
        }
        aux = aux->prox;
    }

    printf("\nNao encontrado.\n");
}

void remover() {
    char cpf[20];
    Funcionario *aux = inicio;
    Funcionario *anterior = NULL;

    printf("\nCPF para remover: ");
    scanf(" %[^\n]", cpf);

    while (aux != NULL && strcmp(cpf, aux->dp.cpf) != 0) {
        anterior = aux;
        aux = aux->prox;
    }

    if (aux == NULL) {
        printf("\nNao encontrado.\n");
        return;
    }

    if (anterior == NULL) {
        inicio = aux->prox;
    } else {
        anterior->prox = aux->prox;
    }

    free(aux);
    printf("\nRemovido!\n");
}

// salva dados no csv
void gerarCSV() {
    FILE *arq = fopen("funcionarios.csv", "w");
    Funcionario *aux = inicio;

    if (arq == NULL) {
        printf("\nErro ao criar arquivo.\n");
        return;
    }

    fprintf(arq, "Nome;Rua;Numero;CPF;EstadoCivil;Cargo;Salario\n");

    while (aux != NULL) {
        fprintf(arq, "%s;%s;%d;%s;%s;%s;%.2f\n",
                aux->nome,
                aux->end.rua,
                aux->end.numero,
                aux->dp.cpf,
                aux->dp.estadoCivil,
                aux->prof.cargo,
                aux->prof.salario);

        aux = aux->prox;
    }

    fclose(arq);
    printf("\nCSV salvo!\n");
}

// puxa dados do csv
void carregarCSV() {
    FILE *arq = fopen("funcionarios.csv", "r");

    if (arq == NULL) return;

    fscanf(arq, "Nome;Rua;Numero;CPF;EstadoCivil;Cargo;Salario\n");

    while (1) {
        Funcionario *novo = (Funcionario *) malloc(sizeof(Funcionario));

        if (novo == NULL) break;

        int lidos = fscanf(arq, " %49[^;];%49[^;];%d;%19[^;];%19[^;];%29[^;];%f\n",
                           novo->nome,
                           novo->end.rua,
                           &novo->end.numero,
                           novo->dp.cpf,
                           novo->dp.estadoCivil,
                           novo->prof.cargo,
                           &novo->prof.salario);

        if (lidos != 7) {
            free(novo);
            break;
        }

        novo->prox = NULL;

        if (inicio == NULL) {
            inicio = novo;
        } else {
            Funcionario *aux = inicio;
            while (aux->prox != NULL) {
                aux = aux->prox;
            }
            aux->prox = novo;
        }
    }

    fclose(arq);
}

// liberar malloc
void liberarLista() {
    Funcionario *aux = inicio;
    Funcionario *temp;

    while (aux != NULL) {
        temp = aux;
        aux = aux->prox;
        free(temp);
    }
}

int main() {
    int op;

    carregarCSV();

    do {
        printf("\n1-Inserir\n2-Remover\n3-Imprimir\n4-Buscar\n5-Salvar CSV\n0-Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1: inserir(); break;
            case 2: remover(); break;
            case 3: imprimirTodos(); break;
            case 4: buscar(); break;
            case 5: gerarCSV(); break;
            case 0:
                gerarCSV();
                liberarLista();
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida.\n");
        }

    } while (op != 0);

    return 0;
}