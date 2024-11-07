#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct No1 {
    int var;
    struct No1* prox;
} No1;

// Função para inicializar uma lista vazia
No1* inicializarLista() {
    return NULL; // Lista vazia
}


// função que cria um nó
No1* criarNo(int nova_var) {
    No1* novo_no = (No1*)malloc(sizeof(No1));
    novo_no->var = nova_var;
    novo_no->prox = NULL;
    return novo_no;
}

// Função para inserir um novo valor no início da lista
void inserirNo(No1** head, int nova_var) {
    No1* novo_no = criarNo(nova_var);
    if (*head == NULL) {
        *head = novo_no;
        return;
    }
    No1* temp = *head;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = novo_no;
}


// Função para imprimir a lista encadeada
void printLista(No1* no) {
    while (no != NULL) {
        printf("%d -> ", no->var);
        no = no->prox;
    }
    printf("NULL\n");
}

// Função para inserir um nó na posição correta em uma lista ordenada
void inserirOrdenado(No1** sorted, No1* novo_no) {
    if (*sorted == NULL || (*sorted)->var >= novo_no->var) {
        novo_no->prox = *sorted;
        *sorted = novo_no;
    } else {
        No1* atual = *sorted;
        while (atual->prox != NULL && atual->prox->var < novo_no->var) {
            atual = atual->prox;
        }
        novo_no->prox = atual->prox;
        atual->prox = novo_no;
    }
}

// Função de Insertion Sort para lista encadeada
void insertionSort(No1** head) {
    No1* sorted = NULL;  // Lista que será ordenada
    No1* atual = *head;

    while (atual != NULL) {
        No1* prox = atual->prox;  // Guarda o próximo nó
        inserirOrdenado(&sorted, atual);  // Insere o nó atual na lista ordenada
        atual = prox;
    }

    *head = sorted;  // Atualiza a lista original para a lista ordenada
}

// Função para liberar a memória da lista encadeada
void liberarLista(No1* head) {
    No1* temp;
    while (head != NULL) {
        temp = head;
        head = head->prox;
        free(temp);  // Libera o nó atual
    }
}

int main() {
    int num;
    No1* head = inicializarLista();

    printf("Bem-vindo ao ordenador de listas Insertion Sort\nDigite aqui sua lista de 5 numeros a serem ordenados\n");
    for (int i = 0; i < 5; i++) {
        printf("Digite aqui o %d numero da lista: ", i + 1);
        scanf("%d", &num);
        inserirNo(&head, num);
    }

    printf("Lista antes da ordenacao:\n");
    printLista(head);

    // Ordenando a lista usando Insertion Sort
    insertionSort(&head);

    printf("Lista depois da ordenacao:\n");
    printLista(head);

    // Liberando a memória da lista
    liberarLista(head);

    return 0;
}
