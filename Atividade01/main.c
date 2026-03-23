#include <stdio.h>

//Zerar
void zerarMatriz(int vet[], int linhas, int colunas) {
    for (int i = 0; i < linhas * colunas; i++){   
        vet[i] = 0;
    }   
}

//Mostrar
void mostarMatriz(int vet[], int linhas, int colunas){
    for (int i = 0; i < linhas; i++){   
        for (int j = 0; j < colunas; j++){
            printf("%d ", vet[i * colunas + j]);
        }
        printf(" \n");
    }
}

//Adicionar elemento
void adicionarElemento(int vet[], int linhas, int colunas, int posL, int posC, int valor) {
    if (posL <= linhas && posC <= colunas && posL > 0 && posC > 0){
        vet[(posL - 1) * colunas + (posC - 1)] = valor;
    }
    else {
        if (posL > linhas && posC > colunas) {printf("Posicao invalida. Linha %d e coluna %d nao existem.\n", posL, posC);} 
        else if (posL > linhas) {printf("Posicao invalida. Linha %d nao existe.\n", posL);} 
        else if (posC > colunas) {printf("Posicao invalida. Coluna %d nao existe.\n", posC);}
        else {printf("Posicao invalida.");}
    }
}

//Buscar elemento
int buscarElemento(int vet[], int linhas, int colunas, int posL, int posC){
    if (posL <= linhas && posC <= colunas && posL > 0 && posC > 0)
    {
        return vet[(posL -1) * colunas + (posC - 1)];
    } else {
        if (posL > linhas && posC > colunas) {printf("Posicao invalida. Linha %d e coluna %d nao existem.\n", posL, posC);} 
        else if (posL > linhas) {printf("Posicao invalida. Linha %d nao existe.\n", posL);} 
        else if (posC > colunas) {printf("Posicao invalida. Coluna %d nao existe.\n", posC);}
        else {printf("Posicao invalida");}
        return -999;
    }
}

//Somar
void somarMatrizes(int vet1[], int vet2[], int vet3[], int linhas, int colunas){
    for (int i = 0; i < linhas * colunas; i++){
        vet3[i] = vet1[i] + vet2[i];
    }
    
}

int main() {

    int l, c;

    l = 4;
    c = 6;

    int vet[l * c];
    int vet2[l * c];
    int vetR[l * c];

    zerarMatriz(vet, l, c);
    zerarMatriz(vet2, l, c);
    zerarMatriz(vetR, l, c);

    mostarMatriz(vet, l, c);
    printf("\n");
    mostarMatriz(vet2, l, c);

    printf("\n");
    
    adicionarElemento(vet, l, c, 1, 1, 2);
    adicionarElemento(vet, l, c, 2, 2, 4);
    adicionarElemento(vet, l, c, 3, 3, 6);
    adicionarElemento(vet, l, c, 4, 4, 8);
    adicionarElemento(vet, l, c, 4, 5, 10);
    
    adicionarElemento(vet2, l, c, 1, 2, 1);
    adicionarElemento(vet2, l, c, 2, 1, 3);
    adicionarElemento(vet2, l, c, 3, 2, 5);
    adicionarElemento(vet2, l, c, 4, 1, 7);
    adicionarElemento(vet2, l, c, 4, 2, 9);
    
    adicionarElemento(vet, l, c, 3, 8, 13);
    adicionarElemento(vet, l, c, 7, 3, 22);
    adicionarElemento(vet, l, c, 7, 7, 14);
    
    mostarMatriz(vet, l, c);
    printf("\n");
    mostarMatriz(vet2, l, c);

    printf("\nElemento [4][5]: %d \n", buscarElemento(vet, l, c, 4, 5));
    printf("%d \n", buscarElemento(vet, l, c, 2, 8));

    somarMatrizes(vet, vet2, vetR, l, c);

    mostarMatriz(vetR, l, c);
    return 0;
}