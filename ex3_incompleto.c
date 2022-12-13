#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int number;
  struct node *next;
}Node;

typedef struct stack {
    struct node *top;
    int max_items;
    int qty;
}stack;

void inserir (int value, stack * pilha){
  
  if(pilha->max_items == pilha->qty && pilha->qty != 0){
      printf("pilha cheia\n");
      return ;
  }
  Node * current = (Node *) malloc(sizeof(Node));
  current->number = value;
  current->next = pilha->top;
  pilha->top = current; 
  pilha->qty++;
}

void printStack(stack * pilha)
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
int main(void) {
  stack stack1, stack2, stack3;
  Node * atual;
  stack1.qty = 0;
  stack1.max_items = 100;
  stack2.qty = 0;
  stack2.max_items = 100;
  
  inserir(2, &stack1);
  inserir(22, &stack1);
  inserir(222, &stack1);
  
  inserir(5, &stack2);
  inserir(1, &stack2);
  inserir(10, &stack2);

  atual = stack1.top;
  while(atual->next){
    inserir(atual->number,&stack3);
    atual = atual->next;
  }

  // atual = stack2.top;
  // while(atual != NULL){
  //   inserir(atual->number,&stack3);
  //   atual = atual->next;
  // }

  
  printStack(&stack3);
  return 0;
}
