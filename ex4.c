#include <stdio.h>
typedef struct Node {
  int number;
  struct Node *next;
} Node;

typedef struct Queue {
  Node *head; // Nó inicial da fila
  Node *tail; // Nó final da fila

  /* Determina a quantidade máxima de itens que a fila pode comportar */
  int max_items;

  /* Indica a quantidade de elementos presentes na fila */
  int qty;
} Queue;

// - Exibir os elementos presentes na fila
void printQueue(Queue fila) {
  Node *current = fila.head;
  printf("================================\n");
  printf("inicio\n");
  for (int i = 0; i < fila.qty; i++) {
    printf("%d\n", current->number);
    current = current->next;
  }
  printf("fim\n");
  printf("================================\n");
}
// - Inserir um elemento na fila
void insertNode(int value, Queue *fila) {
  if (fila->max_items == fila->qty && fila->qty != 0) {
    printf("FILA CHEIA! IMPOSSIVEL ADICIONAR O ELEMENTO");
    return;
  }

  Node *current = (Node *)malloc(sizeof(Node));
  if (fila->qty == 0) {
    current->number = value;
    fila->head = current;
    fila->tail = current;
    fila->qty++;
    printf("VALOR %d ADICIONADO AO FINAL DA FILA\n", fila->tail->number);
  } else {
    current = fila->tail;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->number = value;
    newNode->next = NULL;
    current->next = newNode;
    fila->tail = newNode;
    fila->qty++;
    printf("VALOR %d ADICIONADO AO FINAL DA FILA\n", fila->tail->number);
  }
}

Queue initQueue(Queue *queue) {
  queue->qty = 0;
  queue->max_items = 20;
  return *queue;
}
// void ordenar(Queue *fila) {
//   Node *current = fila->tail;
  
//   while(current =! NULL){
    
//   }

// }

void ordenarbymiguel(Queue *fila) {
  Node *atual = fila->head;
  Node * xpto = fila->head;

  while(atual != NULL){
    
    while(xpto != NULL){
      if(atual->number < xpto->number){
        int n1 = atual->number;
        atual->number = xpto->number;
        xpto->number = n1;
      }
      xpto = xpto->next;
    }
  atual = atual->next;
  }
}
void ex4(Queue *fila, Queue *fila2, Queue *fila3) {
  Node *fila1Current = fila->head;
  Node *fila2Current = fila2->head;
  Node *fila3Current;

  while (fila1Current != NULL) {
    insertNode(fila1Current->number, fila3);
    fila1Current = fila1Current->next;
  }
  while (fila2Current != NULL) {
    insertNode(fila2Current->number, fila3);
    fila2Current = fila2Current->next;
  }
  // ordenarbymiguel(fila3);
  printQueue(*fila3);

}
int main(void) {
  Queue fila1 = initQueue(&fila1);
  Queue fila2 = initQueue(&fila2);
  Queue fila3 = initQueue(&fila3);
  insertNode(10, &fila1);
  insertNode(33, &fila1);
  insertNode(7, &fila1);

  insertNode(666, &fila2);
  insertNode(999, &fila2);
  insertNode(16, &fila2);

  ex4(&fila1, &fila2, &fila3);
  
}