#include <stdio.h>
#include <stdlib.h>
#include "No.h"
#include "FIFO.h"

NoSimples *iniciaFila() {
    return NULL; // Fila vazia
}

NoSimples *criaNoFIFO(int chave) {
    NoSimples *no = malloc(sizeof(NoSimples)); // Cria um novo no da fila

    no->proximo = NULL;
    no->chave = chave; // A chave do novo no é a chave passada como parâmetro

    return no; // Retorna o novo no da fila
}

NoSimples *desalocaFila(NoSimples **fila) {
    if (fila != NULL) { // Se a fila não for nula
        NoSimples *atual, *proximo; // Variáveis para percorrer a fila

        atual = *fila; // Ponteiro para o primeiro nó da fila

        while (atual != NULL) { // Enquanto não chegar no final da fila
            proximo = atual->proximo; // Ponteiro para o próximo nó da fila
            free(atual); // Libera o nó atual
            atual = proximo; // Ponteiro para o nó atual da fila
        }

        *fila = NULL;
        free(*fila); // Libera o ponteiro para a fila
    }

    return *fila; // Retorna a fila desalocada
}

void insercaoFIFO(NoSimples **fila, int chave) {
    NoSimples *novo_no = criaNoFIFO(chave); // Cria um novo no da fila

    if (*fila == NULL) { // Se a fila for nula
        *fila = novo_no; // O primeiro nó da fila será o novo no
    } else { // Se a fila não for nula
        NoSimples *atual = *fila; // Ponteiro para o primeiro nó da fila

        while (atual->proximo != NULL) // Enquanto não chegar no final da fila
            atual = atual->proximo; // Ponteiro para o próximo nó da fila

        atual->proximo = novo_no; // O próximo nó da fila será o novo no
    }
}

void remocaoFIFO(NoSimples **fila) {
    if (*fila != NULL) { // Se a fila não for nula
        NoSimples *atual = *fila; // Ponteiro para o primeiro nó da fila

        *fila = atual->proximo; // O primeiro nó da fila será o segundo nó da fila
        free(atual); // Libera o primeiro nó da fila
    }
}