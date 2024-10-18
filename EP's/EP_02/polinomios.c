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

typedef struct celula {
    float coeficiente;
    int expoente;
    struct celula *prox;
} Celula;


polinomio cria() {
    return NULL;
}

polinomio leia() {
    Celula *inicio = NULL, *nova, *atual, *anterior;
    float coef;
    int exp;

    while (1) {
        scanf("%f", &coef);
        if (coef == 0) break;
        scanf("%d", &exp);

        if (coef != 0) {
            nova = (Celula *)malloc(sizeof(Celula));
            nova->coeficiente = coef;
            nova->expoente = exp;
            nova->prox = NULL;

            if (inicio == NULL || exp > inicio->expoente) {
                nova->prox = inicio;
                inicio = nova;
            } else {
                atual = inicio;
                anterior = NULL;
                while (atual != NULL && atual->expoente > exp) {
                    anterior = atual;
                    atual = atual->prox;
                }

                if (atual != NULL && atual->expoente == exp) {
                    atual->coeficiente += coef;

                    if (atual->coeficiente == 0) {
                        if (anterior == NULL) {
                            inicio = atual->prox;
                        } else {
                            anterior->prox = atual->prox;
                        }
                        free(atual);
                    }
                    free(nova);
                } else {
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

    return inicio;
}

polinomio copia(polinomio p) {
    if (p == NULL) return NULL;

    Celula *atualP = (Celula *)p;
    Celula *nova, *resultado = NULL, *ultimo = NULL;

    while (atualP != NULL) {
        nova = (Celula *)malloc(sizeof(Celula));  
        nova->coeficiente = atualP->coeficiente;  
        nova->expoente = atualP->expoente;        
        nova->prox = NULL;                        

        if (resultado == NULL) {
            resultado = nova;  
        } else {
            ultimo->prox = nova;  
        }
        ultimo = nova;  
        atualP = atualP->prox;  
    }

    return resultado;
}

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

polinomio soma(polinomio p, polinomio q) {
    Celula *resultado = NULL, *nova, *atualP = (Celula *)p, *atualQ = (Celula *)q, *ultimo = NULL;

    while (atualP != NULL || atualQ != NULL) {
        nova = (Celula *)malloc(sizeof(Celula));
        nova->prox = NULL;

        if (atualP == NULL) {
            nova->coeficiente = atualQ->coeficiente;
            nova->expoente = atualQ->expoente;
            atualQ = atualQ->prox;
        } else if (atualQ == NULL) {
            nova->coeficiente = atualP->coeficiente;
            nova->expoente = atualP->expoente;
            atualP = atualP->prox;
        } else if (atualP->expoente > atualQ->expoente) {
            nova->coeficiente = atualP->coeficiente;
            nova->expoente = atualP->expoente;
            atualP = atualP->prox;
        } else if (atualP->expoente < atualQ->expoente) {
            nova->coeficiente = atualQ->coeficiente;
            nova->expoente = atualQ->expoente;
            atualQ = atualQ->prox;
        } else {
            nova->coeficiente = atualP->coeficiente + atualQ->coeficiente;
            nova->expoente = atualP->expoente;

            if (nova->coeficiente == 0) {
                free(nova);
                atualP = atualP->prox;
                atualQ = atualQ->prox;
                continue;
            }

            atualP = atualP->prox;
            atualQ = atualQ->prox;
        }

        if (resultado == NULL) {
            resultado = nova; 
        } else {
            ultimo->prox = nova;
        }
        ultimo = nova;
    }

    return resultado;
}

polinomio subt(polinomio p, polinomio q) {
    Celula *resultado = NULL, *nova, *atualP = (Celula *)p, *atualQ = (Celula *)q, *ultimo = NULL;

    while (atualP != NULL || atualQ != NULL) {
        nova = (Celula *)malloc(sizeof(Celula));
        nova->prox = NULL;

        if (atualP == NULL) {
            nova->coeficiente = -(atualQ->coeficiente);
            nova->expoente = atualQ->expoente;
            atualQ = atualQ->prox;
        } else if (atualQ == NULL) {
            nova->coeficiente = atualP->coeficiente;
            nova->expoente = atualP->expoente;
            atualP = atualP->prox;
        } else if (atualP->expoente > atualQ->expoente) {
            nova->coeficiente = atualP->coeficiente;
            nova->expoente = atualP->expoente;
            atualP = atualP->prox;
        } else if (atualP->expoente < atualQ->expoente) {
            nova->coeficiente = -(atualQ->coeficiente);
            nova->expoente = atualQ->expoente;
            atualQ = atualQ->prox;
        } else {
            nova->coeficiente = atualP->coeficiente - atualQ->coeficiente;
            nova->expoente = atualP->expoente;

            if (nova->coeficiente == 0) {
                free(nova);
                atualP = atualP->prox;
                atualQ = atualQ->prox;
                continue;
            }

            atualP = atualP->prox;
            atualQ = atualQ->prox;
        }

        if (resultado == NULL) {
            resultado = nova;
        } else {
            ultimo->prox = nova;
        }
        ultimo = nova;
    }

    return resultado;
}

polinomio nega(polinomio p) {
    if (p == NULL) return NULL;

    Celula *atualP = (Celula *)p;
    Celula *nova, *resultado = NULL, *ultimo = NULL;

    while (atualP != NULL) {
        nova = (Celula *)malloc(sizeof(Celula));
        nova->coeficiente = -(atualP->coeficiente);
        nova->expoente = atualP->expoente;
        nova->prox = NULL;       

        if (resultado == NULL) {
            resultado = nova;
        } else {
            ultimo->prox = nova;
        }
        ultimo = nova;
        atualP = atualP->prox;
    }

    return resultado;
}

polinomio mult(polinomio p, polinomio q) {
    Celula *resultado = NULL, *nova, *atualP = (Celula *)p, *atualQ, *ultimo = NULL;

    while (atualP != NULL) {
        atualQ = (Celula *)q;
        
        while (atualQ != NULL) {
            nova = (Celula *)malloc(sizeof(Celula));
            nova->coeficiente = atualP->coeficiente * atualQ->coeficiente;
            nova->expoente = atualP->expoente + atualQ->expoente;
            nova->prox = NULL;

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
                    atualR->coeficiente += nova->coeficiente;
                    if (atualR->coeficiente == 0) {
                        if (anterior == NULL) {
                            resultado = atualR->prox;
                        } else {
                            anterior->prox = atualR->prox;
                        }
                        free(atualR);
                    }
                    free(nova);
                } else {
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


void libera(polinomio p) {
    Celula *atual = (Celula *)p, *tmp;

    while (atual != NULL) {
        tmp = atual;
        atual = atual->prox;
        free(tmp);
    }
}
