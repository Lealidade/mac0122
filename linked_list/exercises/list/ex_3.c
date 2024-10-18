// Considere as declarações
// #define FALSE 0
// #define TRUE  1
// Escreva uma função com protótipo
// int crescente (Celula *ini);
// que recebe uma lista encadeada ini de números inteiros e devolve TRUE se 
// a lista está em ordem crescente e FALSE caso contrário. Suponha que a 
// lista encadeada não tem cabeça de lista e que contém pelo menos um elemento.

#include <stdlib.h>
#include <stdio.h>

#define FALSE 0
#define TRUE 1

struct celula {
    int conteudo;
    struct celula *prox;
};
typedef struct celula Celula;

// -----------------------

int crescente (Celula *ini);

int main() {
    // Aloca memória para os nós da lista
    Celula *n1 = (Celula *)malloc(sizeof(Celula));
    Celula *n2 = (Celula *)malloc(sizeof(Celula));
    Celula *n3 = (Celula *)malloc(sizeof(Celula));
    Celula *n4 = (Celula *)malloc(sizeof(Celula));

    // Inicializa os conteúdos dos nós
    n1->conteudo = 10;
    n2->conteudo = 20;
    n3->conteudo = 30;
    n4->conteudo = 40;

    // Conecta os nós para formar a lista encadeada
    n1->prox = n2;
    n2->prox = n3;
    n3->prox = n4;
    n4->prox = NULL;  // O último nó aponta para NULL

    // Chama a função crescente e imprime o resultado
    if (crescente(n1)) {
        printf("A lista está em ordem crescente.\n");
    } else {
        printf("A lista não está em ordem crescente.\n");
    }

    // Teste com uma lista não crescente
    n2->conteudo = 35;  // Altera o valor para testar uma lista não crescente
    if (crescente(n1)) {
        printf("A lista está em ordem crescente.\n");
    } else {
        printf("A lista não está em ordem crescente.\n");
    }

    // Libera a memória alocada
    free(n1);
    free(n2);
    free(n3);
    free(n4);

    return 0;
}

int crescente(Celula *ini) {
    Celula *p = ini;

    while (p->prox != NULL) {
        if (p->conteudo > p->prox->conteudo) {
            return FALSE;
        }
        p = p->prox;
    }
    return TRUE;
}