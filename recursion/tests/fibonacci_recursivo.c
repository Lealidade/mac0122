#include <stdio.h>

long fibonacci(int n);

int main() {
    int numero;
    printf("Digite um numero para calcular fibonacci: ");
    scanf("%d", &numero);
    printf("O valor eh %ld\n", fibonacci(numero));
    return 0;
}


long fibonacci(int n) {
    if (n == 0) return 0;
    if (n==1) return 1;
    long resultado = fibonacci(n-1) + fibonacci(n-2);
    return resultado;
}
