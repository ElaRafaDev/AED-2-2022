# AED-2-2022
Trabalhos referentes à matéria de Algoritmos e Estrutura de Dados 2

Biblioteca **"gfx"** criada pelo **Fabrício Sérgio de Paula (fabricio.paula@gmail.com)**

0) Caso não tenha gcc instalado, instale o gcc e o make através do seguinte comando:
```
$ sudo apt-get install gcc make
```

1) Instalar as bibliotecas básicas da SDL que são usadas pela gfx. As bibliotecas que você precisa instalar nesse passo são as seis seguintes:
```
libsdl1.2debian e libsdl1.2-dev
libsdl-ttf2.0-0 e libsdl-ttf2.0-dev
libsdl-gfx1.2 e libsdl-gfx1.2-dev
```

Para instalar essas bibliotecas, digite o seguinte comando: 
```
$ sudo apt-get install libsdl1.2debian libsdl1.2-dev libsdl-ttf2.0-0 libsdl-ttf2.0-dev libsdl-gfx1.2 libsdl-gfx1.2-dev
```

Entre no diretório gfx e digite o comando ```make clean``` e depois ```make```. Não pode ocorrer erro. Depois disso, volte para o diretório onde se encontra o programa main.c e digite novamente ```make clean``` e depois ```make```
