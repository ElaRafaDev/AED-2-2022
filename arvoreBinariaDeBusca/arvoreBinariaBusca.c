#include <stdio.h>
#include <stdlib.h>
#include "no.h"
#include "arvoreBinariaBusca.h"

noArvore *iniciaRaiz() {
    return NULL;
}

noArvore *criaNo(int chave) {
    noArvore *no = malloc(sizeof(noArvore));

    no->direita = NULL;
    no->esquerda = NULL;
    no->chave = chave;

    return no;
}

noArvore *buscaRecursivaNo(noArvore *raiz, int chave) {
    if (raiz != NULL) {
        if (raiz->chave > chave)
            return buscaRecursivaNo(raiz->esquerda, chave);
        else if (raiz->chave < chave)
            return buscaRecursivaNo(raiz->direita, chave);
        else
            return raiz;
    }

    return NULL;
}

void insercaoNo(noArvore **raiz, int chave) {
    noArvore *atual = *raiz;

    while (atual != NULL) {
        if (atual->chave > chave)
            raiz = &atual->esquerda;
        else if (atual->chave < chave)
            raiz = &atual->direita;
        else
            return;

        atual = *raiz;
    }

    *raiz = criaNo(chave);
}

void remocaoNoRaiz(noArvore *raiz) {
    if (raiz->esquerda == NULL && raiz->direita == NULL) {
        free(raiz);
        raiz = NULL;
    }
}

void remocaoNoUmaFolha(noArvore *raiz) {
    noArvore *atual;

    if (raiz->esquerda == NULL) {
        atual = raiz;
        raiz = raiz->direita;
        free(atual);
    } else if (raiz->direita == NULL) {
        atual = raiz;
        raiz = raiz->esquerda;
        free(atual);
    }
}

noArvore *menorSubArvoreDireita(noArvore *raiz) {
    noArvore *atual = NULL;

    if (raiz->esquerda != NULL && raiz->direita != NULL) {
        atual = raiz->direita;

        while (atual->esquerda != NULL)
            atual = atual->esquerda;
    }

    return atual;
}

void remocaoNo(noArvore *raiz, int chave) {
    if (raiz->chave > chave)
        remocaoNo(raiz->esquerda, chave);
    else if (raiz->chave < chave)
        remocaoNo(raiz->direita, chave);
    else {
        if (raiz->esquerda == NULL && raiz->direita == NULL)
            remocaoNoRaiz(raiz);
        else if (raiz->esquerda == NULL || raiz->direita == NULL)
            remocaoNoUmaFolha(raiz);
        else {
            noArvore *atual = menorSubArvoreDireita(raiz);

            raiz->chave ==  atual->chave;
            atual->chave = chave;
            remocaoNo(raiz->direita, chave);
        }
    }
}

void imprimeArvoreOrdenada(noArvore *raiz) {
    if (raiz != NULL) {
        imprimeArvoreOrdenada(raiz->esquerda);
        printf("\t%d", raiz->chave);
        imprimeArvoreOrdenada(raiz->direita);
    }
}

void imprimeArvoreNaoOrdenada(noArvore *raiz) {
    if (raiz != NULL) {
        printf("\t%d", raiz->chave);
        imprimeArvoreNaoOrdenada(raiz->esquerda);
        imprimeArvoreNaoOrdenada(raiz->direita);
    }
}