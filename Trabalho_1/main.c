#include <stdio.h>
#include <unistd.h>
#include "gfx.h"

#define WIDTH 700
#define HEIGHT 700

#define ERRO_OPCAO printf("\nOpcao invalida!\nTente novamente.\n\n")

#define FIGURA_TRIANGULO printf("\nFigura escolhida: Triangulo de Sierpinski\n")
#define FIGURA_QUADRADO printf("\nFigura escolhida: Quadrados sobrepostos\n")

#define LIMPAR_TELA system("clear")
#define PAUSAR_TELA system("read -p \"Pressione qualquer tecla para continuar . . .\" saindo")

/*Protótipos das funções e procedimentos*/
unsigned int interface();
unsigned int interface_altura(unsigned int tipo_figura);
unsigned int interface_recursao(unsigned int tipo_figura);
void printa_tipo_figura(unsigned int tipo_figura);
void mostra_quadrados_sobrepostos(unsigned int altura, unsigned int nivel_recursao);
void quadrados_sobrepostos(unsigned int altura, int x, int y, unsigned int nivel_recursao, unsigned int flag_recursao);
void quadrado(unsigned int altura, int x, int y);
void mostra_triangulo_sierpinski(unsigned int altura, unsigned int nivel_recursao);
void triangulo_de_sierpinski(unsigned int altura, int x, int y, unsigned int nivel_recursao, unsigned int flag_recursao);
void triangulo(unsigned int altura, int x, int y);

/*
Procedimento que monta os triângulos. OBS: Triângulos invertidos
unsigned int altura: altura da figura
int x: ponto x
int y: ponto y
*/
void triangulo(unsigned int altura, int x, int y)
{
    gfx_set_color(255, 255, 255); /*Cor branca*/

    gfx_line(x / 2, y / 2 + (altura), (x / 2) - (altura / 2), y / 2);       /*Lado direito*/
    gfx_line(x / 2, y / 2 + (altura), (x / 2) + (altura / 2), y / 2);       /*Lado esquerdo*/
    gfx_line((x / 2) + (altura / 2), y / 2, (x / 2) - (altura / 2), y / 2); /*Base*/
}

/*
Procedimento de recursividade que desenha o Triângulo Sierpinski
unsigned int altura: altura da figura
int x: ponto x
int y: ponto y
unsigned int nivel_recursao: nivel de recursao
unsigned int flag_recursao: condicao de parada da recursao
*/
void triangulo_de_sierpinski(unsigned int altura, int x, int y, unsigned int nivel_recursao, unsigned int flag_recursao)
{
    triangulo(altura, x, y); /*Desenha um triangulo*/

    if (nivel_recursao >= flag_recursao)
    {
        triangulo_de_sierpinski((altura / 2), x - altura, y + altura, nivel_recursao, flag_recursao + 1); /*Desenha triangulos para o lado esquerdo*/
        triangulo_de_sierpinski((altura / 2), x + altura, y + altura, nivel_recursao, flag_recursao + 1); /*Desenha triangulos para o lado direito*/
        triangulo_de_sierpinski((altura / 2), x, y - altura, nivel_recursao, flag_recursao + 1);          /*Desenha triangulos para cima*/
    }
}

/*
Procedimento usado para inicir a tela e desenhar o Triângulo de Sierpinski
unsigned int altura: altura da figura
unsigned int nivel_recursao: nivel de recursao
*/
void mostra_triangulo_sierpinski(unsigned int altura, unsigned int nivel_recursao)
{
    gfx_init(WIDTH, HEIGHT, "Triangulo de Sierpinski");

    triangulo_de_sierpinski(altura / 2, WIDTH, HEIGHT, nivel_recursao, 1);
    gfx_paint();

    sleep(10);

    gfx_quit();
}

/*
Procedimeto que monta os quadrados. OBS: Um preenchido da cor preta e um transparente com as vértices brancas
unsigned int altura: altura da figura
int x: ponto x
int y: ponto y
*/
void quadrado(unsigned int altura, int x, int y)
{
    gfx_set_color(0, 0, 0); /*Cor preta*/
    gfx_filled_rectangle((x / 2) - (altura / 2), (y / 2) + (altura / 2), (x / 2) + (altura / 2), (y / 2) - (altura / 2));

    gfx_set_color(255, 255, 255); /*Cor branca*/
    gfx_rectangle((x / 2) + (altura / 2), (y / 2) - (altura / 2), (x / 2) - (altura / 2), (y / 2) + (altura / 2));
}

/*
Procedimento de recursividade que desenha os quadrados sobrepostos
unsigned int altura: altura da figura
int x: ponto x
int y: ponto y
unsigned int nivel_recursao: nivel de recursao
unsigned int flag_recursao: condicao de parada da recursao
*/
void quadrados_sobrepostos(unsigned int altura, int x, int y, unsigned int nivel_recursao, unsigned int flag_recursao)
{
    if (nivel_recursao >= flag_recursao)
    {
        quadrados_sobrepostos((altura / 2), x - altura, y - altura, nivel_recursao, flag_recursao + 1); /*Desenha quadrados no canto superior esquerdo*/
        quadrados_sobrepostos((altura / 2), x + altura, y - altura, nivel_recursao, flag_recursao + 1); /*Desenha quadrados no canto superior direito*/
        quadrados_sobrepostos((altura / 2), x - altura, y + altura, nivel_recursao, flag_recursao + 1); /*Desenha quadrados no canto inferior esquerdo*/
        quadrados_sobrepostos((altura / 2), x + altura, y + altura, nivel_recursao, flag_recursao + 1); /*Desenha quadrados no canto inferior direito*/
    }

    quadrado(altura, x, y); /*Desenha um quadrado*/
}

/*
Procedimento usado para iniciar a tela e desenhar os Quadrados sobrepostos
unsigned int altura: altura da figura
unsigned int nivel_recursao: nivel de recursao
*/
void mostra_quadrados_sobrepostos(unsigned int altura, unsigned int nivel_recursao)
{
    gfx_init(WIDTH, HEIGHT, "Quadrados Sobrepostos");

    quadrados_sobrepostos(altura / 2, WIDTH, HEIGHT, nivel_recursao, 1);
    gfx_paint();

    sleep(10);

    gfx_quit();
}

/*Procedimento usado apenas para printar o tipo da figura escolhida pelo o usuário*/
void printa_tipo_figura(unsigned int tipo_figura)
{
    if (tipo_figura == 1)
        FIGURA_TRIANGULO;
    else if (tipo_figura == 2)
        FIGURA_QUADRADO;
}

/*Função usada para determinar um nível de recursão informado pelo usuário*/
unsigned int interface_recursao(unsigned int tipo_figura)
{
    unsigned int nivel_recursao;

    LIMPAR_TELA;
    printa_tipo_figura(tipo_figura);
    printf("\nInforme o nivel de recursao: ");
    scanf("%u", &nivel_recursao);

    return nivel_recursao;
}

/*Função usada para determinar uma altura informada pelo usuário*/
unsigned int interface_altura(unsigned int tipo_figura)
{
    unsigned int altura = 0;

    LIMPAR_TELA;
    printa_tipo_figura(tipo_figura);
    printf("\nInforme a altura do desenho: ");
    scanf("%u", &altura);

    if (altura > (WIDTH + HEIGHT / 2))
    {
        printf("\nAtencao!\nA figura vai ficar maior que a tela!\n\n.");
        PAUSAR_TELA;
    }

    return altura;
}

/*Função usada para determinar uma figura informada pelo usuário*/
unsigned int interface()
{
    unsigned int escolha = 0;

    do
    {
        LIMPAR_TELA;
        printf("\nEscolha uma opcao:\n\n0 - Sair\n1 - Triângulo de Sierpinski\n2 - Quadrados sobrepostos\nOpcao: ");
        scanf("%u", &escolha);

        switch (escolha)
        {
        case 0:
            printf("\nFinalizando!!\n\n");
            PAUSAR_TELA;
            exit(EXIT_SUCCESS);
            break;
        case 1:
            return escolha;
            break;
        case 2:
            return escolha;
            break;
        default:
            ERRO_OPCAO;
            PAUSAR_TELA;
            break;
        }
    } while (escolha != 0);

    return escolha;
}

int main()
{
    unsigned int escolha_interface = 0, altura = 0, nivel_recursao = 0;

    do
    {
        escolha_interface = interface();
        altura = interface_altura(escolha_interface);
        nivel_recursao = interface_recursao(escolha_interface);

        if (escolha_interface == 1)
            mostra_triangulo_sierpinski(altura, nivel_recursao);
        else if (escolha_interface == 2)
            mostra_quadrados_sobrepostos(altura, nivel_recursao);
    } while (escolha_interface != 0);

    return 0;
}