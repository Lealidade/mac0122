#include <stdio.h>

long fibonacci(int n);

int main(){

    int n;
    printf("Digite um número: ");
    scanf("%d", &n);

    long resultado = fibonacci(n);

    printf("O valor eh %ld\n", resultado);

    return 0;
}

long fibonacci(int n) {
    int valor, i;
    if (n==1) return 1;
    if (n==2) return 2;
    int a = 1;
    int b = 2;

    for(i=2; i<=n; i++){
        valor = a + b;
        a = b;
        b = valor;
    }

    return valor;
}