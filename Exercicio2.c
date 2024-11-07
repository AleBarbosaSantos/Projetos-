

/*Exercício2
Dado um array de inteiros nums, classifique o array em ordem crescente e retorne-o.
Você deve resolver o problema sem usar nenhuma função interna O(nlog(n)) em complexidade
 de tempo e com a menor complexidade de espaço possível.
  */
 #include <stdio.h>
#include <stdlib.h>

// Função auxiliar para mesclar dois subarrays
void merge(int nums[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Arrays temporários
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // Copia dados para os arrays temporários
    for (int i = 0; i < n1; i++)
        L[i] = nums[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = nums[mid + 1 + j];

    // Mescla os arrays temporários de volta no array original
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            nums[k] = L[i];
            i++;
        } else {
            nums[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        nums[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        nums[k] = R[j];
        j++;
        k++;
    }

    // Libera a memória alocada para L e R
    free(L);
    free(R);
}

// Função de ordenação usando Merge Sort
void mergeSort(int nums[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        // Mescla as duas metades
        merge(nums, left, mid, right);
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
    
    printf("Bem-vindo ao ordenador decrescente de array\n");
  
  // Solicita o tamanho do array ao usuário
    printf("Digite o numero de elementos no array: ");
    scanf("%d", &size);
    int* nums = (int*)malloc(size * sizeof(int));

// Solicita os elementos do array ao usuário
    printf("Digite os elementos do array:\n");
    for (int i = 0; i < size; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &nums[i]);
    }


    printf("Array original: ");
    printArray(nums, size);

    mergeSort(nums, 0, size - 1);

    printf("Array ordenado: ");
    printArray(nums, size);

    return 0;
}


