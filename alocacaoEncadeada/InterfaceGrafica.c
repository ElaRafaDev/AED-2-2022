#include "InterfaceGrafica.h"
#include <stdio.h>
#include <stdlib.h>

void background() {
    gfx_clear(); // Limpa a tela
    gfx_set_color(40, 42, 54); // Define a cor do background
    gfx_filled_rectangle(0, 0, WIDTH, WIDTH); // Desenha o background
}

void desenhaSetaDireita(unsigned x1, unsigned y1, unsigned x2, unsigned y2, unsigned p_no) {
    gfx_set_color(248, 248, 242); // Define a cor da seta

    gfx_line(x1, y1 + p_no, x2, y2 + p_no); // Desenha linha horizontal
    gfx_line(x2 - 10, y2 + p_no - 4, x2, y2 + p_no); // Desenha linha inclinado superior
    gfx_line(x2 - 10, y2 + p_no + 4, x2, y2 + p_no); // Desenha linha inclinado inferior
}

void desenhaSetaEsquerda(unsigned x1, unsigned y1, unsigned x2, unsigned y2, unsigned p_no) {
    gfx_set_color(248, 248, 242); // Define a cor da seta

    gfx_line(x1, y1 + p_no, x2, y2 + p_no); // Desenha linha horizontal
    gfx_line(x2, y2 + p_no, x2 + 10, y2 + p_no - 4); // Desenha linha inclinado superior
    gfx_line(x2, y2 + p_no, x2 + 10, y2 + p_no + 4); // Desenha linha inclinado inferior
}

void desenhaSetaGrande(unsigned x1, unsigned y1, unsigned x2, unsigned y2, unsigned p_no1, unsigned p_no2, unsigned p_entre_nos) {
    gfx_set_color(248, 248, 242);

    gfx_line(x1, y1 + p_no1, x2 + p_no1, y1 + p_no1); // Desenha linha horizontal
    gfx_line(x2 + p_no1, y1 + p_no1, x2 + p_no1, y1 + p_entre_nos); // Desenha linha vertical
    gfx_line(x2 + p_no1, y1 + p_entre_nos, XI_NO - p_no2 - 10, y1 + p_entre_nos); // Desenha linha horizontal grande
    gfx_line(XI_NO - p_no2 - 10, y1 + p_entre_nos, XI_NO - p_no2 - 10, y2 + p_no2); // Desenha linha vertical
    gfx_line(XI_NO - p_no2 - 10, y2 + p_no2, XI_NO + p_no2 + 10, y2 + p_no2); // Desenha linha horizontal
}

void desenhaSetaCircular(unsigned x, unsigned y) {
    gfx_set_color(248, 248, 242); // Define a cor da seta

    gfx_line(x, y + YI_NO, x + 30, y + YI_NO); // Desenha linha horizontal
    gfx_line(x + 30, y + YI_NO, x + 30, y + YF_NO); // Desenha linha vertical
    gfx_line(x + 30, y + YF_NO, XI_NO - 40, y + YF_NO); // Desenha linha horizontal
    gfx_line(XI_NO - 40, y + YF_NO, XI_NO - 40, Y_METADE_NO + YI_NO_DE_BAIXO + 10); // Desenha linha vertical
}

void desenhaFigura(unsigned x1, unsigned y1, unsigned x2, unsigned y2) {
    gfx_set_color(98, 114, 164); // Define a cor do retangulo
    gfx_filled_rectangle(x1, y1 + 2, x2, y2 - 2); // Desenha o retangulo

    gfx_set_color(248, 248, 242); // Define a cor da borda do retangulo
    gfx_rectangle(x1, y1 + 2, x2, y2 - 2); // Desenha a borda do retangulo

    gfx_set_color(123, 104, 238); // Define a cor do quadrado
    gfx_filled_rectangle(x1 + 10, y1, x2 - 10, y2); // Desenha o quadrado

    gfx_set_color(248, 248, 242); // Define a cor da borda do quadrado
    gfx_rectangle(x1 + 10, y1, x2 - 10, y2); // Desenha a borda do quadrado
}

void desenhaNo(unsigned x1, unsigned y1, unsigned x2, unsigned y2, unsigned size, char *msg) {
    desenhaFigura(x1, y1, x2, y2); // Desenha a figura do no
    gfx_set_color(0, 0, 0); // Define a cor do texto
    gfx_set_font_size(size); // Define o tamanho do texto
    gfx_text((x1 + ((x2 - x1) / 2)) - (unsigned)(strlen(msg) * 5), y1 + 10, msg); // Desenha o texto alinhado no meio do no
}

void gfxMostraListaLinearSimples(NoSimples *no,unsigned x_inicial, unsigned x_final, unsigned y) {
    char str[64]; // String para armazenar o texto

    // Desenha o a figura que está escrito "LISTA"
    if (y == 100 && x_inicial == XI_NO) { // Se for o primeiro no da lista
        desenhaNo(METADE_WIDTH - 50, YI_NO, METADE_WIDTH + 50, YF_NO, 18, "LISTA"); // Desenha a figura do no

        // Desenha a seta grande que aponta para o primeiro no da lista
        desenhaSetaGrande(METADE_WIDTH - 50, YI_NO, METADE_WIDTH / 2, YI_NO_DE_BAIXO + 20, 20, 20, 60);
        desenhaSetaDireita(XI_NO - 30, YI_NO + YI_NO_DE_BAIXO, XI_NO, YI_NO + YI_NO_DE_BAIXO, 20);
    }
    if (no == NULL) { // Se não houver nenhum no na lista
        desenhaNo(x_inicial, y, x_final, y + 40, 16, "NULL"); // Desenha o no NULL
        return; // Sai da função
    }

    snprintf(str, 64, "%i", no->chave); // Armazena a chave do no na string str
    desenhaNo(x_inicial, y, x_final, y + 40, 18, str); // Desenha o no com a chave armazenada na string str

    if (x_final == XF_NO) { // Se for o ultimo no que cabe na tela de acordo com a largura da tela
        // Desenha a seta grande que aponta para o proximo no
        desenhaSetaGrande(x_final, y, x_final + 10, y + 80, 20, 20, 60);
        desenhaSetaDireita(XI_NO - 30, y + YI_NO_DE_BAIXO, XI_NO, y + YI_NO_DE_BAIXO, 20);

        gfxMostraListaLinearSimples(no->proximo, XI_NO, XI_NO * 2, y + (YI_NO * 4)); // Desenha o proximo no
    } else {
        desenhaSetaDireita(x_final, y, x_final + 30, y, 20); // Desenha a seta para o proximo no

        gfxMostraListaLinearSimples(no->proximo, x_inicial + 90, x_final + 90, y); // Desenha o proximo no
    }
}

void gfxMostraListaCircularSimples(NoSimples *no, NoSimples *inicio, unsigned x_inicial, unsigned x_final, unsigned y) {
    char str[64]; // String para armazenar o texto

    // Desenha o a figura que está escrito "LISTA"
    if (y == 100 && x_inicial == XI_NO) { // Se for o primeiro no da lista
        desenhaNo(METADE_WIDTH - 50, YI_NO, METADE_WIDTH + 50, YF_NO, 18, "LISTA"); // Desenha a figura do no

        if (no != NULL && no->proximo == NULL) { // Se o no atual for o ultimo no da lista
            // Desenha a seta grande que aponta para o primeiro no da lista um pouco acima do meio do no
            desenhaSetaGrande(METADE_WIDTH - 50, YI_NO, METADE_WIDTH / 2, YI_NO_DE_BAIXO + 10, 20, 20, 60);
            desenhaSetaDireita(XI_NO - 30, YI_NO + YI_NO_DE_BAIXO, XI_NO, YI_NO + YI_NO_DE_BAIXO, 10);
        } else { // Se a lista for vazia
            // Desenha a seta grande que aponta para o primeiro no NULL da lista
            desenhaSetaGrande(METADE_WIDTH - 50, YI_NO, METADE_WIDTH / 2, YI_NO_DE_BAIXO + 20, 20, 20, 60);
            desenhaSetaDireita(XI_NO - 30, YI_NO + YI_NO_DE_BAIXO, XI_NO, YI_NO + YI_NO_DE_BAIXO, 20);
        }

    }
    if (no == NULL) {
        desenhaNo(x_inicial, y, x_final, y + 40, 16, "NULL"); // Desenha o no NULL
        return; // Sai da função
    }

    snprintf(str, 64, "%i", no->chave); // Armazena a chave do no na string str
    desenhaNo(x_inicial, y, x_final, y + 40, 18, str); // Desenha o no com a chave armazenada na string str

    if (no->proximo == inicio) { // Se o proximo no for o inicio no da lista
        // Desenha a seta circular que aponta para o primeiro no da lista
        desenhaSetaCircular(x_final, y);
        desenhaSetaDireita(XI_NO - 40, YI_NO + YI_NO_DE_BAIXO, XI_NO, YI_NO + YI_NO_DE_BAIXO, 30);
    } else if (x_final == XF_NO) { // Se for o ultimo no que cabe na tela de acordo com a largura da tela
        // Desenha a seta grande que aponta para o proximo no
        desenhaSetaGrande(x_final, y, x_final + 10, y + 90, 20, 10, 60);
        desenhaSetaDireita(XI_NO - 10, y + YI_NO_DE_BAIXO, XI_NO, y + YI_NO_DE_BAIXO, 20);

        gfxMostraListaCircularSimples(no->proximo, inicio, XI_NO, XI_NO * 2, y + (YI_NO * 4)); // Desenha o proximo no
    } else {
        desenhaSetaDireita(x_final, y, x_final + 30, y, 20); // Desenha a seta para o proximo no

        gfxMostraListaCircularSimples(no->proximo, inicio, x_inicial + 90, x_final + 90, y); // Desenha o proximo no
    }
}

void gfxMostraListaLinearDupla(NoDuplo *no, unsigned x_inicial, unsigned x_final, unsigned y) {
    char str[64]; // String para armazenar o texto

    // Desenha o a figura que está escrito "LISTA"
    if (y == 100 && x_inicial == XI_NO) { // Se for o primeiro no da lista
        desenhaNo(METADE_WIDTH - 50, YI_NO, METADE_WIDTH + 50, YF_NO, 18, "LISTA"); // Desenha a figura do no

        // Desenha a seta grande que aponta para o primeiro no da lista
        desenhaSetaGrande(METADE_WIDTH - 50, YI_NO, METADE_WIDTH / 2, YI_NO_DE_BAIXO + 20, 20, 20, 60);
        desenhaSetaDireita(XI_NO - 30, YI_NO + YI_NO_DE_BAIXO, XI_NO, YI_NO + YI_NO_DE_BAIXO, 20);
    }
    if (no == NULL) { // Se o no for NULL
        desenhaNo(x_inicial, y, x_final, y + 40, 16, "NULL"); // Desenha o no NULL
        return; // Sai da função
    }

    if (no->anterior == NULL) // Se o no anterior for NULL
        desenhaNo(x_inicial, y, x_final, y + 40, 18, "NO"); // Desenha o no cabeca
    else { // Se o no anterior não for NULL
        snprintf(str, 64, "%i", no->chave); // Armazena a chave do no na string str
        desenhaNo(x_inicial, y, x_final, y + 40, 18, str); // Desenha o no com a chave armazenada na string str
    }

    if (x_final == XF_NO) { // Se for o ultimo no que cabe na tela de acordo com a largura da tela
        if (no->proximo != NULL) { // Se o proximo no não for NULL
            // Desenha a seta grande que aponta para o proximo no
            desenhaSetaGrande(x_final, y, x_final - 10, y + 80, 30, 30, 50);
            desenhaSetaDireita(XI_NO - 30, y + YI_NO_DE_BAIXO, XI_NO, y + YI_NO_DE_BAIXO, 30);

            // Desenha a seta grande que aponta para o no anterior
            desenhaSetaGrande(x_final, y, x_final + 30, y + 80, 10, 10, 70);
            desenhaSetaEsquerda(x_final + 30, y, x_final, y, 10);
        } else { // Se o proximo no for NULL
            // Desenha a seta grande que aponta para o proximo no
            desenhaSetaGrande(x_final, y, x_final + 10, y + 80, 20, 20, 60);
            desenhaSetaDireita(XI_NO - 30, y + YI_NO_DE_BAIXO, XI_NO, y + YI_NO_DE_BAIXO, 20);
        }

        gfxMostraListaLinearDupla(no->proximo, XI_NO, XI_NO * 2, y + (YI_NO * 4)); // Desenha o proximo no
    } else { // Se não for o ultimo no que cabe na tela de acordo com a largura da tela
        if (no->proximo != NULL) { // Se o proximo no não for NULL
            desenhaSetaDireita(x_final, y, x_final + 30, y, 30); // Desenha a seta para o proximo no
            desenhaSetaEsquerda(x_final + 30, y, x_final, y, 10); // Desenha a seta para o no anterior
        } else // Se o proximo no for NULL
            desenhaSetaDireita(x_final, y, x_final + 30, y, 20); // Desenha a seta para o proximo no

        gfxMostraListaLinearDupla(no->proximo, x_inicial + 90, x_final + 90, y); // Desenha o proximo no
    }
}

void gfxMostraFIFO(NoSimples *no, unsigned x_inicial, unsigned x_final, unsigned y) {
    char str[64]; // String para armazenar o texto

    // Desenha o a figura que está escrito "FILA"
    if (y == 100 && x_inicial == XI_NO) { // Se for o primeiro no da lista
        desenhaNo(METADE_WIDTH - 50, YI_NO, METADE_WIDTH + 50, YF_NO, 18, "FILA"); // Desenha a figura do no

        // Desenha a seta grande que aponta para o primeiro no da fila
        desenhaSetaGrande(METADE_WIDTH - 50, YI_NO, METADE_WIDTH / 2, YI_NO_DE_BAIXO + 20, 20, 20, 60);
        desenhaSetaDireita(XI_NO - 30, YI_NO + YI_NO_DE_BAIXO, XI_NO, YI_NO + YI_NO_DE_BAIXO, 20);
    }
    if (no == NULL) { // Se o no for NULL
        desenhaNo(x_inicial, y, x_final, y + 40, 16, "NULL"); // Desenha o no NULL
        return; // Sai da função
    }

    snprintf(str, 64, "%i", no->chave); // Armazena a chave do no na string str
    desenhaNo(x_inicial, y, x_final, y + 40, 18, str); // Desenha o no com a chave armazenada na string str

    if (x_final == XF_NO) { // Se for o ultimo no que cabe na tela de acordo com a largura da tela
        // Desenha a seta grande que aponta para o proximo no
        desenhaSetaGrande(x_final, y, x_final + 10, y + 80, 20, 20, 60);
        desenhaSetaDireita(XI_NO - 30, y + YI_NO_DE_BAIXO, XI_NO, y + YI_NO_DE_BAIXO, 20);

        gfxMostraFIFO(no->proximo, XI_NO, XI_NO * 2, y + (YI_NO * 4)); // Desenha o proximo no
    } else { // Se não for o ultimo no que cabe na tela de acordo com a largura da tela
        desenhaSetaDireita(x_final, y, x_final + 30, y, 20); // Desenha a seta para o proximo no

        gfxMostraFIFO(no->proximo, x_inicial + 90, x_final + 90, y); // Desenha o proximo no
    }
}

void gfxMostraLIFO(NoSimples *no, unsigned x_inicial, unsigned x_final, unsigned y) {
    char str[64]; // String para armazenar o texto

    // Desenha o a figura que está escrito "PILHA"
    if (y == 100 && x_inicial == XI_NO) { // Se for o primeiro no da lista
        desenhaNo(METADE_WIDTH - 50, YI_NO, METADE_WIDTH + 50, YF_NO, 18, "PILHA"); // Desenha a figura do no

        // Desenha a seta grande que aponta para o primeiro no da pilha
        desenhaSetaGrande(METADE_WIDTH - 50, YI_NO, METADE_WIDTH / 2, YI_NO_DE_BAIXO + 20, 20, 20, 60);
        desenhaSetaDireita(XI_NO - 30, YI_NO + YI_NO_DE_BAIXO, XI_NO, YI_NO + YI_NO_DE_BAIXO, 20);
    }
    if (no == NULL) { // Se o no for NULL
        desenhaNo(x_inicial, y, x_final, y + 40, 16, "NULL"); // Desenha o no NULL
        return; // Sai da função
    }

    snprintf(str, 64, "%i", no->chave); // Armazena a chave do no na string str
    desenhaNo(x_inicial, y, x_final, y + 40, 18, str); // Desenha o no com a chave armazenada na string str

    if (x_final == XF_NO) { // Se for o ultimo no que cabe na tela de acordo com a largura da tela
        // Desenha a seta grande que aponta para o proximo no
        desenhaSetaGrande(x_final, y, x_final + 10, y + 80, 20, 20, 60);
        desenhaSetaDireita(XI_NO - 30, y + YI_NO_DE_BAIXO, XI_NO, y + YI_NO_DE_BAIXO, 20);

        gfxMostraLIFO(no->proximo, XI_NO, XI_NO * 2, y + (YI_NO * 4)); // Desenha o proximo no
    } else {
        desenhaSetaDireita(x_final, y, x_final + 30, y, 20); // Desenha a seta para o proximo no

        gfxMostraLIFO(no->proximo, x_inicial + 90, x_final + 90, y); // Desenha o proximo no
    }
}