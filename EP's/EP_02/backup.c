/*    
 \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__

  AO PREENCHER ESSE CABEÇALHO COM O MEU NOME E O MEU NÚMERO USP, 
  DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESSE PROGRAMA. 
  TODAS AS PARTES ORIGINAIS DESSE EXERCÍCIO-PROGRAMA (EP) FORAM 
  DESENVOLVIDAS E IMPLEMENTADAS POR MIM SEGUINDO AS INSTRUÇÕES DESSE EP
  E QUE PORTANTO NÃO CONSTITUEM PLÁGIO. DECLARO TAMBÉM QUE SOU RESPONSÁVEL
  POR TODAS AS CÓPIAS DESSE PROGRAMA E QUE EU NÃO DISTRIBUI OU FACILITEI A
  SUA DISTRIBUIÇÃO. ESTOU CIENTE QUE OS CASOS DE PLÁGIO SÃO PUNIDOS COM 
  REPROVAÇÃO DIRETA NA DISCIPLINA.

  Nome: João Lucas Leal
  NUSP: 13683601

 \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__
*/

#include <stdio.h>
#include <stdlib.h>

#include "polinomios.h"

// struct {
//   int             coeficiente;
//   int             expoente;
//   struct celula  *prox;
// } celula;

//   typedef struct celula Celula;

typedef struct celula {
    float coeficiente;  // Coeficiente do termo
    int expoente;       // Expoente do termo
    struct celula *prox;  // Próxima célula da lista encadeada
} Celula;



// int main(){



//   return 0;
// }

/* declaracao da celula das listas encadeadas */

/* prototipo de eventuais funcoes auxiliares */

/* implementacao das funcoes da biblioteca polinomios.h */

// polinomio cria() {
//   // Celula *polinomio = (Celula *)malloc(sizeof(Celula));

//   printf("Vich!  Ainda nao fiz a funcao cria!\n");
//   return NULL;
// }

polinomio cria() {
    return NULL;  // Um polinômio vazio é representado por uma lista encadeada vazia (NULL)
}


// polinomio leia() {
//   printf("Vich!  Ainda nao fiz a funcao leia!\n");
//   return NULL;
// }

// polinomio leia() {
//     Celula *inicio = NULL, *nova, *atual;
//     float coef;
//     int exp;

//     // Leitura dos coeficientes e expoentes
//     while (1) {
//         scanf("%f %d", &coef, &exp);
//         if (exp == 0) break;  // Termina ao ler expoente zero

//         if (coef != 0) {  // Só armazenar termos com coeficiente diferente de zero
//             nova = (Celula *)malloc(sizeof(Celula));
//             nova->coeficiente = coef;
//             nova->expoente = exp;
//             nova->prox = NULL;

//             // Inserir em ordem decrescente de expoente
//             if (inicio == NULL || exp > inicio->expoente) {
//                 nova->prox = inicio;
//                 inicio = nova;
//             } else {
//                 atual = inicio;
//                 while (atual->prox != NULL && atual->prox->expoente > exp) {
//                     atual = atual->prox;
//                 }
//                 nova->prox = atual->prox;
//                 atual->prox = nova;
//             }
//         }
//     }

//     return inicio;  // Retorna o polinômio (início da lista)
// }

polinomio leia() {
    Celula *inicio = NULL, *nova, *atual, *anterior;
    float coef;
    int exp;

    // Leitura dos coeficientes e expoentes
    while (1) {
        // scanf("%f %d", &coef, &exp);
        scanf("%f", &coef);
        if (coef == 0) break;  // Termina ao ler expoente zero
        scanf("%d", &exp);

        // if (coef == 0) break;  // Termina ao ler expoente zero

        if (coef != 0) {  // Só armazenar termos com coeficiente diferente de zero
            nova = (Celula *)malloc(sizeof(Celula));
            nova->coeficiente = coef;
            nova->expoente = exp;
            nova->prox = NULL;

            // Inserir em ordem decrescente de expoente
            if (inicio == NULL || exp > inicio->expoente) {
                // Insere no início
                nova->prox = inicio;
                inicio = nova;
            } else {
                // Insere no meio ou no fim
                atual = inicio;
                anterior = NULL;
                while (atual != NULL && atual->expoente > exp) {
                    anterior = atual;
                    atual = atual->prox;
                }

                if (atual != NULL && atual->expoente == exp) {
                    // Se o expoente já existir, soma os coeficientes
                    atual->coeficiente += coef;

                    // Se o coeficiente resultar em 0, remove o termo
                    if (atual->coeficiente == 0) {
                        if (anterior == NULL) {
                            inicio = atual->prox;
                        } else {
                            anterior->prox = atual->prox;
                        }
                        free(atual);
                    }
                    free(nova); // Libera a nova célula, pois não é necessária
                } else {
                    // Insere o novo termo no meio ou no fim
                    if (anterior == NULL) {
                        nova->prox = inicio;
                        inicio = nova;
                    } else {
                        anterior->prox = nova;
                        nova->prox = atual;
                    }
                }
            }
        }
    }

    return inicio;  // Retorna o polinômio (início da lista)
}


// polinomio leia() {
//     Celula *inicio = NULL, *nova, *atual, *anterior;
//     float coef;
//     int exp;

//     // Leitura dos coeficientes e expoentes
//     while (1) {
//         printf("Digite coeficiente e expoente (expoente 0 para terminar): ");
//         scanf("%f %d", &coef, &exp);  // Lê o coeficiente e o expoente juntos

//         if (coef == 0) break;  // Se o expoente for zero, termina a leitura

//         if (coef != 0) {  // Só armazenar termos com coeficiente diferente de zero
//             nova = (Celula *)malloc(sizeof(Celula));
//             nova->coeficiente = coef;
//             nova->expoente = exp;
//             nova->prox = NULL;

//             // Inserir em ordem decrescente de expoente
//             if (inicio == NULL || exp > inicio->expoente) {
//                 nova->prox = inicio;
//                 inicio = nova;
//             } else {
//                 atual = inicio;
//                 anterior = NULL;
//                 while (atual != NULL && atual->expoente > exp) {
//                     anterior = atual;
//                     atual = atual->prox;
//                 }

//                 if (atual != NULL && atual->expoente == exp) {
//                     // Se o expoente já existir, soma os coeficientes
//                     atual->coeficiente += coef;

//                     // Se o coeficiente resultante for 0, remove o termo
//                     if (atual->coeficiente == 0) {
//                         if (anterior == NULL) {
//                             inicio = atual->prox;
//                         } else {
//                             anterior->prox = atual->prox;
//                         }
//                         free(atual);
//                     }
//                     free(nova); // Libera a nova célula, pois não é necessária
//                 } else {
//                     // Insere o novo termo no meio ou no fim
//                     if (anterior == NULL) {
//                         nova->prox = inicio;
//                         inicio = nova;
//                     } else {
//                         anterior->prox = nova;
//                         nova->prox = atual;
//                     }
//                 }
//             }
//         }
//     }

//     return inicio;  // Retorna o polinômio (início da lista)
// }




// polinomio copia(polinomio p) {
//   printf("Vich!  Ainda nao fiz a funcao copia!\n");
//   return NULL;
// } 

polinomio copia(polinomio p) {
    if (p == NULL) return NULL;

    Celula *atualP = (Celula *)p;
    Celula *nova, *resultado = NULL, *ultimo = NULL;

    while (atualP != NULL) {
        nova = (Celula *)malloc(sizeof(Celula));  // Aloca uma nova célula
        nova->coeficiente = atualP->coeficiente;  // Copia o coeficiente
        nova->expoente = atualP->expoente;        // Copia o expoente
        nova->prox = NULL;                        // A nova célula ainda não tem próxima

        if (resultado == NULL) {
            resultado = nova;  // A primeira célula do resultado
        } else {
            ultimo->prox = nova;  // Liga a célula nova à lista
        }
        ultimo = nova;  // Atualiza o ponteiro para o último nó
        atualP = atualP->prox;  // Avança para o próximo termo do polinômio original
    }

    return resultado;
}


// void impr(char c, polinomio p) {
//   printf("Vich!  Ainda nao fiz a funcao impr!\n");
// }

void impr(char c, polinomio p) {
    Celula *atual = (Celula *)p;
    printf("%c(x) = ", c);

    if (atual == NULL) {
        printf("0\n");
        return;
    }

    while (atual != NULL) {
        printf("%.2f x^%d", atual->coeficiente, atual->expoente);
        if (atual->prox != NULL) printf(" + ");
        atual = atual->prox;
    }
    printf("\n");
}


// polinomio soma(polinomio p, polinomio q) {
//   printf("Vich!  Ainda nao fiz a funcao soma!\n");
//   return NULL;
// }

polinomio soma(polinomio p, polinomio q) {
    Celula *resultado = NULL, *nova, *atualP = (Celula *)p, *atualQ = (Celula *)q, *ultimo = NULL;

    while (atualP != NULL || atualQ != NULL) {
        nova = (Celula *)malloc(sizeof(Celula));
        nova->prox = NULL;

        if (atualP == NULL) {
            // Só resta termos em q
            nova->coeficiente = atualQ->coeficiente;
            nova->expoente = atualQ->expoente;
            atualQ = atualQ->prox;
        } else if (atualQ == NULL) {
            // Só resta termos em p
            nova->coeficiente = atualP->coeficiente;
            nova->expoente = atualP->expoente;
            atualP = atualP->prox;
        } else if (atualP->expoente > atualQ->expoente) {
            // O expoente de p é maior
            nova->coeficiente = atualP->coeficiente;
            nova->expoente = atualP->expoente;
            atualP = atualP->prox;
        } else if (atualP->expoente < atualQ->expoente) {
            // O expoente de q é maior
            nova->coeficiente = atualQ->coeficiente;
            nova->expoente = atualQ->expoente;
            atualQ = atualQ->prox;
        } else {
            // Os expoentes são iguais, somamos os coeficientes
            nova->coeficiente = atualP->coeficiente + atualQ->coeficiente;
            nova->expoente = atualP->expoente;

            // Se a soma resultar em coeficiente zero, ignoramos o termo
            if (nova->coeficiente == 0) {
                free(nova);
                atualP = atualP->prox;
                atualQ = atualQ->prox;
                continue;
            }

            atualP = atualP->prox;
            atualQ = atualQ->prox;
        }

        // Inserir nova célula no resultado
        if (resultado == NULL) {
            resultado = nova; // Primeira célula
        } else {
            ultimo->prox = nova; // Liga à lista existente
        }
        ultimo = nova; // Atualiza o último ponteiro
    }

    return resultado;
}


// polinomio subt(polinomio p, polinomio q) {
//   printf("Vich!  Ainda nao fiz a funcao subt!\n");
//   return NULL;
// }

polinomio subt(polinomio p, polinomio q) {
    Celula *resultado = NULL, *nova, *atualP = (Celula *)p, *atualQ = (Celula *)q, *ultimo = NULL;

    while (atualP != NULL || atualQ != NULL) {
        nova = (Celula *)malloc(sizeof(Celula));
        nova->prox = NULL;

        if (atualP == NULL) {
            // Só resta termos em q, mas subtraímos q de 0
            nova->coeficiente = -(atualQ->coeficiente);  // Subtraímos os termos de q
            nova->expoente = atualQ->expoente;
            atualQ = atualQ->prox;
        } else if (atualQ == NULL) {
            // Só resta termos em p
            nova->coeficiente = atualP->coeficiente;
            nova->expoente = atualP->expoente;
            atualP = atualP->prox;
        } else if (atualP->expoente > atualQ->expoente) {
            // O expoente de p é maior
            nova->coeficiente = atualP->coeficiente;
            nova->expoente = atualP->expoente;
            atualP = atualP->prox;
        } else if (atualP->expoente < atualQ->expoente) {
            // O expoente de q é maior
            nova->coeficiente = -(atualQ->coeficiente);  // Subtraímos os termos de q
            nova->expoente = atualQ->expoente;
            atualQ = atualQ->prox;
        } else {
            // Os expoentes são iguais, subtraímos os coeficientes
            nova->coeficiente = atualP->coeficiente - atualQ->coeficiente;
            nova->expoente = atualP->expoente;

            // Se a subtração resultar em coeficiente zero, ignoramos o termo
            if (nova->coeficiente == 0) {
                free(nova);
                atualP = atualP->prox;
                atualQ = atualQ->prox;
                continue;
            }

            atualP = atualP->prox;
            atualQ = atualQ->prox;
        }

        // Inserir nova célula no resultado
        if (resultado == NULL) {
            resultado = nova; // Primeira célula
        } else {
            ultimo->prox = nova; // Liga à lista existente
        }
        ultimo = nova; // Atualiza o último ponteiro
    }

    return resultado;
}


// polinomio nega(polinomio p) {
//   printf("Vich!  Ainda nao fiz a funcao nega!\n");
//   return NULL;
// }

polinomio nega(polinomio p) {
    if (p == NULL) return NULL;

    Celula *atualP = (Celula *)p;
    Celula *nova, *resultado = NULL, *ultimo = NULL;

    while (atualP != NULL) {
        nova = (Celula *)malloc(sizeof(Celula));  // Aloca uma nova célula
        nova->coeficiente = -(atualP->coeficiente);  // Negamos o coeficiente
        nova->expoente = atualP->expoente;           // Mantemos o expoente
        nova->prox = NULL;                           // A nova célula ainda não tem próxima

        if (resultado == NULL) {
            resultado = nova;  // A primeira célula do resultado
        } else {
            ultimo->prox = nova;  // Liga a célula nova à lista
        }
        ultimo = nova;  // Atualiza o ponteiro para o último nó
        atualP = atualP->prox;  // Avança para o próximo termo do polinômio original
    }

    return resultado;
}


// polinomio mult(polinomio p, polinomio q) {
//   printf("Vich!  Ainda nao fiz a funcao mult!\n");
//   return NULL;
// }

polinomio mult(polinomio p, polinomio q) {
    Celula *resultado = NULL, *nova, *atualP = (Celula *)p, *atualQ, *ultimo = NULL;

    // Percorremos todos os termos de p
    while (atualP != NULL) {
        atualQ = (Celula *)q;
        
        // Multiplicamos cada termo de p por todos os termos de q
        while (atualQ != NULL) {
            nova = (Celula *)malloc(sizeof(Celula));
            nova->coeficiente = atualP->coeficiente * atualQ->coeficiente;
            nova->expoente = atualP->expoente + atualQ->expoente;
            nova->prox = NULL;

            // Inserir o novo termo no resultado, somando coeficientes de expoentes iguais
            if (resultado == NULL) {
                resultado = nova;
                ultimo = nova;
            } else {
                Celula *anterior = NULL, *atualR = resultado;
                while (atualR != NULL && atualR->expoente > nova->expoente) {
                    anterior = atualR;
                    atualR = atualR->prox;
                }

                if (atualR != NULL && atualR->expoente == nova->expoente) {
                    // Se o expoente já existir, somamos os coeficientes
                    atualR->coeficiente += nova->coeficiente;
                    if (atualR->coeficiente == 0) {
                        // Se a soma resultar em coeficiente zero, removemos o termo
                        if (anterior == NULL) {
                            resultado = atualR->prox;
                        } else {
                            anterior->prox = atualR->prox;
                        }
                        free(atualR);
                    }
                    free(nova); // Não precisamos mais de nova
                } else {
                    // Inserimos o novo termo na posição correta
                    if (anterior == NULL) {
                        nova->prox = resultado;
                        resultado = nova;
                    } else {
                        nova->prox = anterior->prox;
                        anterior->prox = nova;
                    }
                }
            }

            atualQ = atualQ->prox;
        }
        atualP = atualP->prox;
    }

    return resultado;
}


polinomio quoc(polinomio p, polinomio q) {
  printf("Vich!  Ainda nao fiz a funcao quoc!\n");
  return NULL;
}

polinomio rest(polinomio p, polinomio q) {
  printf("Vich!  Ainda nao fiz a funcao rest!\n");
  return NULL;
}

// void libera(polinomio p) {
//   printf("Vich!  Ainda nao fiz a funcao libera!\n");
// }

void libera(polinomio p) {
    Celula *atual = (Celula *)p, *tmp;

    while (atual != NULL) {
        tmp = atual;
        atual = atual->prox;
        free(tmp);
    }
}


/* Implementacao das funcoes auxiliares */