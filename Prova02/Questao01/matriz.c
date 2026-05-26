#include "Matriz.h"

//Pegar índice
int getIndex(int posL, int posC) {
    if (posL <= LINHAS && posC <= COLUNAS && posL > 0 && posC >0) {
        return (posL - 1) * COLUNAS + (posC - 1);
    }
    return ERROR;
}

//Adicionar elemento
void adicionarElemento(int vet[], int posL, int posC, int valor) {
    if (getIndex(posL, posC) != ERROR){
        int index = getIndex(posL, posC);
        vet[index] = valor;
    }
    else {
        if (posL > LINHAS && posC > COLUNAS) {printf("Posicao invalida. Linha %d e coluna %d nao existem.\n", posL, posC);} 
        else if (posL > LINHAS) {printf("Posicao invalida. Linha %d nao existe.\n", posL);} 
        else if (posC > COLUNAS) {printf("Posicao invalida. Coluna %d nao existe.\n", posC);}
        else {printf("Posicao invalida.");}
    }
}
//Zerar
void zerarMatriz(int vet[]) {
    for (int i = 1; i < LINHAS + 1 ; i++){   
        for (int j = 1; j < COLUNAS + 1; j++){
            adicionarElemento(vet, i, j, 0);
        }
    }   
}

//Buscar elemento
int buscarElemento(int vet[], int posL, int posC){
    if (getIndex(posL, posC) != ERROR){
        int index = getIndex(posL, posC);
        return vet[index];
    } else {
        if (posL > LINHAS && posC > COLUNAS) {printf("Posicao invalida. Linha %d e coluna %d nao existem.\n", posL, posC);} 
        else if (posL > LINHAS) {printf("Posicao invalida. Linha %d nao existe.\n", posL);} 
        else if (posC > COLUNAS) {printf("Posicao invalida. Coluna %d nao existe.\n", posC);}
        else {printf("Posicao invalida \n");}
        return ERROR;
    }
}

//Mostrar
void mostarMatriz(int vet[]){
    for (int i = 1; i < LINHAS + 1; i++){   
        for (int j = 1; j < COLUNAS + 1; j++){
            printf("%d ", buscarElemento(vet, i, j));
        }
        printf(" \n");
    }
}

//Somar
void somarMatrizes(int vet1[], int vet2[], int vet3[]){
    for (int i = 1; i < LINHAS + 1; i++){
        for (int j = 1; j < COLUNAS + 1; j++){
            int eleVet1 = buscarElemento(vet1, i, j);
            int eleVet2 = buscarElemento(vet2, i, j);
            int soma = eleVet1 + eleVet2;

            if (eleVet1 != ERROR && eleVet2 != ERROR){
                adicionarElemento(vet3, i, j, soma);
            }
            
        }
    }
    
}