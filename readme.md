<h1 align="center"> SpaceJam </h1>

[comment]: <> (Adicione o seu usuário  e o nome do repositório)

<p align="center">
  <image
  src="https://img.shields.io/github/languages/count/ojonatasquirino/[nome-do-repositorio]"
  />
  <image
  src="https://img.shields.io/github/languages/top/ojonatasquirino/[nome-do-repositorio]"
  />
  <image
  src="https://img.shields.io/github/last-commit/ojonatasquirino/[nome-do-repositorio]"
  />

</p>

# sumário 

- [objetivos](#id01)
- [descrição detalhada](#id01.01)
- [tecnologias utilizadas](#id02)
- [ambiente de codificação](#id03)
- [clonagem e instalação](#id04)
- [deploy e implatação](#id05)
- [responsividade](#id06)
- [autoria](#id07)



# objetivos <a name="id01"></a>

<div  align='center'> 
  
O objetivo principal deste projeto é desenvolver um jogo chamado Space Jam utilizando a linguagem de programação C e a biblioteca Allegro. Este projeto foi criado como parte de uma atividade acadêmica para a disciplina de Programação em C. Os objetivos específicos incluem:

Aplicar conceitos de programação em C aprendidos em sala de aula.
Desenvolver habilidades na utilização da biblioteca Allegro para manipulação gráfica e controle de eventos.
Criar um jogo funcional que inclui um menu inicial, múltiplas fases e lógica de colisão.
Objetivos de Aprendizado
Os objetivos de aprendizado deste projeto são:

Manipulação de Gráficos: Aprender a carregar, desenhar e manipular bitmaps utilizando a biblioteca Allegro.
Controle de Eventos: Gerenciar entradas do teclado para controlar a nave dentro do jogo.
Lógica de Jogo: Implementar a lógica de movimento da nave, incluindo efeitos de gravidade e colisão.
Estruturação de Código: Organizar o código de forma modular, com funções específicas para inicialização, movimentação, colisão e gerenciamento de fases.
Desenvolvimento de Jogos: Entender os princípios básicos do desenvolvimento de jogos, incluindo design de fases e desafios de jogo.

</div>


# descrição detalhada <a name="id01.01"></a>

<div  align='center'> 
  Space Jam é um jogo de nave bidimensional onde o jogador controla uma espaçonave com o objetivo de pousar em locais específicos sem colidir com obstáculos. O jogo foi desenvolvido em C utilizando a biblioteca Allegro para a manipulação gráfica e controle de eventos. A seguir, uma descrição detalhada dos componentes e funcionalidades do jogo:

Componentes do Jogo
Menu Inicial:

Exibe o título do jogo e opções de menu.
O jogador pode navegar pelas opções usando as setas do teclado e selecionar uma opção pressionando a tecla Enter.
Opções disponíveis: Iniciar Jogo, Créditos e Sair.
Controle da Nave:

A nave pode ser movida para cima, para a esquerda e para a direita usando as teclas do teclado.
A nave é constantemente afetada pela gravidade, exigindo que o jogador mantenha a nave em movimento ativo para evitar colisões.
Fases do Jogo:

O jogo possui duas fases com diferentes desafios.
Na primeira fase, o jogador deve pousar a nave no local correto evitando obstáculos estáticos.
Na segunda fase, a dificuldade aumenta com mais obstáculos e padrões de movimento mais complexos.
Lógica de Colisão:

A lógica de colisão é implementada para detectar quando a nave colide com obstáculos ou ultrapassa os limites do campo de jogo.
Se uma colisão for detectada, uma mensagem de "Game Over" é exibida e o jogo termina.
Mensagens e Feedback:

Mensagens de "Parabéns" são exibidas quando o jogador completa uma fase.
Mensagem de "Game Over" é exibida quando o jogador falha em evitar colisões.
Funcionalidades do Código
Inicialização e Finalização:

A função init() inicializa a biblioteca Allegro e configura o modo gráfico.
A função deinit() finaliza a biblioteca Allegro e limpa o buffer de teclas.
Movimento da Nave:

A função fMovimento() controla a movimentação da nave, aplicando gravidade quando a tecla de subida não está pressionada.
Scroll do Background:

A função fScrool_Background() movimenta o fundo da tela para criar a ilusão de movimento.
Gerenciamento de Fases:

As funções fFase1() e fFase2() gerenciam as respectivas fases do jogo, incluindo o controle de obstáculos e detecção de colisões.
Teste de Colisões:

A função fTesta_Colisao() verifica se a nave colidiu com algum obstáculo ou ultrapassou os limites do campo de jogo.
Game Over:

A função fGame_Over() exibe a mensagem de "Game Over" e encerra o jogo quando uma colisão é detectada.
Este projeto não apenas oferece uma experiência prática com programação em C e utilização da biblioteca Allegro, mas também desenvolve habilidades de resolução de problemas e lógica de programação aplicadas em um contexto de desenvolvimento de jogos.
</div>


# tecnologias utilizadas <a name="id02"></a>

<div  align='center'> 

 <a href='https://dev.to/envoy_/150-badges-for-github-pnk'>  link para adicionar badges </a> 


</div>

# ambiente de codificação <a name="id03"></a>

<div  align='center'> 

![](https://img.shields.io/badge/VSCode-0D1117?style=for-the-badge&logo=visual%20studio%20code&logoColor=blue)
![node](https://img.shields.io/badge/Nodejs-0D1117?style=for-the-badge&logo=node.js&logoColor=green)
![git](https://img.shields.io/badge/GIT-0D1117?style=for-the-badge&logo=git&logoColor=red)
![github](https://img.shields.io/badge/Github-0D1117?style=for-the-badge&logo=github&logoColor=fff)
</div>


# clonagem e instalação <a name="id04"></a>

Clone este repositório usando o comando:

```bash
git clone https://github.com/usuario/repositorio.git
```

Instale na pasta do projeto as dependências com uso do npm ou yarn:

```bash
adicione aqui os prcocessos adicionais e dependências 
```
[comment]: <> (Adicione o link da implatação, se houver)

# deploy e implatação  <a name="id05"></a>

[comment]: <> (Adicione o link da implatação)

# responsividade  <a name="id06"></a>

## mobile 

[comment]: <> (adicione a imagem)

## tablet

[comment]: <> (adicione a imagem)

## desktop 

[comment]: <> (adicione a imagem)

# autoria <a name="id07"></a>

[comment]: <> (Adicione seu nome e função)

<h3 align='center'> @ojonatasquirino • desenvolvedor front-end
 </h3>

#

<div  align='center'>

[![Linkedin](https://img.shields.io/badge/LinkedIn-0D1117?style=for-the-badge&logo=linkedin&logoColor=blue)](https://www.linkedin.com/in/jonatasquirino/)
<a href = "mailto:quirinoj02@gmail.com">
![Gmail](https://img.shields.io/badge/Gmail-0D1117?style=for-the-badge&logo=gmail&logoColor=red)</a>
[![TabNews](https://img.shields.io/badge/tabnews-0D1117?style=for-the-badge&logo=Databricks&logoColor=fff)](https://www.tabnews.com.br/ojonatasquirino) [![github](https://img.shields.io/badge/Github-0D1117?style=for-the-badge&logo=github&logoColor=fff)](https://www.github.com/ojonatasquirino)
</div>
