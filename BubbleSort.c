#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct No{
int var;
struct No*prox;
}No;


// Função para inicializar uma lista vazia
 No* inicializarLista() {
return NULL ; // Lista vazia
}

// função que cria um nó
No* criarNo(int nova_var) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->var = nova_var;
    novo_no->prox = NULL;
    return novo_no;
}

// Função para inserir um novo valor no início da lista
void inserirNo(No** head, int nova_var) {
    No* novo_no = criarNo(nova_var);
    if (*head == NULL) {
        *head = novo_no;
        return;
    }
    No* temp = *head;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = novo_no;
}


// Função para imprimir a lista ligada
void printLista ( No *no) {
while ( no != NULL ) {
printf ("%d -> ", no-> var ) ;
no = no-> prox;
}
 printf("NULL\n");
}





void bubbleSortLista(No*head) {

    if(head==NULL) return;

    No *ptr1;
    No *ptrOrd=NULL;
    int temp, troca;
    do{
    troca=0;
    ptr1= head;
      while (ptr1->prox != ptrOrd) {
       if (ptr1->var > ptr1->prox->var) {
       temp= ptr1-> var;
       ptr1-> var= ptr1-> prox-> var;
       ptr1-> prox-> var = temp;
       troca=1;
    }
    ptr1 = ptr1-> prox;
      }

ptrOrd = ptr1;
 
 }while(troca);

}



void liberarLista(No* head) {
    No* temp;
    while (head != NULL) {
        temp = head;
        head = head->prox;
        free(temp);  // Libera o nó atual
    }
}



int main(){
int num;
No* head = inicializarLista();

printf("Bem-vindo ao ordenador de listas Bublle Sort\n Digite aqui sua lista de 5 numeros a serem ordenados\n");
for(int i=0; i<5; i++){
 printf("Digite aqui o %d numero da lista: ", i+1);
 scanf ("%d",&num);
 inserirNo(&head, num);
}

printf("Lista antes da ordenacao:\n");
  printLista(head);

   // Ordenando a lista usando Bubble Sort
    bubbleSortLista(head);

    printf("Lista depois da ordenacao:\n");
    printLista(head);

    // Liberando a memória da lista
    liberarLista(head);

 return 0;   
}