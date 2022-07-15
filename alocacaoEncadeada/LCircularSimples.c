#include <stdio.h>
#include <stdlib.h>
#include "No.h"
#include "LCircularSimples.h"

// Lista circular simplesmente encadeada com nó cabeça ordenada

NoSimples *iniciaListaCircularSimples() {
    return NULL; // Lista sem nó cabeca
}

NoSimples *criaNoCircularSimples(int chave) {
    NoSimples *no = malloc(sizeof(NoSimples)); // Aloca memória para o nó

    no->proximo = NULL;
    no->chave = chave; // Chave do nó é a chave passada como parâmetro

    return no; // Retorna o nó criado
}

NoSimples *desalocaListaCircularSimples(NoSimples **lista) {
    if (*lista != NULL) { // Se a lista não for vazia
        NoSimples *atual, *proximo; // Variáveis para percorrer a lista

        atual = (*lista)->proximo; // Ponteiro para o próximo nó da lista

        while (atual != *lista) { // Enquanto não chegar no início da lista
            proximo = atual->proximo; // Ponteiro para o próximo nó da lista
            free(atual); // Libera o nó atual
            atual = proximo; // ponteiro para o nó atual da lista
        }

        *lista = NULL;
        free(*lista); // Libera o ponteiro para a lista
    }

    return *lista; // Retorna a lista desalocada
}

NoSimples *buscaNoCircularSimples(NoSimples *lista, int chave) {
    NoSimples *no = NULL; // Nó a ser buscado

    if (lista != NULL) { // Se a lista não for vazia
        no = lista; // Ponteiro para o primeiro nó da lista

        do
            no = no->proximo; // Ponteiro para o próximo nó da lista
        while (no != lista && no->chave != chave); // Enquanto não chegar no início da lista e não encontrar o nó

        if (no == lista && no->chave != chave) // Se não encontrar o nó
            no = NULL;
    }

    return no; // Retorna o nó buscado ou NULL se não encontrado
}

void insercaoOrdenadaNoCircularSimples(NoSimples **lista, int chave) {
    NoSimples *novo_no = criaNoCircularSimples(chave); // Cria o nó a ser inserido

    if (*lista == NULL) { // Se a lista estiver vazia
        novo_no->proximo = novo_no; // O próximo nó do nó a ser inserido é o próprio nó a ser inserido
        *lista = novo_no; // O primeiro nó da lista é o nó a ser inserido
    } else if ((*lista)->chave >= novo_no->chave) { // Se a chave do primeiro nó da lista for maior ou igual à chave do nó a ser inserido
        NoSimples *atual = *lista; // Variável para percorrer a lista

        while (atual->proximo != *lista) // Enquanto não chegar no início da lista
            atual = atual->proximo; // Ponteiro para o próximo nó da lista

        // Se atual->proximo == *lista, então atual é o último nó da lista

        atual->proximo = novo_no; // O ponteiro proximo do no atual aponta o novo nó
        novo_no->proximo = *lista; // O ponteiro proximo do novo nó aponta o primeiro nó da lista
        *lista = novo_no; // O primeiro nó da lista é o novo nó
    } else { //
        NoSimples *atual = *lista; // Variável para percorrer a lista

        // Enquanto não chegar no iníco da lista e o próximo nó da lista for maior ou igual à chave do nó a ser inserido
        while (atual->proximo != *lista && atual->proximo->chave <= novo_no->chave)
            atual = atual->proximo; // Ponteiro para o próximo nó da lista

        // Se atual->proximo == *lista, então atual é o último nó da lista

        novo_no->proximo = atual->proximo; // O ponteiro proximo do novo nó aponta o ponteiro próximo do nó atual da lista
        atual->proximo = novo_no; // O ponteiro proximo do nó atual aponta o novo nó
    }
}

void remocaoNoCircularSimples(NoSimples **lista, int chave) {
    if (*lista != NULL) { // Se a lista não for vazia
        NoSimples *no = buscaNoCircularSimples(*lista, chave); // Busca o nó a ser removido

        if (no == NULL) // Se não encontrar o nó
            return; // Não faz nada

        // Se o nó a ser removido for o primeiro nó da lista
        if (*lista == no && no->proximo == *lista) {
            *lista = NULL;
            free(*lista);
        } else if (*lista == no && (*lista)->proximo != *lista) { // Se o nó a ser removido for o primeiro nó da lista e o próximo nó da lista não for o último nó da lista
            NoSimples *atual = *lista; // Variável para percorrer a lista

            while (atual->proximo != *lista) // Enquanto não chegar no início da lista
                atual = atual->proximo; // Ponteiro para o próximo nó da lista

            atual->proximo = no->proximo; // O ponteiro proximo do nó atual aponta o próximo nó do nó a ser removido
            *lista = atual; // O primeiro nó da lista é o nó atual
            free(no); // Libera o nó a ser removido
        } else { // Se o nó a ser removido não for o primeiro nó da lista
            NoSimples *anterior, *proximo; // Variáveis para percorrer a lista

            anterior = *lista; // Ponteiro para o nó anterior da lista
            proximo = (*lista)->proximo; // Ponteiro para o próximo nó da lista

            // Enquanto não chegar no início da lista e não chegar no nó a ser removido
            while (anterior->proximo != *lista && anterior->proximo != no) {
                anterior = proximo; // Anterior passa a apontar para o próximo nó da lista
                proximo = proximo->proximo; // Ponteiro para o próximo nó da lista
            }

            anterior->proximo = proximo->proximo; // O ponteiro proximo do nó anterior aponta o próximo nó do nó a ser removido
            free(no); // Libera o nó a ser removido
        }
    }
}