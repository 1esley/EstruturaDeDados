#include "Impressora.h"

FilaImpressora filaImpressora = {
    .inicio = 0,
    .fim = -1,
    .quantidade = 0
};

// Adicionar o papel calculando a prioridade
void adicionaPedido() {

    if (filaImpressora.quantidade == TAM_MAX_FILA) {
        printf("Fila cheia!\n");
        return;
    }

    Papel papel;

    printf("Insira a descricao do documento: ");
    scanf(" %[^\n]", papel.titulo);
    
    printf("\nInsira a prioridade do documento (1 - 2 - 3): ");
    scanf("%d", &papel.prioridade);

    filaImpressora.fim = (filaImpressora.fim + 1) % TAM_MAX_FILA;
    filaImpressora.fila[filaImpressora.fim] = papel;
    filaImpressora.quantidade++;

    int controle = filaImpressora.fim;

    while (controle != filaImpressora.inicio) {
        int anterior = (controle - 1 + TAM_MAX_FILA) % TAM_MAX_FILA;

        if (filaImpressora.fila[anterior].prioridade <= filaImpressora.fila[controle].prioridade) {
            break;
        }
        
        Papel papelControle = filaImpressora.fila[controle];

        filaImpressora.fila[controle] = filaImpressora.fila[anterior];

        filaImpressora.fila[anterior] = papelControle;

        controle = anterior;

    }
    
    printf("\n%s adicionado!\n", papel.titulo);

    // -> -> -> -> -> -> -> -> saida
    // 3a 1a 2a 3b 3c 1b 1c 1d 2b 3d 
    // <- <- <- <- <- <- <- <- entrada

    // 1a 1b 1c 1d 2a 2b 3a 3b 3c 3d

}

void mostrarFila() {

    if (filaImpressora.quantidade == 0){
        printf("Fila vazia!\n");
        return;
    }

    printf("FILA: ");

    int i;
    int pos = filaImpressora.inicio;

    for(i = 0; i < filaImpressora.quantidade; i++) {
        printf("%s - ", filaImpressora.fila[pos].titulo);
        printf("%d | ", filaImpressora.fila[pos].prioridade);
        pos = (pos + 1) % TAM_MAX_FILA;
    }
    printf("\n");

}