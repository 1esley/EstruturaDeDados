// 1
#include "Matriz.h"
#include "FilaEst.h"
#include "FilaDin.h"
#include "FilaCirc.h"
#include "PilhaEst.h"
#include "PilhaDin.h"
// 2
#include "Funcionario.h"
#include "ListaEnc.h"
#include "ListaVet.h"
// 3
#include "Impressora.h"
// 4
#include "PilhaEstNPI.h"

void menuMatriz() {
    int vet[LINHAS * COLUNAS];
    int vet2[LINHAS * COLUNAS];
    int vetR[LINHAS * COLUNAS];

    zerarMatriz(vet);
    zerarMatriz(vet2);
    zerarMatriz(vetR);

    printf("Matriz 1 \n \n");
    mostarMatriz(vet);
    printf("\n");
    printf("Matriz 2 \n \n");
    mostarMatriz(vet2);
    printf("\n");
    printf("Matriz 3 \n \n");
    mostarMatriz(vetR);
    
    printf("\n");
    
    adicionarElemento(vet, 1, 1, 2);
    adicionarElemento(vet, 2, 2, 4);
    adicionarElemento(vet, 3, 3, 6);
    
    adicionarElemento(vet2, 1, 2, 1);
    adicionarElemento(vet2, 2, 1, 3);
    adicionarElemento(vet2, 3, 2, 5);
    
    printf("Matriz 1 \n \n");
    mostarMatriz(vet);
    printf("\n");
    printf("Matriz 2 \n \n");
    mostarMatriz(vet2);
    
    printf("\nElemento [3][3] matriz 1: %d \n \n", buscarElemento(vet, 3, 3));
    
    somarMatrizes(vet, vet2, vetR);
    
    printf("Matriz 3 (resultado soma) \n \n");
    mostarMatriz(vetR);

    printf("\n");
}

void menuFilaDin() {
    int op;

    do {
        printf("\n=== FILA DINAMICA ===\n");
        printf("1. Enfileirar\n");
        printf("2. Desenfileirar (remover frente)\n");
        printf("3. Ver frente\n");
        printf("4. Imprimir fila inteira\n");
        printf("0. Liberar e sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1: enfileirar();    break;
            case 2: desenfileirar(); break;
            case 3: verFrente();     break;
            case 4: imprimirFila();  break;
            case 0: liberarFila();  break;
            default: printf("\nOpcao invalida.\n");
        }

    } while (op != 0);
}

void menuFilaEst() {
    int op;

    do {
        printf("\n=== FILA ESTATICA ===\n");
        printf("1. Enfileirar\n");
        printf("2. Desenfileirar (remover frente)\n");
        printf("3. Imprimir fila inteira\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1: enfileirarEst();    break;
            case 2: desenfileirarEst(); break;
            case 3: imprimirFilaEst();  break;
            case 0: break;
            default: printf("\nOpcao invalida.\n");
        }

    } while (op != 0);
}

void menuFilaCirc() {
    int op;

    do {
        printf("\n=== FILA CIRCULAR ===\n");
        printf("1. Enfileirar\n");
        printf("2. Desenfileirar (remover frente)\n");
        printf("3. Imprimir fila inteira\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1: enfileirarCirc();    break;
            case 2: desenfileirarCirc(); break;
            case 3: imprimirFilaCirc();  break;
            case 0: break;
            default: printf("\nOpcao invalida.\n");
        }

    } while (op != 0);
}

void menuPilhaDin() {
    int op;

    do {
        printf("\n=== PILHA DINAMICA ===\n");
        printf("1. Empilhar\n");
        printf("2. Desempilhar (remover topo)\n");
        printf("3. Ver topo\n");
        printf("4. Imprimir pilha inteira\n");
        printf("5. Liberar\n");
        printf("0. Voltar\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1: empilhar();     break;
            case 2: desempilhar();  break;
            case 3: verTopo();      break;
            case 4: imprimirPilha(); break;
            case 5: liberarPilha(); break;
            case 0: break;
            default: printf("\nOpcao invalida.\n");
        }

    } while (op != 0);
}

void menuPilhaEst() {
    int op;

    do {
        printf("\n=== PILHA ESTATICA===\n");
        printf("1. Empilhar\n");
        printf("2. Desempilhar (remover topo)\n");
        printf("3. Imprimir pilha inteira\n");
        printf("0. Voltar\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1: empilharEst();     break;
            case 2: desempilharEst();  break;
            case 3: imprimirPilhaEst(); break;
            case 0: break;
            default: printf("\nOpcao invalida.\n");
        }

    } while (op != 0);
}

void menuEmpresaDin() {
    carregarCSV();
    int op;

    do {
        printf("\n=== LISTA ===\n");
        printf("1. Inserir funcionario\n");
        printf("2. Listar todos\n");
        printf("3. Buscar por CPF\n");
        printf("4. Remover por CPF\n");
        printf("5. Salvar CSV\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1: inserir(); break;
            case 2: imprimirTodos(); break;
            case 3: buscar(); break;
            case 4: remover(); break;
            case 5: gerarCSV(); break;
            case 0: liberarLista(); break;
            default: printf("\nOpcao invalida.\n");
        }

    } while (op != 0);
}

void menuEmpresaEst() {
    carregarCSVEst();
    int op;

    do {
        printf("\n=== LISTA ===\n");
        printf("1. Inserir funcionario\n");
        printf("2. Listar todos\n");
        printf("3. Buscar por CPF\n");
        printf("4. Remover por CPF\n");
        printf("5. Salvar CSV\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1: inserirEst(); break;
            case 2: imprimirTodosEst(); break;
            case 3: buscarEst(); break;
            case 4: removerEst(); break;
            case 5: gerarCSVEst(); break;
            case 0: break;
            default: printf("\nOpcao invalida.\n");
        }

    } while (op != 0);
}

void menuImpressora() {
    int op;

    do
    {
        printf("========= IMPRESSORA =========\n");
        printf("1. Adicionar papel\n");
        printf("2. Fila de impressao\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1: adicionaPedido();    break;
            case 2: mostrarFila(); break;
            case 0: break;
            default: printf("\nOpcao invalida.\n");
        }

    } while (op != 0);
}

void menuNPI() {
    int op;

    do {
        printf("\n=== NPI ===\n");
        printf("1. Calcular\n");
        printf("0. Voltar\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1: calcularNPI();     break;
            case 0: break;
            default: printf("\nOpcao invalida.\n");
        }

    } while (op != 0);
}

int main() {


    int op;

    do {

        printf("\n=================================\n");
        printf("         MENU PRINCIPAL\n");
        printf("=================================\n");

        printf("1. Matriz\n");
        printf("2. Fila Estatica\n");
        printf("3. Fila Dinamica\n");
        printf("4. Fila Circular\n");
        printf("5. Pilha Estatica\n");
        printf("6. Pilha Dinamica\n");
        printf("7. Empresa Estatica\n");
        printf("8. Empresa Dinamica\n");
        printf("9. Impressora\n");
        printf("10. NPI\n");
        printf("0. Sair\n");

        printf("Opcao: ");
        scanf("%d", &op);

        switch(op) {

            case 1: menuMatriz(); break;
            case 2: menuFilaEst(); break;
            case 3: menuFilaDin(); break;
            case 4: menuFilaCirc(); break;
            case 5: menuPilhaEst(); break;
            case 6: menuPilhaDin(); break;
            case 7: menuEmpresaEst(); break;
            case 8: menuEmpresaDin(); break;
            case 9: menuImpressora(); break;
            case 10: menuNPI(); break;
            case 0: printf("\nEncerrando programa...\n"); break;
            default: printf("\nOpcao invalida.\n");
        }

    } while(op != 0);

    return 0;


    return 0;
}