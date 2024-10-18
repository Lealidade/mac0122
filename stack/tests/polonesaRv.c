#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // Para usar isdigit() e isalpha()

#define MAX 100

// Definição da pilha para armazenar os operadores
typedef struct {
    char itens[MAX];
    int topo;
} Pilha;

// Função para inicializar a pilha
void inicializar(Pilha* p) {
    p->topo = -1;
}

// Verifica se a pilha está vazia
int estaVazia(Pilha* p) {
    return p->topo == -1;
}

// Verifica se a pilha está cheia
int estaCheia(Pilha* p) {
    return p->topo == MAX - 1;
}

// Empilha um elemento
void empilhar(Pilha* p, char valor) {
    if (estaCheia(p)) {
        printf("Erro: Pilha cheia!\n");
        exit(1);
    }
    p->itens[++(p->topo)] = valor;
}

// Desempilha um elemento
char desempilhar(Pilha* p) {
    if (estaVazia(p)) {
        printf("Erro: Pilha vazia!\n");
        exit(1);
    }
    return p->itens[(p->topo)--];
}

// Verifica a precedência dos operadores
int precedencia(char operador) {
    if (operador == '+' || operador == '-') return 1;
    if (operador == '*' || operador == '/') return 2;
    return 0;
}

// Função para converter a expressão infixa para pós-fixa
void infixaParaPosfixa(char* expressao) {
    Pilha p;
    inicializar(&p);
    char resultado[MAX];  // Para armazenar a expressão pós-fixa
    int k = 0;  // Índice para resultado

    for (int i = 0; expressao[i] != '\0'; i++) {
        char token = expressao[i];

        // Se o token for um operando (número ou letra), adiciona ao resultado
        if (isalnum(token)) {
            resultado[k++] = token;
        }
        // Se o token for um parêntese abrindo, empilha
        else if (token == '(') {
            empilhar(&p, token);
        }
        // Se o token for um parêntese fechando
        else if (token == ')') {
            while (!estaVazia(&p) && p.itens[p.topo] != '(') {
                resultado[k++] = desempilhar(&p);
            }
            desempilhar(&p);  // Remove o '(' da pilha
        }
        // Se o token for um operador
        else {
            while (!estaVazia(&p) && 
                   precedencia(p.itens[p.topo]) >= precedencia(token)) {
                resultado[k++] = desempilhar(&p);
            }
            empilhar(&p, token);
        }
    }

    // Remove os operadores restantes da pilha
    while (!estaVazia(&p)) {
        resultado[k++] = desempilhar(&p);
    }
    resultado[k] = '\0';  // Termina a string

    printf("Expressao pos-fixa: %s\n", resultado);
}

int main() {
    char expressao[MAX];

    printf("Digite uma expressao infixa: ");
    scanf("%s", expressao);

    infixaParaPosfixa(expressao);

    return 0;
}
