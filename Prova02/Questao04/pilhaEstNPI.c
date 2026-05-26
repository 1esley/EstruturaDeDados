#include "PilhaEstNPI.h"

PilhaNPI pilhaNPI = {
    .topo = -1
};

// Empilhar
void empilharNPI(int valor) {

    if(pilhaNPI.topo == TAM_MAX_PILHA - 1) {
        printf("Pilha cheia!\n");
        return;
    }
    
    pilhaNPI.topo++;
    pilhaNPI.dados[pilhaNPI.topo] = valor;
}

// Desempilhar
int desempilharNPI() {

    if(pilhaNPI.topo == -1) {
        printf("Pilha vazia!\n");
        return 0;
    }

    int removido = pilhaNPI.dados[pilhaNPI.topo];

    pilhaNPI.topo--;

    return removido;
}

// Mostrar pilha
void imprimirPilhaNPI() {

    if(pilhaNPI.topo == -1) {
        printf("Pilha vazia!\n");
        return;
    }

    printf("Pilha:\n");

    int i;

    for(i = pilhaNPI.topo; i >= 0; i--) {
        printf("%d\n", pilhaNPI.dados[i]);
    }
}

void calcularNPI() {

    char expr[256];

    printf("\nDigite a expressao NPI (tokens separados por espaco):\n");
    printf("Exemplo: 1 2 3 * + 4 -\n");
    printf("> ");

    // funcao pra limpar o buffer
    while(getchar() != '\n');
    fgets(expr, sizeof(expr), stdin);

    printf("\n--- Processando expressao: %s", expr);

    char *token = strtok(expr, " \t\n");

    while(token != NULL) {

        if(strcmp(token, "+") == 0 ||
           strcmp(token, "-") == 0 ||
           strcmp(token, "*") == 0 ||
           strcmp(token, "/") == 0) {

            if(pilhaNPI.topo < 1) {
                printf("Erro: operandos insuficientes para o operador '%s'.\n", token);
                return;
            }

            int b = desempilharNPI();
            int a = desempilharNPI();
            int resultado;

            if(strcmp(token, "+") == 0) {
                resultado = a + b;
                printf("  %d + %d = %d\n", a, b, resultado);

            } else if(strcmp(token, "-") == 0) {
                resultado = a - b;
                printf("  %d - %d = %d\n", a, b, resultado);

            } else if(strcmp(token, "*") == 0) {
                resultado = a * b;
                printf("  %d * %d = %d\n", a, b, resultado);

            } else if(strcmp(token, "/") == 0) {
                if(b == 0) {
                    printf("Erro: divisao por zero!\n");
                    return;
                }
                resultado = a / b;
                printf("  %d / %d = %d\n", a, b, resultado);
            }

            empilharNPI(resultado);

        } else {
            char *fim;
            int numero = strtof(token, &fim);

            if(*fim != '\0') {
                printf("Erro: token invalido '%s'.\n", token);
                return;
            }

            empilharNPI(numero);
            printf("  Empilhou: %d\n", numero);
        }

        token = strtok(NULL, " \t\n");
    }

    if(pilhaNPI.topo > 0) {
        printf("\nErro: expressao invalida (operandos sobrando na pilha).\n");
        imprimirPilhaNPI();
        return;
    }

    int resultado = desempilharNPI();
    printf("\n>>> Resultado final: %d <<<\n", resultado);
    imprimirPilhaNPI();
}
