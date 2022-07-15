#include <stdio.h>
#include <stdlib.h>
#include "No.h"
#include "LLinearDupla.h"

// Lista linear duplamente encadeada com nó cabeça não ordenada

NoDuplo *iniciaListaLinearDupla() {
    NoDuplo *no = malloc(sizeof(NoDuplo)); // Aloca memória para o nó cabeça

    no->anterior = NULL;
    no->proximo = NULL;
    no->chave = 0; // Chave do nó cabeça é 0

    return no; // Retorna o nó cabeça
}

NoDuplo *criaNoLinearDuplo(int chave) {
    NoDuplo *no = malloc(sizeof(NoDuplo)); // Aloca memória para o nó

    no->anterior = NULL;
    no->proximo = NULL;
    no->chave = chave; // Chave do nó é a chave passada como parâmetro

    return no; // Retorna o nó criado
}

NoDuplo *desalocaListaLinearDupla(NoDuplo **lista) {
    if ((*lista)->proximo != NULL) { // Se a lista não estiver vazia
        NoDuplo *atual, *proximo; // Variáveis para percorrer a lista

        atual = (*lista)->proximo; // Ponteiro para o primeiro nó da lista

        while (atual != NULL) { // Enquanto não chegar ao final da lista
            proximo = atual->proximo; // Ponteiro para o próximo nó da lista
            free(atual); // Libera memória do nó atual
            atual = proximo; // Ponteiro para o nó atual da lista
        }

        *lista = NULL;
        free(*lista); // Libera o ponteiro para a lista
    }

    return *lista;
}

NoDuplo *buscaNoLinearDuplo(NoDuplo *lista, int chave) {
    NoDuplo *no = NULL; // Nó a ser buscado

    if (lista->proximo != NULL) { // Se a lista não estiver vazia
        no = lista->proximo; // Ponteiro para o primeiro nó da lista

        while (no != NULL && no->chave != chave) // Enquanto não chegar ao final da lista e não encontrar o nó buscado
            no = no->proximo; // Ponteiro para o próximo nó da lista
    }

    return no; // Retorna o nó buscado ou NULL se não encontrado
}

void insercaoNoLinearDuplo(NoDuplo *lista, int chave) {
    NoDuplo *novo_no = criaNoLinearDuplo(chave); // Cria o nó a ser inserido

    if (lista->proximo == NULL){
        lista->proximo = novo_no;
        novo_no->anterior = lista;
        novo_no->proximo = NULL;
    }else if (lista->proximo->proximo == NULL){
        lista->proximo->proximo = novo_no;
        novo_no->anterior = lista->proximo;
    } else {
        NoDuplo *anterior, *proximo; // Variáveis para percorrer a lista

        anterior = lista->proximo; // Ponteiro para o primeiro nó da lista
        proximo = anterior->proximo; // Ponteiro para o próximo nó da lista

        while (proximo->proximo != NULL) { // Enquanto não chegar ao final da lista
            anterior = proximo; // Anterior recebe o próximo nó da lista
            proximo = proximo->proximo; // Ponteiro para o próximo nó da lista
        }

        anterior->proximo = novo_no; // O ponteiro próximo nó do anterior recebe o nó a ser inserido
        novo_no->anterior = anterior; // O ponteiro anterior do nó a ser inserido recebe o anterior
        proximo->anterior = novo_no; // O ponteiro anterior do próximo nó da lista recebe o nó a ser inserido
        novo_no->proximo = proximo; // O ponteiro próximo do nó a ser inserido recebe o próximo nó da lista
    }
}

void remocaoNoLinearDuplo(NoDuplo **lista, int chave) {
    if ((*lista)->proximo != NULL) { // Se a lista não estiver vazia
        NoDuplo *no = buscaNoLinearDuplo(*lista, chave); // Busca o nó a ser removido

        if (no == NULL) // Se o nó não for encontrado
            return; // Não faz nada

        NoDuplo *anterior, *proximo; // Variáveis para percorrer a lista

        anterior = no->anterior; // O ponteiro anterior do nó a ser removido recebe o anterior do nó a ser removido
        proximo = no->proximo; // O ponteiro próximo do nó a ser removido recebe o próximo do nó a ser removido
        anterior->proximo = proximo; // O ponteiro próximo do nó anterior recebe o próximo do nó a ser removido
        if (proximo != NULL) // Se o próximo nó da lista não for nulo
            proximo->anterior = anterior; // O ponteiro anterior do próximo nó da lista recebe o nó anterior

        free(no);
    }
}