// Escreva uma função recursiva com protótipo
//    int soma_digitos (int n);
// que devolve a soma do número de dígitos de n.

# include <stdio.h>
# include <math.h>

int soma_digitos(int n);
int soma_digitosN(int n);
int num_digitos(int n);

int main(){
    int n;

    printf("Digite o valor: ");
    scanf("%d", &n);

    printf("O resultado eh: %d\n", soma_digitos(n));

    return 0;
}

int soma_digitos(int n){
    if (n / 10 == 0) return n;
    return (n % 10) + soma_digitos(n / 10);
}

int soma_digitosN(int n){
    int j = n;
    int soma = 0;
    int digitos = num_digitos(n);
    for(int i = 0; i < digitos; i++){
        soma = soma + j % 10;
        j = j / 10;
    }
    return soma;
}

int num_digitos(int n){
    if (n/10 == 0) return 1;
    return num_digitos(n/10) + 1;
}