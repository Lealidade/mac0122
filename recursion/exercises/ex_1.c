// Escreva uma função recursiva com protótipo
//    int num_digitos (int n);
// que devolve o número de dígitos de n.

#include <stdio.h>

int num_digitos(int n);
int num_digitosP(int n);

int main() {

    int n;

    printf("Digite um valor n >= 0: ");
    scanf("%d", &n);

    printf("Os digitos desse numero eh: %d\n", num_digitos(n)); // método normal

    return 0;
}

int num_digitos(int n){
    if (n/10 == 0) return 1;
    return num_digitos(n/10) + 1;
}

int num_digitosP(int n){
    int j = n;
    int count = 0;
    while (j != 0) {
        j = j / 10;
        count++;
    }
    return count;
}