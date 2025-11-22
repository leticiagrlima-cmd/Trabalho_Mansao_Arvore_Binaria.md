# Projeto: Exploração de Mansão Usando Árvore Binária em C

## Disciplina: Estrutura de Dados  
## Estudante: *Preencher com seu nome*  
## Professor: *Preencher*  

---

## 1. Introdução

Este trabalho apresenta a implementação de uma **árvore binária** para representar a planta de uma mansão, permitindo que o usuário explore seus cômodos de maneira interativa a partir do Hall de Entrada.  
O programa foi desenvolvido em linguagem **C**, utilizando conceitos fundamentais de estruturas de dados, como alocação dinâmica, structs, modularização e árvore binária.

---

## 2. Objetivos

### Objetivos Funcionais
- Criar automaticamente a árvore binária que representa os cômodos da mansão.
- Permitir navegação interativa do jogador, utilizando os comandos:
  - `e` – Ir para a esquerda  
  - `d` – Ir para a direita  
  - `s` – Sair da exploração
- Exibir todos os cômodos visitados.
- Encerrar exploração quando o jogador chegar a um nó-folha.

### Objetivos Não Funcionais
- Código claro e bem identado.
- Interação simples e objetiva com o usuário.
- Comentários detalhando as funções do programa.

---

## 3. Estrutura da Árvore

A mansão é representada como uma árvore binária, onde cada sala possui:
- Nome do cômodo
- Ponteiro para sala à esquerda
- Ponteiro para sala à direita

Árvore utilizada:

```
                  Hall de Entrada
                 /               \
        Sala de Estar           Corredor
        /           \          /        \
   Cozinha      Biblioteca   Quarto     Jardim
```

---

## 4. Código-Fonte Completo

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * Estrutura que representa uma sala (nó da árvore binária).
 */
typedef struct Sala {
    char *nome;
    struct Sala *esquerda; /* caminho à esquerda */
    struct Sala *direita;  /* caminho à direita */
} Sala;

/*
 * criarSala
 *  - Cria dinamicamente uma sala com o nome informado.
 *  - Aloca memória para a struct e para a string do nome.
 *  - Retorna ponteiro para a sala criada.
 */
Sala *criarSala(const char *nome) {
    Sala *s = (Sala *) malloc(sizeof(Sala));
    if (!s) {
        fprintf(stderr, "Erro: memória insuficiente para criar sala.
");
        exit(EXIT_FAILURE);
    }
    size_t len = strlen(nome) + 1;
    s->nome = (char *) malloc(len);
    if (!s->nome) {
        fprintf(stderr, "Erro: memória insuficiente para nome da sala.
");
        free(s);
        exit(EXIT_FAILURE);
    }
    strcpy(s->nome, nome);
    s->esquerda = NULL;
    s->direita = NULL;
    return s;
}

/*
 * liberarSalas
 *  - Libera recursivamente a árvore a partir do nó passado.
 *  - Evita vazamentos de memória.
 */
void liberarSalas(Sala *root) {
    if (!root) return;
    liberarSalas(root->esquerda);
    liberarSalas(root->direita);
    free(root->nome);
    free(root);
}

/*
 * explorarSalas
 *  - Permite a navegação interativa do jogador pela árvore (mansão).
 *  - Recebe o nó inicial (por exemplo, o Hall) e
 *    permite escolher 'e' (esquerda), 'd' (direita) ou 's' (sair).
 *  - Exibe o nome de cada sala visitada durante a exploração.
 */
void explorarSalas(Sala *inicio) {
    if (!inicio) {
        printf("Mapa vazio. Não há salas para explorar.
");
        return;
    }

    Sala *atual = inicio;
    char **visitadas = NULL;
    size_t n_visitadas = 0;

    while (1) {
        visitadas = (char **) realloc(visitadas, (n_visitadas + 1) * sizeof(char *));
        visitadas[n_visitadas++] = atual->nome;

        printf("
Você está agora na sala: %s
", atual->nome);

        if (!atual->esquerda && !atual->direita) {
            printf("
*** Você chegou a um cômodo sem caminhos (nó-folha). Exploração finalizada. ***
");
            break;
        }

        printf("Opções:
");
        if (atual->esquerda) printf("  (e) Ir para a esquerda -> %s
", atual->esquerda->nome);
        else printf("  (e) Ir para a esquerda -> (não disponível)
");

        if (atual->direita) printf("  (d) Ir para a direita -> %s
", atual->direita->nome);
        else printf("  (d) Ir para a direita -> (não disponível)
");

        printf("  (s) Sair da exploração
");
        printf("Escolha (e/d/s): ");

        char escolha[16];
        fgets(escolha, sizeof(escolha));
        char cmd = tolower(escolha[0]);

        if (cmd == 's') break;
        else if (cmd == 'e' && atual->esquerda) atual = atual->esquerda;
        else if (cmd == 'd' && atual->direita) atual = atual->direita;
        else printf("Comando inválido.
");
    }

    printf("
----- Salas visitadas -----
");
    for (size_t i = 0; i < n_visitadas; i++)
        printf("%zu. %s
", i + 1, visitadas[i]);

    free(visitadas);
}

/*
 * main
 *  - Monta a árvore da mansão e inicia a exploração.
 */
int main(void) {
    Sala *hall = criarSala("Hall de Entrada");

    Sala *salaEstar = criarSala("Sala de Estar");
    Sala *cozinha = criarSala("Cozinha");
    Sala *biblioteca = criarSala("Biblioteca");

    Sala *corredor = criarSala("Corredor");
    Sala *quarto = criarSala("Quarto");
    Sala *jardim = criarSala("Jardim");

    hall->esquerda = salaEstar;
    hall->direita = corredor;

    salaEstar->esquerda = cozinha;
    salaEstar->direita = biblioteca;

    corredor->esquerda = quarto;
    corredor->direita = jardim;

    printf("=== Exploração da Mansão ===
");
    explorarSalas(hall);

    liberarSalas(hall);
    return 0;
}
```

---

## 5. Conclusão

O trabalho demonstra o uso eficiente de uma **árvore binária** aplicada a um problema de navegação interativa.  
A solução atende todos os requisitos propostos e apresenta boa organização estrutural e modularização.

---

## 6. Instruções para Compilação

```
gcc mansao.c -o mansao
./mansao
```

---

## 7. Capturas de Tela (se desejar inserir após testar)
*(Inserir prints mostrando a execução do programa)*

---

## 8. Link do Repositório GitHub

https://github.com/SEU-USUARIO/seu-projeto-mansao  
*(substitua pelo link real após fazer o push)*

---

## 9. Referências

- Documentação Oficial da Linguagem C  
- Material da disciplina de Estrutura de Dados  
