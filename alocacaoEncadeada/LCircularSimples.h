#ifndef ALOCACAOENCADEADA_LCIRCULARSIMPLES_H
#define ALOCACAOENCADEADA_LCIRCULARSIMPLES_H

NoSimples *iniciaListaCircularSimples(); // Inicia a lista
NoSimples *criaNoCircularSimples(int chave); // Cria um novo no
NoSimples *desalocaListaCircularSimples(NoSimples **lista); // Desaloca a lista
NoSimples *buscaNoCircularSimples(NoSimples *lista, int chave); // Busca um no na lista
void insercaoOrdenadaNoCircularSimples(NoSimples **lista, int chave); // Insere um no ordenado
void remocaoNoCircularSimples(NoSimples **lista, int chave); // Remove um no da lista

#endif //ALOCACAOENCADEADA_LCIRCULARSIMPLES_H
