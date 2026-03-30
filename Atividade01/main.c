#include <stdio.h>

#define ERROR -999

int l, c;

//Pegar índice
int getIndex(int posL, int posC) {
    if (posL <= l && posC <= c && posL > 0 && posC >0) {
        return (posL - 1) * c + (posC - 1);
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
        if (posL > l && posC > c) {printf("Posicao invalida. Linha %d e coluna %d nao existem.\n", posL, posC);} 
        else if (posL > l) {printf("Posicao invalida. Linha %d nao existe.\n", posL);} 
        else if (posC > c) {printf("Posicao invalida. Coluna %d nao existe.\n", posC);}
        else {printf("Posicao invalida.");}
    }
}
//Zerar
void zerarMatriz(int vet[]) {
    for (int i = 1; i < l + 1 ; i++){   
        for (int j = 1; j < c + 1; j++){
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
        if (posL > l && posC > c) {printf("Posicao invalida. Linha %d e coluna %d nao existem.\n", posL, posC);} 
        else if (posL > l) {printf("Posicao invalida. Linha %d nao existe.\n", posL);} 
        else if (posC > c) {printf("Posicao invalida. Coluna %d nao existe.\n", posC);}
        else {printf("Posicao invalida \n");}
        return ERROR;
    }
}

//Mostrar
void mostarMatriz(int vet[]){
    for (int i = 1; i < l + 1; i++){   
        for (int j = 1; j < c + 1; j++){
            printf("%d ", buscarElemento(vet, i, j));
        }
        printf(" \n");
    }
}

//Somar
void somarMatrizes(int vet1[], int vet2[], int vet3[]){
    for (int i = 1; i < l + 1; i++){
        for (int j = 1; j < c + 1; j++){
            int eleVet1 = buscarElemento(vet1, i, j);
            int eleVet2 = buscarElemento(vet2, i, j);
            int soma = eleVet1 + eleVet2;

            if (eleVet1 != ERROR && eleVet2 != ERROR){
                adicionarElemento(vet3, i, j, soma);
            }
            
        }
    }
    
}

int main() {

    l = 3;
    c = 3;
    
    int vet[l * c];
    int vet2[l * c];
    int vetR[l * c];

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

    return 0;
}