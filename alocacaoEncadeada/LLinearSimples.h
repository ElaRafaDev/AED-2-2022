#ifndef ALOCACAOENCADEADA_LLINEARSIMPLES_H
#define ALOCACAOENCADEADA_LLINEARSIMPLES_H

NoSimples *iniciaListaLinearSimples(); // Inicia a lista
NoSimples *criaNoLinearSimples(int chave); // Cria um novo no
NoSimples *desalocaListaLinearSimples(NoSimples **lista); // Desaloca a lista
NoSimples *buscaNoLinearSimples(NoSimples *lista, int chave); // Busca um no na lista
void insercaoOrdenadaNoLinearSimples(NoSimples **lista, int chave); // Insere um no ordenado
void remocaoNoLinearSimples(NoSimples **lista, int chave); // Remove um no da lista

#endif //ALOCACAOENCADEADA_LLINEARSIMPLES_H
