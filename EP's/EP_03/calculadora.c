// /*    
//  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__

//   AO PREENCHER ESSE CABEÇALHO COM O MEU NOME E O MEU NÚMERO USP, 
//   DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESSE PROGRAMA. 
//   TODAS AS PARTES ORIGINAIS DESSE EXERCÍCIO-PROGRAMA (EP) FORAM 
//   DESENVOLVIDAS E IMPLEMENTADAS POR MIM SEGUINDO AS INSTRUÇÕES DESSE EP
//   E QUE PORTANTO NÃO CONSTITUEM PLÁGIO. DECLARO TAMBÉM QUE SOU RESPONSÁVEL
//   POR TODAS AS CÓPIAS DESSE PROGRAMA E QUE EU NÃO DISTRIBUI OU FACILITEI A
//   SUA DISTRIBUIÇÃO. ESTOU CIENTE QUE OS CASOS DE PLÁGIO SÃO PUNIDOS COM 
//   REPROVAÇÃO DIRETA NA DISCIPLINA.

//   Nome: João Lucas Leal
//   NUSP: 13683601

//  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__
// */

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "polinomios.h"

// typedef struct Node {
//     polinomio data;
//     struct Node *next;
// } Node;

// typedef struct Stack {
//     Node *top;
// } Stack;

// void push(Stack *stack, polinomio p) {
//     Node *newNode = (Node *)malloc(sizeof(Node));
//     newNode->data = p;
//     newNode->next = stack->top;
//     stack->top = newNode;
// }

// polinomio pop(Stack *stack) {
//     if (stack->top == NULL) return NULL;
//     Node *temp = stack->top;
//     polinomio p = temp->data;
//     stack->top = stack->top->next;
//     free(temp);
//     return p;
// }

// int isEmpty(Stack *stack) {
//     return stack->top == NULL;
// }

// void descarta_resto_da_linha() {
//     char c;
//     do {
//         scanf("%c", &c);
//     } while (c != '\n' && c != EOF);
// }

// int varIndex(char c) {
//     return c - 'a';
// }

// int main() {
//     polinomio var[26];
//     for (int i = 0; i < 26; i++) {
//         var[i] = cria();
//     }

//     char input[256];
//     printf("*************************\nCalculadora de polinomios\n*************************\n");

//     while (1) {
//         printf("\nDigite uma expressão ou quit para sair do programa:\n> ");
//         fgets(input, 256, stdin);

//         if (strncmp(input, "quit", 4) == 0) break;

//         char varName = input[0];
//         char command = input[1];

//         if (command == '?') {
//             impr(varName, var[varIndex(varName)]);
//         } else if (command == ':') {
//             libera(var[varIndex(varName)]);
//             printf("%c: ", varName);
//             var[varIndex(varName)] = leia();
//             impr(varName, var[varIndex(varName)]);
//         } else if (command == '=') {
//             Stack stack = {NULL};
//             char *token = 
//             (&input[2], " \n");

//             while (token) {
//                 if (token[0] >= 'a' && token[0] <= 'z') {
//                     push(&stack, copia(var[varIndex(token[0])]));
//                 } else if (strcmp(token, "+") == 0) {
//                     polinomio b = pop(&stack);
//                     polinomio a = pop(&stack);
//                     push(&stack, soma(a, b));
//                     libera(a);
//                     libera(b);
//                 } else if (strcmp(token, "-") == 0) {
//                     polinomio b = pop(&stack);
//                     polinomio a = pop(&stack);
//                     push(&stack, subt(a, b));
//                     libera(a);
//                     libera(b);
//                 } else if (strcmp(token, "*") == 0) {
//                     polinomio b = pop(&stack);
//                     polinomio a = pop(&stack);
//                     push(&stack, mult(a, b));
//                     libera(a);
//                     libera(b);
//                 } else if (strcmp(token, "/") == 0) {
//                     polinomio b = pop(&stack);
//                     polinomio a = pop(&stack);
//                     push(&stack, quoc(a, b));
//                     libera(a);
//                     libera(b);
//                 } else if (strcmp(token, "%") == 0) {
//                     polinomio b = pop(&stack);
//                     polinomio a = pop(&stack);
//                     push(&stack, rest(a, b));
//                     libera(a);
//                     libera(b);
//                 } else if (strcmp(token, "~") == 0) {
//                     polinomio a = pop(&stack);
//                     push(&stack, nega(a));
//                     libera(a);
//                 }
//                 token = strtok(NULL, " \n");
//             }

//             libera(var[varIndex(varName)]);
//             var[varIndex(varName)] = pop(&stack);
//             impr(varName, var[varIndex(varName)]);
//         }
//     }

//     for (int i = 0; i < 26; i++) {
//         libera(var[i]);
//     }

//     printf("Tchau!\n");
//     return 0;
// }

// ----

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "polinomios.h"

// typedef struct Node {
//     polinomio data;
//     struct Node *next;
// } Node;

// typedef struct Stack {
//     Node *top;
// } Stack;

// void push(Stack *stack, polinomio p) {
//     Node *newNode = (Node *)malloc(sizeof(Node));
//     newNode->data = p;
//     newNode->next = stack->top;
//     stack->top = newNode;
// }

// polinomio pop(Stack *stack) {
//     if (stack->top == NULL) return NULL;
//     Node *temp = stack->top;
//     polinomio p = temp->data;
//     stack->top = stack->top->next;
//     free(temp);
//     return p;
// }

// int varIndex(char c) {
//     return c - 'a';
// }

// int main() {
//     polinomio var[26];  // Vetor de 26 polinômios (a-z)
//     for (int i = 0; i < 26; i++) {
//         var[i] = cria();  // Inicializa com polinômios nulos
//     }

//     printf("*************************\nCalculadora de polinomios\n*************************\n");

//     char varName, command;
//     while (1) {
//         printf("\nDigite uma expressão ou quit para sair do programa:\n> ");

//         // Ler o primeiro token: pode ser 'quit' ou uma variável com um comando
//         if (scanf(" %c", &varName) != 1) break;

//         // Se for 'quit', sair do programa
//         if (varName == 'q') {
//             char next[5];
//             scanf("%4s", next);  // Verifica se o usuário digitou "quit"
//             if (strcmp(next, "uit") == 0) break;
//         }

//         scanf(" %c", &command);  // Lê o comando ('?', ':', '=')

//         if (command == '?') {  // Consulta o polinômio
//             impr(varName, var[varIndex(varName)]);
//         } else if (command == ':') {  // Atribuir novo polinômio
//             libera(var[varIndex(varName)]);
//             var[varIndex(varName)] = leia();
//             impr(varName, var[varIndex(varName)]);
//         } else if (command == '=') {  // Atribuir resultado de expressão
//             Stack stack = {NULL};
//             char token[10];

//             while (scanf("%s", token) == 1 && token[0] != '\n') {
//                 if (token[0] >= 'a' && token[0] <= 'z') {
//                     push(&stack, copia(var[varIndex(token[0])]));
//                 } else if (strcmp(token, "+") == 0) {
//                     polinomio b = pop(&stack);
//                     polinomio a = pop(&stack);
//                     push(&stack, soma(a, b));
//                     libera(a);
//                     libera(b);
//                 } else if (strcmp(token, "-") == 0) {
//                     polinomio b = pop(&stack);
//                     polinomio a = pop(&stack);
//                     push(&stack, subt(a, b));
//                     libera(a);
//                     libera(b);
//                 } else if (strcmp(token, "*") == 0) {
//                     polinomio b = pop(&stack);
//                     polinomio a = pop(&stack);
//                     push(&stack, mult(a, b));
//                     libera(a);
//                     libera(b);
//                 } else if (strcmp(token, "/") == 0) {
//                     polinomio b = pop(&stack);
//                     polinomio a = pop(&stack);
//                     push(&stack, quoc(a, b));
//                     libera(a);
//                     libera(b);
//                 } else if (strcmp(token, "%") == 0) {
//                     polinomio b = pop(&stack);
//                     polinomio a = pop(&stack);
//                     push(&stack, rest(a, b));
//                     libera(a);
//                     libera(b);
//                 } else if (strcmp(token, "~") == 0) {
//                     polinomio a = pop(&stack);
//                     push(&stack, nega(a));
//                     libera(a);
//                 }
//             }

//             libera(var[varIndex(varName)]);
//             var[varIndex(varName)] = pop(&stack);
//             impr(varName, var[varIndex(varName)]);
//         }
//     }

//     // Libera todos os polinômios antes de sair
//     for (int i = 0; i < 26; i++) {
//         libera(var[i]);
//     }

//     printf("Tchau!\n");
//     return 0;
// }

// ------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "polinomios.h"

typedef struct Node {
    polinomio data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

void push(Stack *stack, polinomio p) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = p;
    newNode->next = stack->top;
    stack->top = newNode;
}

polinomio pop(Stack *stack) {
    if (stack->top == NULL) return NULL;
    Node *temp = stack->top;
    polinomio p = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return p;
}

int varIndex(char c) {
    return c - 'a';
}

int main() {
    polinomio var[26];  // Vetor de 26 polinômios (a-z)
    for (int i = 0; i < 26; i++) {
        var[i] = cria();  // Inicializa com polinômios nulos
    }

    printf("*************************\nCalculadora de polinomios\n*************************\n");

    char varName, command;
    while (1) {
        printf("\nDigite uma expressão ou quit para sair do programa:\n> ");

        if (scanf(" %c", &varName) != 1) break;

        if (varName == 'q') {   // se a letra for 'q', verificar se é 'quit' ou se é polinôomio q.
            char nextChar;
            scanf("%c", &nextChar); // verificar o caractere pós 'q'

            if (nextChar == 'u') {  // se o próximo caractere é 'u' então deve ser tratado como quit
                char rest[3];
                scanf("%2s", rest);  // ler os próximos dois caracteres "it"
                if (strcmp(rest, "it") == 0) break;  // Se for "uit", sair do programa
            } else {
                ungetc(nextChar, stdin);  // ungetc devolve o caractere para a entrada
            }
        }

        scanf(" %c", &command);

        if (command == '?') {
            impr(varName, var[varIndex(varName)]);
        } else if (command == ':') {
            libera(var[varIndex(varName)]);
            var[varIndex(varName)] = leia();
            impr(varName, var[varIndex(varName)]);
        } else if (command == '=') {
            Stack stack = {NULL};
            char token[10];

            while (scanf("%s", token) == 1 && token[0] != '\n') {
                if (token[0] >= 'a' && token[0] <= 'z') {
                    push(&stack, copia(var[varIndex(token[0])]));
                } else if (strcmp(token, "+") == 0) {
                    polinomio b = pop(&stack);
                    polinomio a = pop(&stack);
                    push(&stack, soma(a, b));
                    libera(a);
                    libera(b);
                } else if (strcmp(token, "-") == 0) {
                    polinomio b = pop(&stack);
                    polinomio a = pop(&stack);
                    push(&stack, subt(a, b));
                    libera(a);
                    libera(b);
                } else if (strcmp(token, "*") == 0) {
                    polinomio b = pop(&stack);
                    polinomio a = pop(&stack);
                    push(&stack, mult(a, b));
                    libera(a);
                    libera(b);
                } else if (strcmp(token, "/") == 0) {
                    polinomio b = pop(&stack);
                    polinomio a = pop(&stack);
                    push(&stack, quoc(a, b));
                    libera(a);
                    libera(b);
                } else if (strcmp(token, "%") == 0) {
                    polinomio b = pop(&stack);
                    polinomio a = pop(&stack);
                    push(&stack, rest(a, b));
                    libera(a);
                    libera(b);
                } else if (strcmp(token, "~") == 0) {
                    polinomio a = pop(&stack);
                    push(&stack, nega(a));
                    libera(a);
                }
            }

            libera(var[varIndex(varName)]);
            var[varIndex(varName)] = pop(&stack);
            impr(varName, var[varIndex(varName)]);
        }
    }

    for (int i = 0; i < 26; i++) {
        libera(var[i]);
    }

    printf("Tchau!\n");
    return 0;
}

