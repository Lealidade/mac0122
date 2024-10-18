#include <stdio.h>

long binomial(int n, int k);

int main() {
    
    int n, k;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    printf("Digite o valor de k: ");
    scanf("%d", &k);

    printf("O resultado eh %ld\n", binomial(n, k));

    return 0;
}

long binomial(int n, int k){
    if(n < k) return 0;
    if(n == k || k == 0) return 1;

    return (binomial(n-1, k) + binomial(n-1, k-1));
}