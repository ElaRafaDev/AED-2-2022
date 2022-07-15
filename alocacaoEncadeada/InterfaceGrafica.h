#ifndef ALOCACAOENCADEADA_INTERFACEGRAFICA_H
#define ALOCACAOENCADEADA_INTERFACEGRAFICA_H

#include "gfx/gfx.h"
#include "No.h"
#include "LLinearSimples.h"
#include "LCircularSimples.h"
#include "LLinearDupla.h"
#include "FIFO.h"
#include "LIFO.h"

#define WIDTH 900 // largura da tela
#define HEIGHT 640 // altura da tela

#define XI_NO 60 // posicao x final do primeiro no
#define XF_NO WIDTH - 60 // posicao x final do ultimo no
#define YI_NO 20 // posicao y inicial do no
#define YF_NO YI_NO * 3 // posicao y final do no
#define YI_NO_DE_BAIXO YF_NO + 20 // posicao y inicial do no de baixo

#define METADE_WIDTH (WIDTH / 2) // metade da largura da tela
#define Y_METADE_NO YI_NO * 2 // metade da altura do no

void background(); // Desenha o background
// Desenha a seta para a direita
void desenhaSetaDireita(unsigned x1, unsigned y1, unsigned x2, unsigned y2, unsigned p_no);
// Desenha a seta para a esquerda
void desenhaSetaEsquerda(unsigned x1, unsigned y1, unsigned x2, unsigned y2, unsigned p_no);
// Desenha a seta circular
void desenhaSetaCircular(unsigned x, unsigned y);
// Desenha a seta grande
void desenhaSetaGrande(unsigned x1, unsigned y1, unsigned x2, unsigned y2, unsigned p_no1, unsigned p_no2, unsigned p_entre_nos);
// Desenha a figura usada para representar o no
void desenhaFigura(unsigned x1, unsigned y1, unsigned x2, unsigned y2);
// Desenha o no
void desenhaNo(unsigned x1, unsigned y1, unsigned x2, unsigned y2, unsigned size, char *msg);
// Mostra a lista linear simples
void gfxMostraListaLinearSimples(NoSimples *no,unsigned x_inicial, unsigned x_final, unsigned y);
// Mostra a lista circular simples
void gfxMostraListaCircularSimples(NoSimples *no, NoSimples *inicio, unsigned x_inicial, unsigned x_final, unsigned y);
// Mostra a lista linear dupla
void gfxMostraListaLinearDupla(NoDuplo *no,unsigned x_inicial, unsigned x_final, unsigned y);
// Mostra a fila FIFO
void gfxMostraFIFO(NoSimples *no, unsigned x_inicial, unsigned x_final, unsigned y);
// Mostra a fila LIFO
void gfxMostraLIFO(NoSimples *no, unsigned x_inicial, unsigned x_final, unsigned y);

#endif //ALOCACAOENCADEADA_INTERFACEGRAFICA_H
