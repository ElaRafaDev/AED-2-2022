#include <stdio.h>
#include <stdlib.h>
#include "No.h"
#include "LIFO.h"

NoSimples *iniciaPilha() {
    return NULL; // Pilha vazia
}

NoSimples *criaNoLIFO(int chave) {
    NoSimples *no = malloc(sizeof(NoSimples)); // Cria um novo no da pilha

    no->proximo = NULL;
    no->chave = chave; // A chave do novo no é a chave passada como parâmetro

    return no; // Retorna o novo no da pilha
}

NoSimples *desalocaPilha(NoSimples **pilha) {
    if (*pilha != NULL) { // Se a pilha não for nula
        NoSimples *atual, *proximo; // Variáveis para percorrer a pilha

        atual = *pilha; // Ponteiro para o primeiro nó da pilha

        while (atual != NULL) { // Enquanto não chegar no final da pilha
            proximo = atual->proximo; // Ponteiro para o próximo nó da pilha
            free(atual); // Libera o nó atual
            atual = proximo; // Ponteiro para o nó atual da pilha
        }

        *pilha = NULL;
        free(*pilha); // Libera o ponteiro para a pilha
    }

    return *pilha; // Retorna a pilha desalocada
}

void insercaoLIFO(NoSimples **pilha, int chave) {
    NoSimples *novo_no = criaNoLIFO(chave); // Cria um novo no da pilha

    if (*pilha == NULL) { // Se a pilha for nula
        *pilha = novo_no; // O primeiro nó da pilha será o novo no
    } else { // Se a pilha não for nula
        NoSimples *atual = *pilha; // Ponteiro para o primeiro nó da pilha

        while (atual->proximo != NULL) // Enquanto não chegar no final da pilha
            atual = atual->proximo; // Ponteiro para o próximo nó da pilha

        atual->proximo = novo_no; // O próximo nó da pilha será o novo no
    }
}

void remocaoLIFO(NoSimples **pilha) {
    if (*pilha != NULL) { // Se a pilha não for nula
        NoSimples *ultimo, *penultimo; // Variáveis para percorrer a pilha

        ultimo = (*pilha)->proximo; // Ponteiro para o proximo nó da pilha
        penultimo = *pilha; // Ponteiro para o primeiro nó da pilha

        if (ultimo != NULL) { // Se o próximo nó da pilha não for nulo
            while (ultimo->proximo != NULL) { // Enquanto não chegar no final da pilha
                penultimo = ultimo; // Ponteiro para o nó atual da pilha
                ultimo = ultimo->proximo; // Ponteiro para o próximo nó da pilha
            }

            penultimo->proximo = NULL; // O próximo nó do penultimo nó da pilha será nulo
            free(ultimo); // Libera o nó ultimo da pilha
        } else { // Se o próximo nó da pilha for nulo
            *pilha = NULL;
            free(*pilha); // Libera o ponteiro para a pilha
        }
    }
}