#ifndef ALOCACAOENCADEADA_LLINEARDUPLA_H
#define ALOCACAOENCADEADA_LLINEARDUPLA_H

NoDuplo *iniciaListaLinearDupla(); // Inicia a lista
NoDuplo *criaNoLinearDuplo(int chave); // Cria um novo no
NoDuplo *desalocaListaLinearDupla(NoDuplo **lista); // Desaloca a lista
NoDuplo *buscaNoLinearDuplo(NoDuplo *lista, int chave); // Busca um no na lista
void insercaoNoLinearDuplo(NoDuplo *lista, int chave); // Insere um no na lista
void remocaoNoLinearDuplo(NoDuplo **lista, int chave); // Remove um no da lista

#endif //ALOCACAOENCADEADA_LLINEARDUPLA_H
