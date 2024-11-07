#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct No3 {
    int var;
    struct No3* prox;
} No3;

// Função para inicializar uma lista vazia
No3* inicializarLista() {
    return NULL;  // Lista vazia
}

// função que cria um nó
No3* criarNo(int nova_var) {
    No3* novo_no = (No3*)malloc(sizeof(No3));
    novo_no->var = nova_var;
    novo_no->prox = NULL;
    return novo_no;
}

// Função para inserir um novo valor no início da lista
void inserirNo(No3** head, int nova_var) {
    No3* novo_no = criarNo(nova_var);
    if (*head == NULL) {
        *head = novo_no;
        return;
    }
    No3* temp = *head;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = novo_no;
}


// Função para imprimir a lista encadeada
void printLista(No3* no) {
    while (no != NULL) {
        printf("%d -> ", no->var);
        no = no->prox;
    }
    printf("NULL\n");
}

// Função para liberar a memória da lista
void liberarLista(No3* head) {
    No3* temp;
    while (head != NULL) {
        temp = head;
        head = head->prox;
        free(temp);  // Libera o nó atual
    }
}

// Função para particionar a lista em torno de um pivô
No3* particionar(No3* head, No3** menor, No3** maior) {
    No3* piv = head;
    No3* atual = head->prox;

    *menor = NULL;
    *maior = NULL;

    while (atual != NULL) {
        No3* prox = atual->prox;
        if (atual->var < piv->var) {
            atual->prox = *menor;
            *menor = atual;
        } else {
            atual->prox = *maior;
            *maior = atual;
        }
        atual = prox;
    }
    piv->prox = NULL;  // O pivô é isolado
    return piv;
}

// Função recursiva para realizar o Quick Sort
No3* quickSortLista(No3* head) {
    if (head == NULL || head->prox == NULL) {
        return head;  // Lista vazia ou com um único nó já está ordenada
    }

    No3* menor;
    No3* maior;

    // Particiona a lista em torno do pivô
    No3* piv = particionar(head, &menor, &maior);

    // Ordena recursivamente as listas menores e maiores
    menor = quickSortLista(menor);
    maior = quickSortLista(maior);

    // Concatena as listas: menor -> pivô -> maior
    No3* resultado = menor;
    if (menor != NULL) {
        No3* temp = menor;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = piv;
    } else {
        resultado = piv;
    }
    piv->prox = maior;

    return resultado;
}

int main() {
    int num;
    No3* head = inicializarLista();

    printf("Bem-vindo ao ordenador de listas Quick Sort:\nDigite aqui sua lista de 5 numeros a serem ordenados\n");
    for (int i = 0; i < 5; i++) {
        printf("Digite aqui o %d numero da lista: ", i+1);
        scanf("%d", &num);
        inserirNo(&head, num);
    }

    printf("Lista antes da ordenacao:\n");
    printLista(head);

    // Ordenando a lista usando Quick Sort
    head = quickSortLista(head);

    printf("Lista depois da ordenacao:\n");
    printLista(head);

    // Liberando a memória da lista
    liberarLista(head);

    return 0;
}
