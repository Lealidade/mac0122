#include <stdio.h>

#define MAX 101

long binomialI(int n, int k);

int main(){

    int n, k;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    printf("Digite o valor de k: ");
    scanf("%d", &k);

    printf("O resultado eh %ld\n", binomialI(n, k));

    return 0;
}

long binomialI(int n, int k) {
    int i, j, bin[MAX][MAX];
    for (j = 1; j <= k; j++) bin[0][j] = 0;
    for (i = 0; i <= n; i++) bin[i][0] = 1;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= k; j++)
            bin[i][j] = bin[i-1][j] + bin[i-1][j-1];

    return bin[n][k];
}