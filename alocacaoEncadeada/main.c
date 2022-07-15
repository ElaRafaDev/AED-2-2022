// Aluna: Rafaela Gettner de Oliveira, RGM: 457670

#include <stdio.h>
#include <stdlib.h>
#include "InterfaceGrafica.h"

// Função que retorna a escolha do usuário no menu de estruturas
unsigned int escolhaMenuEstruturas();
// Função que retorna a escolha do usuário no menu de listas
unsigned int escolhaMenuListas(char *nome_estrutura);
// Função que retorna a escolha do usuário no menu de fila e pilha
unsigned int escolhaMenuFilaEPilha(char *nome_estrutura);
// Função que exibe o menu de lista linear simples sem no cabeca ordenada
void menuListaLinearSimplesSemNoCabecaOrdenada();
// Procedimento que exibe o menu de lista circular simples sem no cabeca ordenada
void menuListaCircularSimplesSemNoCabecaOrdenada();
// Procedimento que exibe o menu de lista linear dupla com no cabeca não ordenada
void menuListaLinearDuplaComNoCabecaNaoOrdenada();
// Procedimento que exibe o menu de fila
void menuFila();
// Procedimento que exibe o menu de pilha
void menuPilha();

unsigned int escolhaMenuEstruturas() {
    unsigned int opcao = 0;

    printf("\nEscolha umas das estruturas de dados:\n\n");
    printf("\t0 - Sair\n\t1 - Lista Linear Simplesmente encadeada sem no cabeca ordenada");
    printf("\n\t2 - Lista Circular Simplesmente encadeada sem no cabeca ordenada");
    printf("\n\t3 - Lista Linear Duplamente encadeada com no cabeca nao ordenada");
    printf("\n\t4 - Fila\n\t5 - Pilha\n\nOpcao: ");
    scanf("%u", &opcao);

    return opcao;
}

unsigned int escolhaMenuListas(char *nome_estrutura) {
    unsigned int opcao = 0;

    printf("\nEstrutura escolhida: %s\n\n", nome_estrutura);
    printf("\t0 - Voltar\n\t1 - Busca\n\t2 - Insercao\n\t3 - Remocao\n\nOpcao: ");
    scanf("%u", &opcao);

    return opcao;
}

unsigned int escolhaMenuFilaEPilha(char *nome_estrutura) {
    unsigned int opcao = 0;

    printf("\nEstrutura escolhida: %s\n\n", nome_estrutura);
    printf("\t0 - Voltar\n\t1 - Insercao\n\t2 - Remocao\n\nOpcao: ");
    scanf("%u", &opcao);

    return opcao;
}

unsigned int escolhaMenuFilaEPilha(char *nome_estrutura);

int recebeChaveBusca() {
    int chave;

    printf("\nDigite a chave a ser buscada: ");
    scanf("%d", &chave);

    return chave;
}

int recebeChaveInsercao() {
    int chave;

    printf("\nDigite a chave a ser inserida: ");
    scanf("%d", &chave);

    return chave;
}

int recebeChaveRemocao() {
    int chave;

    printf("\nDigite a chave a ser removida: ");
    scanf("%d", &chave);

    return chave;
}

void menuListaLinearSimplesSemNoCabecaOrdenada() {
    NoSimples *lista = iniciaListaLinearSimples(); // Inicia a lista
    NoSimples *no_busca = NULL;
    unsigned int opcao;
    int chave;

    do {
        background(); // Limpa e coloca o background na tela
        gfxMostraListaLinearSimples(lista, XI_NO, XI_NO * 2, (YI_NO * 5)); // Mostra a lista
        gfx_paint(); // Aplica as mudanças na tela

        no_busca = NULL; // Limpa o ponteiro de busca

        switch (opcao = escolhaMenuListas("Lista Linear Simplesmente encadeada sem no cabeca ordenada")) {
            case 1: // Busca
                chave = recebeChaveBusca(); // Recebe a chave a ser buscada
                no_busca = buscaNoLinearSimples(lista, chave); // Busca o no com a chave

                if (no_busca == NULL) // Se não encontrar o no
                    printf("\nChave %d nao encontrada!\n", chave);
                else // Se encontrar o no
                    printf("\nChave %d encontrada!\n", no_busca->chave);

                no_busca = NULL; // Limpa o ponteiro de busca
                break;
            case 2: // Insercao
                chave = recebeChaveInsercao(); // Recebe a chave a ser inserida
                insercaoOrdenadaNoLinearSimples(&lista, chave); // Insere o no na lista ordenada
                break;
            case 3: // Remocao
                chave = recebeChaveRemocao(); // Recebe a chave a ser removida
                remocaoNoLinearSimples(&lista, chave);
                break;
            case 0: // Voltar
                lista = desalocaListaLinearSimples(&lista); // Desaloca a lista
                printf("\nRetornando ao menu de estruturas...\n");
                break;
            default: // Opcao invalida
                printf("\nOpcao invalida!\n");
                break;
        }
    } while (opcao != 0); // Enquanto o usuário não escolher a opção 0
}

void menuListaCircularSimplesSemNoCabecaOrdenada() {
    NoSimples *lista = iniciaListaCircularSimples(); // Inicia a lista
    NoSimples *no_busca = NULL, *inicio;
    unsigned int opcao;
    int chave;

    do {
        inicio = lista; // Salva o ponteiro para o inicio da lista

        background(); // Limpa e coloca o background na tela
        gfxMostraListaCircularSimples(lista, inicio, XI_NO, XI_NO * 2, (YI_NO * 5)); // Mostra a lista
        gfx_paint(); // Aplica as mudanças na tela

        switch (opcao = escolhaMenuListas("Lista Circular Simplesmente encadeada sem no cabeca ordenada")) {
            case 1: // Busca
                chave = recebeChaveBusca(); // Recebe a chave a ser buscada
                no_busca = buscaNoCircularSimples(lista, chave); // Busca o no com a chave

                if (no_busca == NULL) // Se não encontrar o no
                    printf("\nChave %d nao encontrada!\n", chave);
                else // Se encontrar o no
                    printf("\nChave %d encontrada!\n", no_busca->chave);

                no_busca = NULL; // Limpa o ponteiro de busca
                break;
            case 2: // Insercao
                chave = recebeChaveInsercao(); // Recebe a chave a ser inserida
                insercaoOrdenadaNoCircularSimples(&lista, chave); // Insere o no na lista ordenada
                break;
            case 3: // Remocao
                chave = recebeChaveRemocao(); // Recebe a chave a ser removida
                remocaoNoCircularSimples(&lista, chave); // Remove o no da lista
                break;
            case 0: // Voltar
                lista = desalocaListaCircularSimples(&lista); // Desaloca a lista
                printf("\nRetornando ao menu de estruturas...\n");
                break;
            default: // Opcao invalida
                printf("\nOpcao invalida!\n");
                break;
        }
    } while (opcao != 0); // Enquanto o usuário não escolher a opção 0
}

void menuListaLinearDuplaComNoCabecaNaoOrdenada() {
    NoDuplo *lista = iniciaListaLinearDupla();
    NoDuplo *no_busca = NULL;
    unsigned int opcao;
    int chave;

    do {
        background(); // Limpa e coloca o background na tela
        gfxMostraListaLinearDupla(lista, XI_NO, XI_NO * 2, (YI_NO * 5)); // Mostra a lista
        gfx_paint(); // Aplica as mudanças na tela

        switch (opcao = escolhaMenuListas("Lista Linear Duplamente encadeada com no cabeca nao ordenada")) {
            case 1: // Busca
                chave = recebeChaveBusca(); // Recebe a chave a ser buscada
                no_busca = buscaNoLinearDuplo(lista, chave); // Busca o no com a chave
                break;
            case 2: // Insercao
                chave = recebeChaveInsercao(); // Recebe a chave a ser inserida
                insercaoNoLinearDuplo(lista, chave); // Insere o no na lista
                break;
            case 3: // Remocao
                chave = recebeChaveRemocao(); // Recebe a chave a ser removida
                remocaoNoLinearDuplo(&lista, chave); // Remove o no da lista

                if (no_busca == NULL) // Se não encontrar o no
                    printf("\nChave %d nao encontrada!\n", chave);
                else // Se encontrar o no
                    printf("\nChave %d encontrada!\n", no_busca->chave);

                no_busca = NULL; // Limpa o ponteiro de busca
                break;
            case 0: // Voltar
                lista = desalocaListaLinearDupla(&lista); // Desaloca a lista
                printf("\nRetornando ao menu de estruturas...\n");
                break;
            default: // Opcao invalida
                printf("\nOpcao invalida!\n");
                break;
        }
    } while (opcao != 0); // Enquanto o usuário não escolher a opção 0
}

void menuFila() {
    NoSimples *fila = iniciaFila(); // Inicia a fila
    unsigned int opcao;
    int chave;

    do {
        background(); // Limpa e coloca o background na tela
        gfxMostraFIFO(fila, XI_NO, XI_NO * 2, (YI_NO * 5)); // Mostra a fila
        gfx_paint(); // Aplica as mudanças na tela

        switch (opcao = escolhaMenuFilaEPilha("Fila")) {
            case 1: // Insercao
                chave = recebeChaveInsercao(); // Recebe a chave a ser inserida
                insercaoFIFO(&fila, chave); // Insere o no na fila
                break;
            case 2:
                remocaoFIFO(&fila); // Remove o no da fila
                break;
            case 0:
                fila = desalocaFila(&fila); // Desaloca a fila
                printf("\nRetornando ao menu de estruturas...\n");
                break;
            default: // Opcao invalida
                printf("\nOpcao invalida!\n");
                break;
        }

    } while (opcao != 0); // Enquanto o usuário não escolher a opção 0
}

void menuPilha() {
    NoSimples *pilha = iniciaPilha(); // Inicia a pilha
    unsigned int opcao;
    int chave;

    do {
        background(); // Limpa e coloca o background na tela
        gfxMostraLIFO(pilha, XI_NO, XI_NO * 2, (YI_NO * 5)); // Mostra a pilha
        gfx_paint(); // Aplica as mudanças na tela

        switch (opcao = escolhaMenuFilaEPilha("Pilha")) {
            case 1: // Insercao
                chave = recebeChaveInsercao(); // Recebe a chave a ser inserida
                insercaoLIFO(&pilha, chave); // Insere o no na pilha
                break;
            case 2: // Remocao
                remocaoLIFO(&pilha); // Remove o no da pilha
                break;
            case 0: // Voltar
                pilha = desalocaPilha(&pilha); // Desaloca a pilha
                printf("\nRetornando ao menu de estruturas...\n");
                break;
            default: // Opcao invalida
                printf("\nOpcao invalida!\n");
                break;
        }

    } while (opcao != 0); // Enquanto o usuário não escolher a opção 0
}

int main() {
    unsigned int opcao;

    gfx_init(WIDTH, HEIGHT, "ALOCACAO ENCADEADA"); // Inicia o gfx
    do {
        background(); // Limpa e coloca o background na tela
        gfx_paint(); // Aplica as mudanças na tela

        switch (opcao = escolhaMenuEstruturas()) {
            case 1:
                menuListaLinearSimplesSemNoCabecaOrdenada();
                break;
            case 2:
                menuListaCircularSimplesSemNoCabecaOrdenada();
                break;
            case 3:
                menuListaLinearDuplaComNoCabecaNaoOrdenada();
                break;
            case 4:
                menuFila();
                break;
            case 5:
                menuPilha();
                break;
            case 0:
                gfx_quit();
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
                break;
        }
    } while (opcao != 0);
}