#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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


void atualizarFuncionario(Funcionario *lista);