// Escreva uma função com protótipo
// int conta (Celula *ini, int x);
// que recebe uma lista encadeada ini de números inteiros 
// e um inteiro x, e devolve o número de vezes que x aparece na lista. 
// Suponha que a lista encadeada não tem cabeça de lista.

#include <stdlib.h>
#include <stdio.h>

struct celula {
    int conteudo;
    struct celula *prox;
};
typedef struct celula Celula;

// -------------------------------

int conta (Celula *ini, int x);

int main() {
    // Aloca memória para os nós da lista
    Celula *n1 = (Celula *)malloc(sizeof(Celula));
    Celula *n2 = (Celula *)malloc(sizeof(Celula));
    Celula *n3 = (Celula *)malloc(sizeof(Celula));
    Celula *n4 = (Celula *)malloc(sizeof(Celula));

    // Inicializa os conteúdos dos nós
    n1->conteudo = 10;
    n2->conteudo = 20;
    n3->conteudo = 10;
    n4->conteudo = 30;

    // Conecta os nós para formar a lista encadeada
    n1->prox = n2;
    n2->prox = n3;
    n3->prox = n4;
    n4->prox = NULL;  // O último nó aponta para NULL

    // Chama a função conta e imprime o resultado
    int resultado = conta(n1, 10);
    printf("O número 10 aparece %d vezes na lista.\n", resultado);

    // Libera a memória alocada
    free(n1);
    free(n2);
    free(n3);
    free(n4);

    return 0;
}

int conta (Celula *ini, int x){
    Celula *p;
    p = ini;
    int count = 0;

    while (p != NULL){
        if(p->conteudo == x) count ++;
        p = p->prox;
    }
    return count;
}