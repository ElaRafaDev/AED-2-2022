#ifndef ALOCACAOENCADEADA_NO_H
#define ALOCACAOENCADEADA_NO_H

// Estrutura de dados para armazenar um nó da lista encadeada

struct noSimples {
    int chave; // chave do nó
    struct noSimples *proximo; // ponteiro para o próximo nó
};

struct noDuplo {
    int chave; // chave do nó
    struct noDuplo *anterior; // ponteiro para o nó anterior
    struct noDuplo *proximo; // ponteiro para o próximo nó
};

typedef struct noSimples NoSimples; // tipo de dado para o nó simples
typedef struct noDuplo NoDuplo; // tipo de dado para o nó duplo

#endif //ALOCACAOENCADEADA_NO_H
