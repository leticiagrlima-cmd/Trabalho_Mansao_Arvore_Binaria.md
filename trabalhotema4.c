#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Sala {
    char *nome;
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

Sala *criarSala(const char *nome) {
    Sala *s = malloc(sizeof(Sala));
    s->nome = malloc(strlen(nome) + 1);
    strcpy(s->nome, nome);
    s->esquerda = NULL;
    s->direita = NULL;
    return s;
}

void liberarSalas(Sala *root) {
    if (!root) return;
    liberarSalas(root->esquerda);
    liberarSalas(root->direita);
    free(root->nome);
    free(root);
}

void explorarSalas(Sala *inicio) {
    Sala *atual = inicio;
    char escolha[10];

    while (1) {
        printf("\nVocê está na sala: %s\n", atual->nome);

        if (!atual->esquerda && !atual->direita) {
            printf("Sem caminhos disponíveis. Fim da exploração.\n");
            break;
        }

        printf("(e) Esquerda  ");
        if (atual->esquerda) printf("-> %s  ", atual->esquerda->nome);
        else printf("(indisp.)  ");

        printf("(d) Direita  ");
        if (atual->direita) printf("-> %s  ", atual->direita->nome);
        else printf("(indisp.)  ");

        printf("(s) Sair\nEscolha: ");

        fgets(escolha, sizeof(escolha), stdin);
        char cmd = tolower(escolha[0]);

        if (cmd == 's') break;
        else if (cmd == 'e' && atual->esquerda) atual = atual->esquerda;
        else if (cmd == 'd' && atual->direita) atual = atual->direita;
        else printf("Movimento inválido.\n");
    }
}

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

    explorarSalas(hall);
    liberarSalas(hall);

    return 0;
}
