#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int number;
    struct Node * next;
} Node;
typedef struct Stack {
    struct Node * top;

    /* Determina a quantidade máxima de itens que a pilha pode comportar */
    int max_items;

    /* Indica a quantidade de elementos presentes na pilha */
    int qty;
} Stack;
typedef struct Queue {
    Node * head; //Nó inicial da fila
    Node * tail; //Nó final da fila
    
    /* Determina a quantidade máxima de itens que a fila pode comportar */
    int max_items;

    /* Indica a quantidade de elementos presentes na fila */
    int qty;
} Queue;


void printStack(Stack * pilha)
{
  Node * current = pilha->top;
  printf("===============================\n");
  printf("PILHA CONTEM :\n");
  printf("\t\ttopo\n");
  for(int i = 0; i<pilha->qty; i++){
    printf("%d\n",current->number);
    current = current->next;
  }
  printf("\t\tfinal\n");
  printf("===============================\n");
}
void printQueue(Queue fila)
{
    if(fila.qty == 0){
      printf("====FILA VAZIA=====\n");
      printf("Pressione enter para voltar ao menu inicial\n");
      setbuf(stdin,NULL);
      getchar();
      return;
    }
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

void insertStack(int value, Stack * pilha)
{
    if(pilha->max_items == pilha->qty && pilha->qty != 0){
        printf("PILHA CHEIA! IMPOSSIVEL ADICIONAR O ELEMENTO\n");
        return ;
    }
    Node * current = (Node *) malloc(sizeof(Node));
    current->number = value;
    current->next = pilha->top;
    pilha->top = current; 
    pilha->qty++;
}
void insertQueue(int value, Queue * fila)
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
    }else{
    current = fila->tail;
    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode->number = value;
    current->next = newNode;
    fila->tail = newNode;
    fila->qty++;
    }
}

int popStack(Stack * pilha)
{
    Node * current = pilha->top;
    int number = current->number;
    pilha->top = current->next;
    pilha->qty--;
    free(current);
    return number;
}
int popQueue(Queue * fila)
{
    Node * current = fila->head;
    int number = current->number;
    fila->head = current->next;
    fila->qty--;
  
    free(current);
    return number;
}

Stack initStack(Stack * stack){
  stack->qty = 0;
  stack->max_items = 20;
  return *stack;
}
Queue initQueue(Queue * queue){
  queue->qty = 0;
  queue->max_items = 20;
  return *queue;
}

int main(void){
  Stack pilha1 = initStack(&pilha1);
  Queue filaPar = initQueue(&filaPar);
  Queue filaImpar = initQueue(&filaImpar);
  int option;
  
  while(1){
    printf("\nDigite 0 para finalizar o armazenamento \n");
    printf("Digite um numero: ");
    scanf("%d", &option);
    if(option == 0 )
      break; 
    insertStack(option,&pilha1);
  }
  system("clear");

  printStack(&pilha1);
  Node * current = pilha1.top; 
  for(int i = 0; i<pilha1.qty;i++){
    if(current->number % 2 == 0){
      insertQueue(current->number, &filaPar);
      current = current->next;
    }else{
      insertQueue(current->number, &filaImpar);
      current = current->next;
    }
  }
  while(1){ 
    printf("1 - para acessar a pilha digitada\n");
    printf("2 - para acessar a fila de numeros impares\n");
    printf("3 - para acessar a fila de numeros pares\n");
    printf("0 - fechar sair do programa\n");
    printf("Digite uma opção: ");
    scanf("%d", &option);
    switch(option){
      case 1:
        printStack(&pilha1);
      break;
      case 2:
        printQueue(filaImpar);
      break;
      case 3:
        printQueue(filaPar);
      break;
      case 0:
      exit(0);
      break;
      default:
        printf("opção invalida!");
    }
  }
  
}

