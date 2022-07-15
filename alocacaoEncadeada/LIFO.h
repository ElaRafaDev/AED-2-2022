#ifndef ALOCACAOENCADEADA_LIFO_H
#define ALOCACAOENCADEADA_LIFO_H

NoSimples *iniciaPilha(); // Inicia a pilha
NoSimples *criaNoLIFO(int chave); // Cria um novo no da pilha
NoSimples *desalocaPilha(NoSimples **pilha); // Desaloca a pilha
void insercaoLIFO(NoSimples **pilha, int chave); // Insere um novo no na pilha
void remocaoLIFO(NoSimples **pilha); // Remove o no mais novo da pilha

#endif //ALOCACAOENCADEADA_LIFO_H
