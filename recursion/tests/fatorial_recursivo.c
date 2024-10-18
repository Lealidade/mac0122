#include <stdio.h>

// Função recursiva para calcular o fatorial
// int fatorial(int n) {
//     // Caso base: fatorial de 0 ou 1 é 1
//     if (n == 0 || n == 1) {
//         return 1;
//     }
//     // Caso recursivo: n * fatorial(n - 1)
//     return n * fatorial(n - 1);
// }

long fatorial(long n) {
    if (n == 0) return 1;
    return n * fatorial(n-1);
}

int main() {
    int numero;
    printf("Digite um número para calcular o fatorial: ");
    scanf("%d", &numero);

    // Calcula e imprime o fatorial
    printf("O fatorial de %d é %ld\n", numero, fatorial(numero));

    return 0;
}
