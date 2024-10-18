// // #include <stdio.h>

// // int main() {
// //     int num = 10;  // Declarando uma variável inteira
// //     int *p;        // Declarando um ponteiro para int
    
// //     p = &num;  // O ponteiro p recebe o endereço da variável num

// //     printf("Valor de num: %d\n", num);             // Mostra o valor de num
// //     printf("Endereço de num: %p\n", (void*)&num);  // Mostra o endereço de num
// //     printf("Valor de p: %p\n", (void*)p);          // Mostra o endereço armazenado em p (que é o endereço de num)
// //     printf("Valor apontado por p: %d\n", *p);      // Mostra o valor armazenado no endereço apontado por p (que é o valor de num)

// //     return 0;
// // }

// // #include <stdio.h>

// // int main() {
// //     int arr[] = {1, 2, 3, 4, 5};  // Declarando um array de inteiros
// //     int *p = arr;  // Ponteiro aponta para o primeiro elemento do array

// //     printf("Elementos do array usando ponteiros:\n");
// //     printf("endereco do array ou p: -- %p\n\n", p);
// //     printf("2 endereco do array ou p: -- %p\n\n", (p+1));
// //     printf("3 endereco do array ou p: -- %p\n\n", (p+2));
// //     printf("4 endereco do array ou p: -- %p\n\n", (p+3));




// //     printf("valor do primeiro do array ou p: -- %d\n\n", *p);


// //     for (int i = 0; i < 5; i++) {
// //         printf("Elemento %d: %d\n", i, *(p + i));  // Acessando elementos do array usando aritmética de ponteiros
// //     }

// //     return 0;
// // }

// #include <stdio.h>
// #include <stdlib.h>  // Necessário para malloc e free

// int main() {
//     // int n;
//     // printf("Digite o número de elementos: ");
//     // scanf("%d", &n);

//     // // Alocação dinâmica de memória para n inteiros
//     // int *arr = (int *)malloc(n * sizeof(int));
//     // if (arr == NULL) {
//     //     printf("Erro de alocação de memória\n");
//     //     return 1;  // Saída do programa se a alocação falhar
//     // }

//     // // Preenchendo o array
//     // for (int i = 0; i < n; i++) {
//     //     arr[i] = i + 1;
//     // }

//     // // Exibindo os elementos do array
//     // printf("Elementos do array alocado dinamicamente:\n");
//     // for (int i = 0; i < n; i++) {
//     //     printf("%d ", arr[i]);
//     // }
//     // printf("\n");

//     // // Liberando a memória alocada
//     // free(arr);

//     // return 0;

//     int i;
// scanf("%d", &i);
// printf("end. i=%p cont. i=%d",
// (void *)&i, i);

// return 0;
// }


#include <stdio.h>

// Função errada
void troca_errada(int i, int j) {
    int temp;
    temp = i;
    i = j;
    j = temp;
}

// Função certa
void troca_certa(int *i, int *j) {
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

int main() {
    int a = 5, b = 10;

    printf("Antes da troca: a = %d, b = %d\n", a, b);

    troca_errada(a, b);
    printf("Depois da troca (função errada): a = %d, b = %d\n", a, b);

    troca_certa(&a, &b);
    printf("Depois da troca (função certa): a = %d, b = %d\n", a, b);

    return 0;
}
