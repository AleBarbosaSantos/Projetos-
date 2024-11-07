#include <stdio.h>
/*Exercício 1
faça um programa em c em que Dado um array de inteiros nums,
mova todos os inteiros pares no início do array, 
seguidos por todos os inteiros ímpares.
Retorna qualquer array que satisfaça esta condição.*/




// Função para mover todos os inteiros pares para o início do array
void rearrangeArray(int nums[], int size) {
    int left = 0;
    int right = size - 1;

    while (left < right) {
        // Avança o ponteiro esquerdo se o número for par
        if (nums[left] % 2 == 0) {
            left++;
        }
        // Retrocede o ponteiro direito se o número for ímpar
        else if (nums[right] % 2 != 0) {
            right--;
        }
        // Se nums[left] é ímpar e nums[right] é par, troque-os
        else {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }
}

// Função para imprimir o array
void printArray(int nums[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", nums[i]);
    printf("\n");
}

int main() {
    int size;

    // Solicita o tamanho do array ao usuário
    printf("Digite o numero de elementos no array: ");
    scanf("%d", &size);

    int nums[size];

    // Solicita os elementos do array ao usuário
    printf("Digite os elementos do array:\n");
    for (int i = 0; i < size; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &nums[i]);
    }

    printf("Array original: ");
    printArray(nums, size);

    // Chama a função para rearranjar o array
    rearrangeArray(nums, size);

    printf("Array rearranjado (pares no inicio, impares no final): ");
    printArray(nums, size);

    return 0;
}

