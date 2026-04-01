#include <stdio.h>
#include <stdbool.h>
#define ERROR -999

int l, c;
int n;

int getIndex(int posL, int posC) {
    if (posL <= l && posC <= c && posL > 0 && posC > 0) {
        return (posL - 1) * c + (posC - 1);
    }
    return ERROR;
}

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

void zerarMatriz(int vet[]) {
    for (int i = 1; i < l + 1 ; i++){   
        for (int j = 1; j < c + 1; j++){
            adicionarElemento(vet, i, j, 0);
        }
    }
}

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

void mostarMatriz(int vet[]){
    for (int i = 1; i < l + 1; i++){   
        for (int j = 1; j < c + 1; j++){
            printf("%d ", buscarElemento(vet, i, j));
        }
        printf(" \n");
    }
}

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

void cidadesIsoladas(int vet[]) {

    bool temSaida;
    bool temEntrada;
    bool isolada = false;

        for (int k = 1; k <= n; k++) {
            temSaida = false;
            temEntrada = false;

            for (int j = 1; j <= n; j++) {
                if (j != k && buscarElemento(vet, k, j) == 1) {
                    temSaida = true;
                    break;
                }
            }

            for (int i = 1; i <= n; i++) {
                if (i != k && buscarElemento(vet, i, k) == 1) {
                    temEntrada = true;
                    break;
                }
            }

            if (!temSaida && !temEntrada) {
                isolada = true;
                printf("Cidade %d esta isolada\n", k - 1);

            }
        }
        if (!isolada){printf("Nenhuma cidade isolada \n");}
        
}

void cidadesSemSaidaComEntrada(int vet[]) {
    bool temSaida;
    bool temEntrada;
    bool existe = false;

        for (int k = 1; k <= n; k++) {
            temSaida = false;
            temEntrada = false;

            for (int j = 1; j <= n; j++) {
                if (j != k && buscarElemento(vet, k, j) == 1) {
                    temSaida = true;
                    break;
                }
            }

            for (int i = 1; i <= n; i++) {
                if (i != k && buscarElemento(vet, i, k) == 1) {
                    temEntrada = true;
                    break;
                }
            }

            if (!temSaida && temEntrada) {
                existe = true;
                printf("Cidade %d nao tem saida, apesar de ter entrada.\n", k - 1);

            }
        }
        if (!existe){printf("Nenhuma esta sem saida, apesar de ter entrada.\n");}
    
}

void cidadesComSaidaSemEntrada(int vet[]) {
    bool temSaida;
    bool temEntrada;
    bool existe = false;

        for (int k = 1; k <= n; k++) {
            temSaida = false;
            temEntrada = false;

            for (int j = 1; j <= n; j++) {
                if (j != k && buscarElemento(vet, k, j) == 1) {
                    temSaida = true;
                    break;
                }
            }

            for (int i = 1; i <= n; i++) {
                if (i != k && buscarElemento(vet, i, k) == 1) {
                    temEntrada = true;
                    break;
                }
            }

            if (temSaida && !temEntrada) {
                existe = true;
                printf("Cidade %d tem saida, apesar de nao ter entrada.\n", k - 1);

            }
        }
        if (!existe){printf("Nenhuma esta sem entrada, apesar de ter saida.\n");}
}

void chegaMaisEstradas(int vet[]) {
    int countEntradas;
    int cidade;
    int maxAnterior = 0;

    for (int k = 1; k <= n; k++) {
        countEntradas = 0;
        for (int i = 1; i <= n; i++) {
            if (i != k && buscarElemento(vet, i, k) == 1) {
                countEntradas++;
            }
            
        }
        if (countEntradas > maxAnterior) {
            maxAnterior = countEntradas;
            cidade = k;
        }
        

    }
    printf("A cidade %d recebeu o maior numero de entradas: %d \n", cidade - 1, maxAnterior);
    
}

void cidadesComSaidaParaK(int vet[], int cidadeK) {

    bool existe = false;

    for (int i = 1; i <= n; i++) {
        if (i != cidadeK + 1 && buscarElemento(vet, i, cidadeK + 1) == 1) {
            printf("Cidade %d tem saida para a cidade %d. \n", i - 1, cidadeK);
            existe = true;
        }
        
    }
    if (!existe) {printf("Nao existe cidade que tenha saida para a cidade %d \n", cidadeK);}
    
}

void verificarRoteiro(int vet[], int roteiro[], int tamanhoM) {
    
    bool ePossivel = true;
    int origem;
    int destino;

    for (int k = 0; k < tamanhoM - 1; k++) {
        origem = roteiro[k] + 1;
        destino = roteiro[k + 1] + 1;
        if (buscarElemento(vet, origem, destino) == 0) {
            ePossivel = false;
            printf("O roteiro e IMPOSSIVEL. Pois nao existe a rota %d --> %d \n \n", roteiro[k], roteiro[k + 1]);
            break;
        }
    }
    if (ePossivel) {
        printf("O roteiro e POSSIVEL. \n \n");
    }
}

int verificarMatrizInversa(int vetA[], int vetB[]) {
    int resultado[n*n];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int soma = 0;
            adicionarElemento(resultado, i, j, 0);
            for (int k = 1; k <= n; k++) {
                soma += buscarElemento(vetA, i, k) * buscarElemento(vetB, k, j);
            }
            adicionarElemento(resultado, i, j, soma);
            
        }
    }
    
    //verificar se é identidade
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j && buscarElemento(resultado, i, j) != 1) {
                printf("A matriz B NAO E INVERSA de A, pois retorna: \n");
                mostarMatriz(resultado);
                return 0;
            }
            if (i != j && buscarElemento(resultado, i, j) != 0) {
                printf("A matriz B NAO E INVERSA de A, pois retorna: \n");
                mostarMatriz(resultado);
                return 0;
            }
        }
    }
    
    printf("A matriz B E INVERSA de A, pois retorna: \n");
    mostarMatriz(resultado);
    return 1;
}

int main() {

    n = 5;
    l = n;
    c = n;

    int vet1[l*c];
    int vet2[l*c];
    
    zerarMatriz(vet1);
    zerarMatriz(vet2);
    
// ---------------------------------------

    adicionarElemento(vet1, 1, 1, 1);
    adicionarElemento(vet1, 1, 2, 1);
    adicionarElemento(vet1, 1, 3, 1);
    adicionarElemento(vet1, 1, 4, 0);
    adicionarElemento(vet1, 1, 5, 1);
    
    adicionarElemento(vet1, 2, 1, 0);
    adicionarElemento(vet1, 2, 2, 1);
    adicionarElemento(vet1, 2, 3, 0);
    adicionarElemento(vet1, 2, 4, 0);
    adicionarElemento(vet1, 2, 5, 0);
    
    adicionarElemento(vet1, 3, 1, 1);
    adicionarElemento(vet1, 3, 2, 0);
    adicionarElemento(vet1, 3, 3, 1);
    adicionarElemento(vet1, 3, 4, 1);
    adicionarElemento(vet1, 3, 5, 0);
    
    adicionarElemento(vet1, 4, 1, 0);
    adicionarElemento(vet1, 4, 2, 0);
    adicionarElemento(vet1, 4, 3, 1);
    adicionarElemento(vet1, 4, 4, 1);
    adicionarElemento(vet1, 4, 5, 1);
    
    adicionarElemento(vet1, 5, 1, 0);
    adicionarElemento(vet1, 5, 2, 0);
    adicionarElemento(vet1, 5, 3, 1);
    adicionarElemento(vet1, 5, 4, 0);
    adicionarElemento(vet1, 5, 5, 1);

// ---------------------------------------

    adicionarElemento(vet2, 1, 1, 1);
    adicionarElemento(vet2, 1, 2, 0);
    adicionarElemento(vet2, 1, 3, 1);
    adicionarElemento(vet2, 1, 4, 0);
    adicionarElemento(vet2, 1, 5, 0);

    adicionarElemento(vet2, 2, 1, 0);
    adicionarElemento(vet2, 2, 2, 1);
    adicionarElemento(vet2, 2, 3, 0);
    adicionarElemento(vet2, 2, 4, 0);
    adicionarElemento(vet2, 2, 5, 1);

    adicionarElemento(vet2, 3, 1, 1);
    adicionarElemento(vet2, 3, 2, 0);
    adicionarElemento(vet2, 3, 3, 1);
    adicionarElemento(vet2, 3, 4, 0);
    adicionarElemento(vet2, 3, 5, 0);

    adicionarElemento(vet2, 4, 1, 1);
    adicionarElemento(vet2, 4, 2, 0);
    adicionarElemento(vet2, 4, 3, 0);
    adicionarElemento(vet2, 4, 4, 1);
    adicionarElemento(vet2, 4, 5, 1);
    
    adicionarElemento(vet2, 5, 1, 1);
    adicionarElemento(vet2, 5, 2, 1);
    adicionarElemento(vet2, 5, 3, 1);
    adicionarElemento(vet2, 5, 4, 0);
    adicionarElemento(vet2, 5, 5, 1);
    
// ---------------------------------------

    printf("M1\n");
    mostarMatriz(vet1);
    printf("\nM2\n");
    mostarMatriz(vet2);
    printf("\nCidades isoladas M1: \n");
    cidadesIsoladas(vet1);
    printf("\nCidades isoladas M2: \n");
    cidadesIsoladas(vet2);
    printf("\nCidades sem saida e com entrada M1: \n");
    cidadesSemSaidaComEntrada(vet1);
    printf("\nCidades sem saida e com entrada M2: \n");
    cidadesSemSaidaComEntrada(vet2);
    printf("\nCidade que recebeu mais entradas M1: \n");
    chegaMaisEstradas(vet1);
    printf("\nCidade que recebeu mais entradas M2: \n");
    chegaMaisEstradas(vet2);
    printf("\n");
    cidadesComSaidaParaK(vet1, 3);
    printf("\n");
    cidadesComSaidaParaK(vet2, 3);
    int roteiro[5] = {2, 3, 2, 0, 2};
    int roteiro2[5] = {2, 3, 2, 1, 0};
    printf("Verificando roteiro para M1: \n");
    verificarRoteiro(vet1, roteiro, 5);
    printf("\n");
    printf("Verificando roteiro para M2: \n");
    verificarRoteiro(vet1, roteiro, 5);

// ---------------------------------------

    int matrizTeste1[25] = {1,2,0,1,3,
                            0,1,3,0,2,
                            0,0,1,1,0,
                            0,0,0,1,2,
                            0,0,0,0,1};
    int matrizTeste2[25] = {1,-2,6,-7,14,
                            0,1,-3,3,-8,
                            0,0,1,-1,2,
                            0,0,0,1,-2,
                            0,0,0,0,1};

    verificarMatrizInversa(matrizTeste1, matrizTeste2);
    
    return 0;
}