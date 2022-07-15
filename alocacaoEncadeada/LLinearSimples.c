#include <stdio.h>
#include <stdlib.h>
#include "No.h"
#include "LLinearSimples.h"

// Lista linear simplesmente encadeada sem nó cabeça ordenada

NoSimples *iniciaListaLinearSimples() {
    return NULL; // Lista sem nó cabeca
}

NoSimples *criaNoLinearSimples(int chave) {
    NoSimples *no = malloc(sizeof(NoSimples)); // Aloca memória para o nó

    no->proximo = NULL;
    no->chave = chave; // Chave do nó é a chave passada como parâmetro

    return no; // Retorna o nó criado
}

NoSimples *desalocaListaLinearSimples(NoSimples **lista) {
    if (*lista != NULL) { // Se a lista não for vazia
        NoSimples *atual, *proximo; // Variáveis para percorrer a lista

        atual = *lista; // Ponteiro para o primeiro nó da lista

        while (atual != NULL) { // Enquanto não chegar no final da lista
            proximo = atual->proximo; // Ponteiro para o próximo nó da lista
            free(atual); // Libera o nó atual
            atual = proximo; // Ponteiro para o nó atual da lista
        }

        *lista = NULL;
        free(*lista); // Libera o ponteiro para a lista
    }

    return *lista; // Retorna a lista desalocada
}

NoSimples *buscaNoLinearSimples(NoSimples *lista, int chave) {
    NoSimples *no = NULL; // Nó a ser buscado

    if (lista != NULL) { // Se a lista não for vazia
        no = lista; // Ponteiro para o primeiro nó da lista

        while (no != NULL && no->chave != chave) // Enquanto não chegar no final da lista e não encontrar o nó
            no = no->proximo; // Ponteiro para o próximo nó da lista
    }

    return no; // Retorna o nó buscado ou NULL se não encontrado
}

void insercaoOrdenadaNoLinearSimples(NoSimples **lista, int chave) {
    NoSimples *novo_no = criaNoLinearSimples(chave); // Cria o nó a ser inserido

    if (*lista == NULL) { // Se a lista for vazia
        novo_no->proximo = NULL; // O próximo nó da lista será NULL
        *lista = novo_no; // O primeiro nó da lista será o nó a ser inserido
    } else if (novo_no->chave < (*lista)->chave) { // Se a chave a ser inserida for menor que a chave do primeiro nó da lista
        novo_no->proximo = *lista; // O próximo nó da lista será o primeiro nó da lista
        *lista = novo_no; // O primeiro nó da lista será o nó a ser inserido
    } else { // Se a chave a ser inserida for maior ou igual a chave do primeiro nó da lista e lista não for vazia
        NoSimples *atual; // Variável para percorrer a lista

        atual = *lista; // Ponteiro para o primeiro nó da lista

        // Enquanto não chegar no final da lista e a chave do próximo nó for menor ou igual à chave a ser inserida
        while (atual->proximo != NULL && atual->proximo->chave <= novo_no->chave)
            atual = atual->proximo; // Ponteiro para o próximo nó da lista

        // Se atual->proximo->chave <= novo_no->chave o ponteiro atual aponta para o nó que tem a chave menor ou igual à chave a ser inserida
        // Se atual->proximo == NULL o ponteiro atual aponta para o último nó da lista

        novo_no->proximo = atual->proximo; // O próximo nó do novo nó será o próximo nó do nó atual
        atual->proximo = novo_no; // O próximo nó da lista será o nó a ser inserido
    }
}

void remocaoNoLinearSimples(NoSimples **lista, int chave) {
    if (*lista != NULL) { // Se a lista não for vazia
        NoSimples *no = buscaNoLinearSimples(*lista, chave); // Busca o nó a ser removido

        if (no == NULL) // Se o nó a ser removido não for encontrado
            return; // Não faz nada

        if (*lista == no && (*lista)->proximo == NULL) { // Se o nó a ser removido for o primeiro nó da lista e o próximo nó da lista for NULL
            *lista = NULL;
            free(*lista); // Libera o ponteiro para a lista
        } else if (*lista == no && (*lista)->proximo != NULL) { // Se o nó a ser removido for o primeiro nó da lista e o próximo nó da lista não for NULL
            *lista = (*lista)->proximo; // O primeiro nó da lista será o próximo nó da lista
            free(no); // Libera o nó a ser removido
        }else { // Se o nó a ser removido não for o primeiro nó da lista e o próximo nó da lista não for NULL

            NoSimples *anterior, *proximo; // Variáveis para percorrer a lista

            anterior = *lista; // Ponteiro para o primeiro nó da lista
            proximo = (*lista)->proximo; // Ponteiro para o próximo nó da lista

            while (proximo->proximo != NULL && anterior->proximo != no) { // Enquanto não chegar no final da lista e não encontrar o nó a ser removido
                anterior = proximo; // anterior aponta para o próximo nó da lista
                proximo = proximo->proximo; // proximo aponta para o próximo nó da lista
            }

            anterior->proximo = proximo->proximo; // O próximo nó do nó anterior será o próximo nó do nó a ser removido
            free(no); // Libera o nó a ser removido
        }
    }
}