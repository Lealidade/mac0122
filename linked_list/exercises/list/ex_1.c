// Escreva uma função com protótipo int soma (Celula *ini);
// que recebe uma lista encadeada ini de números inteiros e 
// devolve a soma dos números na lista. Suponha que a lista 
// encadeada não tem cabeça de lista.

#include <stdlib.h>
#include <stdio.h>

struct celula {
    int conteudo;
    struct celula *prox;
};
typedef struct celula Celula;

// ---------------------

int soma(Celula *ini);

int main(){
    // Aloca memória para os nós da lista
    Celula *n1 = (Celula *)malloc(sizeof(Celula));
    Celula *n2 = (Celula *)malloc(sizeof(Celula));
    Celula *n3 = (Celula *)malloc(sizeof(Celula));

    // Inicializa os conteúdos dos nós
    n1->conteudo = 10;
    n2->conteudo = 20;
    n3->conteudo = 30;

    // Conecta os nós para formar a lista encadeada
    n1->prox = n2;
    n2->prox = n3;
    n3->prox = NULL;  // O último nó aponta para NULL

    // Chama a função soma e imprime o resultado
    int resultado = soma(n1);
    printf("Soma dos elementos: %d\n", resultado);

    // Libera a memória alocada
    free(n1);
    free(n2);
    free(n3);

    return 0;
}

int soma(Celula *ini){
    Celula *p;
    int soma = 0;
    p = ini;

    while(p != NULL){
        soma = soma + p->conteudo;
        p = p->prox;
    }
    return soma;
}