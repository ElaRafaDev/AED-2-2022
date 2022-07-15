#ifndef ARVOREBINARIADEBUSCA_ARVOREBINARIABUSCA_H
#define ARVOREBINARIADEBUSCA_ARVOREBINARIABUSCA_H

typedef struct no noArvore;

noArvore *iniciaRaiz();
noArvore *criaNo(int chave);
noArvore *buscaRecursivaNo(noArvore *raiz, int chave);
void insercaoNo(noArvore **raiz, int chave);
void remocaoNoRaiz(noArvore *raiz);
void remocaoNoUmaFolha(noArvore *raiz);
noArvore *menorSubArvoreDireita(noArvore *raiz);
void remocaoNo(noArvore *raiz, int chave);
void imprimeArvoreOrdenada(noArvore *raiz);
void imprimeArvoreNaoOrdenada(noArvore *raiz);

#endif //ARVOREBINARIADEBUSCA_ARVOREBINARIABUSCA_H
