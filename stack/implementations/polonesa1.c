/* *********************************************************************************** */
/* Este programa faz parte do material de MAC0121 produzido pelo Prof. Coelho de Pina. */
/* *********************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

int mostreItem;    /* indica se o item sendo examinado deve ser exibido */
int mostrePosfixa; /* indica se expressao em notacao posfixa deve ser 
		            * exibida depois de um item ser examinado */
int mostrePilha;   /* indica se o conteudo da pilha deve ser exibido 
		             * depois de um item ser examinado */

char *nomeProg;  /* nome do programa */

void mostreUso(char *nomeProg);
void *mallocSafe(unsigned int n); 
char *infixaParaPosfixa(char *infixa);

int main(int argc, char *argv[]) {
    nomeProg = argv[0];

    if (argc == 1) {
        mostreUso(nomeProg);
        return 0;
    }

    mostreItem = FALSE;
    mostrePosfixa = FALSE;
    mostrePilha = FALSE;

    /* examina os argumentos na linha de comando */
    while (--argc > 1) {
        if (strncmp(argv[argc], "-i", 2) == 0) mostreItem = TRUE;
        else if (strncmp(argv[argc], "-p", 2) == 0) mostrePosfixa = TRUE;
        else if (strncmp(argv[argc], "-s", 2) == 0) mostrePilha = TRUE;
        else {
            mostreUso(nomeProg);
            return EXIT_FAILURE;
        }
    }

    printf("polonesa: %s\n", infixaParaPosfixa(argv[1]));

    return 0;
}

char *infixaParaPosfixa(char *infixa) {
    char *polonesa;
    int n = strlen(infixa); /* comprimento da expressao infixa */
    int i, j;
    char *s;
    int topo;

    polonesa = mallocSafe((n + 1) * sizeof(char));
    s = mallocSafe(n * sizeof(char));
    topo = 0;

    j = 0;
    for (i = 0; i < n; i++) {
        if (mostreItem) {
            fprintf(stdout, "item   : '%c'\n", infixa[i]);
        }

        switch (infixa[i]) {
            char item;

            case '(':
                s[topo++] = infixa[i];
                break;
            case ')':
                while ((item = s[--topo]) != '(')
                    polonesa[j++] = item;
                break;
            case '+': 
            case '-': 
                while (topo != 0 && (item = s[topo - 1]) != '(') {
                    polonesa[j++] = s[--topo];
                }
                s[topo++] = infixa[i];
                break;
            case '*':
            case '/': 
                while (topo != 0 && (item = s[topo - 1]) != '('
                        && item != '+' && item != '-') {
                    polonesa[j++] = s[--topo];
                }
                s[topo++] = infixa[i];
                break;
            default:  
                if (infixa[i] != ' ') 
                    polonesa[j++] = infixa[i];
                break;
        }

        if (mostrePilha) {
            int k;
            fprintf(stdout, "pilha: ");
            if (topo == 0) fprintf(stdout, "vazia.");
            for (k = 0; k < topo; k++) {
                fprintf(stdout, "%c ", s[k]);
            }
            fprintf(stdout, "\n");
        }

        if (mostrePosfixa) {
            int k;
            fprintf(stdout, "posfixa: ");
            for (k = 0; k < j; k++) {
                fprintf(stdout, "%c ", polonesa[k]);
            }
            fprintf(stdout, "\n");
        }

        if (mostreItem || mostrePosfixa || mostrePilha) {
            printf("\n");
        }
    }

    while (topo != 0) {
        polonesa[j++] = s[--topo];
    }

    polonesa[j] = '\0';
    free(s);

    return polonesa;
}

void mostreUso(char *nomeProg) {
    fprintf(stdout, "Uso: %s \"<expressao infixa>\" [-i] [-e] [-p]\n"
                    " -i mostra o item sendo examinado\n"
                    " -p mostra a expressao posfixa sendo construida\n"
                    " -s mostra o conteudo da pilha\n", nomeProg);
}

void *mallocSafe(unsigned int n) {
    void *p = malloc(n);
    if (p == NULL) {
        fprintf(stderr, "%s, malloc de %u bytes falhou.\n", nomeProg, n);
        exit(-1);
    }
    return p;
}
