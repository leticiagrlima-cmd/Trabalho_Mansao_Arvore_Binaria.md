Tetris Stack — Sistema de Fila de Peças (Estrutura de Dados em C)

Este projeto implementa a fila de peças futuras do jogo fictício Tetris Stack, desenvolvido como parte de um desafio acadêmico.
A aplicação utiliza uma fila circular para organizar peças do jogo e permitir operações de inserção e remoção, simulando o comportamento real de jogos de Tetris modernos.

*Objetivo do Projeto

Criar um programa em C que:

Inicializa uma fila circular com 5 peças.

Permite ao jogador:

Jogar peça (dequeue).

Adicionar nova peça (enqueue).

Exibir a fila de peças automaticamente após cada ação.

Utiliza structs, funções, modularização, entrada e saída, e controle de fluxo.

*Estrutura da Peça

Cada peça é representada por um struct contendo:

nome: caractere indicando o tipo da peça (I, O, T, L)

id: número inteiro único gerado automaticamente

Exemplo de peça:

[T 3]

*Fila Circular

A fila foi implementada utilizando:

Array estático com tamanho fixo (MAX_FILA = 5)

Variáveis de controle:

inicio

fim

tamanho

Essa técnica permite reaproveitar posições já liberadas pela remoção de elementos, sem necessidade de deslocamento de memória.

*Funcionalidades
✔ Jogar peça

Remove a peça da frente da fila (dequeue).

✔ Inserir nova peça

Adiciona uma peça automaticamente gerada ao final da fila (enqueue).

✔ Visualização automática

Após cada operação, o programa exibe a fila neste formato:

[I 0] [O 1] [L 2] [T 3] [I 4]

*Estrutura do Código

Funções implementadas:

gerarPeca() → cria peças aleatórias com ID único

enqueue() → insere peças ao final da fila

dequeue() → remove a peça do início da fila

exibirFila() → imprime o estado atual da fila

main() → controla o fluxo do menu e inicializa o programa

*Como Compilar

No terminal, execute:

gcc tetris_stack.c -o tetris


Para rodar:

./tetris

*Menu do Programa

O jogador pode escolher:

1 - Jogar peça (dequeue)
2 - Inserir nova peça (enqueue)
0 - Sair


O estado da fila é mostrado automaticamente após cada operação.

*Exemplo de Execução
==============================
      Fila de Peças
==============================
[I 0] [T 1] [O 2] [L 3] [I 4]

Opções:
1 - Jogar peça (dequeue)
2 - Inserir nova peça (enqueue)
0 - Sair
Escolha: 1

Peça jogada: [I 0]

*Conceitos Aplicados

Estruturas de dados (fila circular)

Structs em C

Modularização de código

Entrada e saída pelo terminal

Controle com condicionais e loops

Geração automática de dados

*Desenvolvido Para

Atividade de implementação de estrutura de dados do jogo Tetris Stack, conforme orientações educacionais.

*Licença

Este projeto é de uso acadêmico e educativo.
