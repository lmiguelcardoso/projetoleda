#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int number;
    struct Node * next;
}Node;

typedef struct Queue {
    Node * head; //Nó inicial da fila
    Node * tail; //Nó final da fila

    /* Determina a quantidade máxima de itens que a fila pode comportar */
    int max_items;

    /* Indica a quantidade de elementos presentes na fila */
    int qty;
} Queue;

// - Retornar a quantidade de elementos contidos na fila
int qtdQueue(Queue fila){
  return fila.qty;
}
// - Verificar se a fila está cheia
// 0 - false 1- true
int isFull(Queue fila){
  if(fila.qty == fila.max_items){
    return 1;
  }
  return 0;
}
// - Verificar se a fila  está vazia
int isEmpty(Queue fila){
  if(fila.qty == 0){
    return 1;
  }
  return 0;
}
// - Verificar se um elemento está presente na fila
int contains(int number, Queue fila)
{
  Node * current = fila.head;

  for(int i = 0; i<fila.qty ; i++){
    if(current->number == number){
      return 1;
    }
    else{
      current = current->next;
    }
  }
    return 0;
}

// - Exibir os elementos presentes na fila
void printQueue(Queue fila)
{
    Node * current = fila.head;
    printf("================================\n");
    printf("inicio\n");
    for(int i = 0; i<fila.qty; i++){
      printf("%d\n",current->number);
      current = current->next;
    }
    printf("fim\n");
    printf("================================\n");
}
// - Inserir um elemento na fila
void insertNode(int value, Queue * fila)
{
    if(fila->max_items == fila->qty && fila->qty != 0){
        printf("FILA CHEIA! IMPOSSIVEL ADICIONAR O ELEMENTO");
        return ;
    }

    Node * current = (Node *) malloc(sizeof(Node));
    if(fila->qty == 0){
    current->number = value;
    fila->head = current;
    fila->tail = current;
    fila->qty++;
    printf("VALOR %d ADICIONADO AO FINAL DA FILA\n", fila->tail->number);
    }else{
    current = fila->tail;
    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode->number = value;
    current->next = newNode;
    fila->tail = newNode;
    fila->qty++;
    printf("VALOR %d ADICIONADO AO FINAL DA FILA\n", fila->tail->number);
    }
}
// - Retirar um elemento da fila
int popNode(Queue * fila)
{
    Node * current = fila->head;
    int number = current->number;
    fila->head = current->next;
    fila->qty--;

    free(current);
    return number;
}

int main(void) {
  Queue myQueue;
  myQueue.qty = 0;
  myQueue.max_items = 10;
  insertNode(5, &myQueue);
  insertNode(22, &myQueue);
  insertNode(123, &myQueue);
  insertNode(444, &myQueue);
  printQueue(myQueue);
  printf("%d\n", popNode(&myQueue));
  printQueue(myQueue);

  return 0;
}
