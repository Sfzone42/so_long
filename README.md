
# so_long

**so_long** é um projeto desenvolvido como parte do currículo da 42. O objetivo deste projeto é criar um jogo 2D simples usando a biblioteca gráfica `mlx` (MiniLibX). O jogo envolve um personagem que deve percorrer um mapa coletando todos os itens e chegando à saída para vencer.

## 📋 Índice

- [Visão Geral](#visão-geral)
- [Instalação](#instalação)
- [Uso](#uso)
- [Regras do Jogo](#regras-do-jogo)
- [Controles](#controles)
- [Recursos](#recursos)
- [Contribuições](#contribuições)
- [Licença](#licença)
- [Contato](#contato)

## 🌟 Visão Geral

Neste jogo, você controla um personagem que se move em um labirinto. O objetivo é coletar todos os itens e alcançar a saída. Se você conseguir coletar todos os itens e chegar à saída, você vence o jogo. Caso contrário, o jogo continua até que você consiga alcançar a saída após coletar todos os itens ou fique preso.

## 🚀 Instalação

### Pré-requisitos

- **gcc** (ou outro compilador C)
- **make**
- **MiniLibX** (mlx)
- **X11** (para sistemas baseados em Unix)
- **Xpm** (para manipulação de imagens XPM)

### Passos de Instalação

1. Clone o repositório:
    ```bash
    git clone https://github.com/usuario/so_long.git
    cd so_long
    ```

2. Compile o projeto:
    ```bash
    make
    ```

3. Execute o jogo:
    ```bash
    ./so_long mapas/mapa.ber
    ```

## 🎮 Uso

Para jogar, basta executar o comando acima, especificando o caminho para um arquivo de mapa `.ber`. O mapa deve estar em conformidade com as regras especificadas no projeto.

## 🕹️ Regras do Jogo

- O mapa deve ser delimitado por paredes.
- O jogador (representado por 'P') deve coletar todos os itens (representados por 'C') antes de chegar à saída (representada por 'E').
- O jogo termina quando o jogador coleta todos os itens e alcança a saída.

## ⌨️ Controles

- **W**: Mover para cima
- **A**: Mover para a esquerda
- **S**: Mover para baixo
- **D**: Mover para a direita
- **ESC**: Sair do jogo

## 🛠️ Recursos

- **Movimento**: O personagem pode se mover em quatro direções (cima, baixo, esquerda, direita).
- **Coleção de Itens**: O jogador deve coletar todos os itens antes de chegar à saída.
- **Contagem de Movimentos**: O jogo exibe a quantidade de movimentos realizados pelo jogador.

## 📄 Licença

Este projeto está licenciado sob a Licença MIT - veja o arquivo [LICENSE](LICENSE) para detalhes.

## 📞 Contato

- **GitHub**: [SFzone42](https://github.com/Sfzone42)
- **Email**: liedsonnhabacuc@gmail.com

---
