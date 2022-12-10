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

// - Retornar a quantidade de elementos contidos na pilha
int stackSize(Stack pilha)
{
    return pilha.qty;
}

//- Verificar se a pilha está cheia
// 0 = false // 1 = true
int isFull(Stack pilha)
{
    if(pilha.qty == pilha.max_items){
        return 1;
    }
    return 0;
}

//- Verificar se a pilha está vazia
// 0 = false // 1 = true
int isEmpty(Stack pilha)
{
    if(pilha.qty == 0){
        return 1;
    }
    return 0;
}

//- Verificar se um elemento está presente na pilha
// 0 = false // 1 = true
int contains(int number, Stack pilha)
{
    Node * current = pilha.top;
    for(int i = 0; i<pilha.qty ; i++){
        if(current->number == number){
            return 1;
        }
        else{
            current = current->next;
        }
    }
    return 0;
}

//- Exibir os elementos presentes na pilha
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
//- Empilhar (inserir) um novo elemento na pilha
void insertNode(int value, Stack * pilha)
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
    printf("VALOR %d ADICIONADO AO FINAL DA PILHA\n", current->number);
}

//- Desempilhar (retirar) um elemento da pilha
int popNode(Stack * pilha)
{
    Node * current = pilha->top;
    int number = current->number;
    pilha->top = current->next;
    pilha->qty--;
    free(current);
    return number;
}

int main(void){
  Stack pilha;
  pilha.qty = 0;
  pilha.max_items = 10;
  insertNode(1, &pilha);
  insertNode(41, &pilha);
  insertNode(11, &pilha);
  printf("topo: %d", pilha.top->number);
  printStack(&pilha);
  popNode(&pilha);
  insertNode(666, &pilha);
  printStack(&pilha);
}

