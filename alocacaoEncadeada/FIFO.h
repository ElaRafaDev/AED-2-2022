#ifndef ALOCACAOENCADEADA_FIFO_H
#define ALOCACAOENCADEADA_FIFO_H

NoSimples *iniciaFila(); // Inicia a fila
NoSimples *criaNoFIFO(int chave); // Cria um novo no da fila
NoSimples *desalocaFila(NoSimples **fila); // Desaloca a fila
void insercaoFIFO(NoSimples **fila, int chave); // Insere um novo no na fila
void remocaoFIFO(NoSimples **fila); // Remove o no mais antigo da fila

#endif //ALOCACAOENCADEADA_FIFO_H
