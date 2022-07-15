#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinariaBusca.h"

int main() {
    noArvore *raiz = iniciaRaiz();

    insercaoNo(&raiz, 10);
    insercaoNo(&raiz, 5);
    insercaoNo(&raiz, 15);
    insercaoNo(&raiz, 3);
    insercaoNo(&raiz, 7);
    insercaoNo(&raiz, 13);
    insercaoNo(&raiz, 17);

    remocaoNo(raiz, 3);

    printf("\nArvore Ordenada:\n");
    imprimeArvoreOrdenada(raiz);
    printf("\nArvore Nao Ordenada:\n");
    imprimeArvoreNaoOrdenada(raiz);
    return 0;
}