#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct No2 {
    int var;
    struct No2* prox;
} No2;

// Função para inicializar uma lista vazia
No2* inicializarLista() {
    return NULL;  // Lista vazia
}
// função que cria um nó
No2* criarNo(int nova_var) {
    No2* novo_no = (No2*)malloc(sizeof(No2));
    novo_no->var = nova_var;
    novo_no->prox = NULL;
    return novo_no;
}

// Função para inserir um novo valor no início da lista
void inserirNo(No2** head, int nova_var) {
    No2* novo_no = criarNo(nova_var);
    if (*head == NULL) {
        *head = novo_no;
        return;
    }
    No2* temp = *head;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = novo_no;
}



// Função para imprimir a lista encadeada
void printLista(No2* no) {
    while (no != NULL) {
        printf("%d -> ", no->var);
        no = no->prox;
    }
    printf("NULL\n");
}

// Função para liberar a memória da lista
void liberarLista(No2* head) {
    No2* temp;
    while (head != NULL) {
        temp = head;
        head = head->prox;
        free(temp);  // Libera o nó atual
    }
}

// Função para dividir a lista ao meio
void dividirLista(No2* head, No2** frente, No2** tras) {
    No2* lento = head;
    No2* rapido = head->prox;

    // Move o ponteiro 'rapido' duas posições e o 'lento' uma posição
    while (rapido != NULL) {
        rapido = rapido->prox;
        if (rapido != NULL) {
            lento = lento->prox;
            rapido = rapido->prox;
        }
    }

    // Divide a lista ao meio
    *frente = head;
    *tras = lento->prox;
    lento->prox = NULL;
}

// Função para mesclar duas listas ordenadas
No2* mergeListas(No2* lista1, No2* lista2) {
    if (lista1 == NULL) return lista2;
    if (lista2 == NULL) return lista1;

    No2* resultado;

    if (lista1->var <= lista2->var) {
        resultado = lista1;
        resultado->prox = mergeListas(lista1->prox, lista2);
    } else {
        resultado = lista2;
        resultado->prox = mergeListas(lista1, lista2->prox);
    }

    return resultado;
}

// Função recursiva para realizar o Merge Sort
void mergeSortLista(No2** head) {
    No2* atual = *head;
    No2* frente;
    No2* tras;

    // Base da recursão: lista vazia ou com um único nó
    if (atual == NULL || atual->prox == NULL) {
        return;
    }

    // Divide a lista em duas metades
    dividirLista(atual, &frente, &tras);

    // Ordena as duas metades recursivamente
    mergeSortLista(&frente);
    mergeSortLista(&tras);

    // Mescla as duas listas ordenadas
    *head = mergeListas(frente, tras);
}

int main() {
    int num;
    No2* head = inicializarLista();

    printf("Bem-vindo ao ordenador de listas Merge Sort\nDigite aqui sua lista de 5 numeros a serem ordenados\n");
    for (int i = 0; i < 5; i++) {
        printf("Digite aqui o %d numero da lista: ", i + 1);
        scanf("%d", &num);
        inserirNo(&head, num);
    }

    printf("Lista antes da ordenacao:\n");
    printLista(head);

    // Ordenando a lista usando Merge Sort
    mergeSortLista(&head);

    printf("Lista depois da ordenacao:\n");
    printLista(head);

    // Liberando a memória da lista
    liberarLista(head);

    return 0;
}
