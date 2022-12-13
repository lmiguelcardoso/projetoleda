#include <stdio.h>
#include <stdlib.h>

typedef struct Vinho {
  char nome[20];
  char pais[20];
  char tipoUva[20];
  int safra;
} Vinho;

typedef struct Node {
  Vinho vinho;
  struct Node *next;
  struct Node *previous;
} Node;

typedef struct estoque {
  Node *primeiro;
  Node *ultimo;
  int qty;
} Estoque;

void Order(Estoque *estoque) {
  Node *x = estoque->primeiro;
  while (x->next != NULL) {
    if (x->vinho.safra > x->next->vinho.safra) {
      Vinho vinho1 = x->vinho;
      Vinho vinho2 = x->next->vinho;
      x->vinho = vinho2;
      x->next->vinho = vinho1;
    }
    x = x->next;
  }
}

void AddWine(Vinho novoVinho, Estoque *estoque) {
  // primeira insercao
  if (estoque->qty == 0) {
    Node *primeiroVinho = malloc(sizeof(Node));
    primeiroVinho->previous = NULL;
    primeiroVinho->vinho = novoVinho;
    estoque->primeiro = primeiroVinho;
    estoque->ultimo = primeiroVinho;
    estoque->qty++;
  } else {
    Node *newNode = malloc(sizeof(Node));
    newNode->vinho = novoVinho;
    newNode->next = NULL;
    newNode->previous = estoque->ultimo;
    estoque->ultimo->next = newNode;
    estoque->ultimo = newNode;
    estoque->qty++;
  }
}

void saveWine(Estoque *estoque, Estoque *estoqueOrdenado) {
  Vinho novoVinho;
  char isEspecial;
  printf("Digite o nome do vinho: ");
  fgets(novoVinho.nome, 20, stdin);
  printf("Digite o pais de origem: ");
  fgets(novoVinho.pais, 20, stdin);
  printf("É um vinho especial (s,n): ");
  isEspecial = getchar();
  __fpurge(stdin);
  printf("Tipo de uva: ");
  fgets(novoVinho.tipoUva, 20, stdin);
  printf("Digite a Safra: ");
  __fpurge(stdin);
  scanf("%d", &novoVinho.safra);
  if (isEspecial == 's') {
    AddWine(novoVinho, estoqueOrdenado);
    Order(estoqueOrdenado);
  } else {
    AddWine(novoVinho, estoque);
  }
}

void popWine(Estoque *estoque) {
  if(estoque->qty == 0){
    printf("Estoque Vazio!!!!\n");
    return;
  }
  Node *primeiroVinho = estoque->primeiro;
  estoque->primeiro = primeiroVinho->next;
  estoque->qty--;

  printf("=========================\n");
  printf("nome do vinho: %s\n", primeiroVinho->vinho.nome);
  printf("pais de origem: %s\n", primeiroVinho->vinho.pais);
  printf("tipo de uva: %s\n", primeiroVinho->vinho.tipoUva);
  printf("safra: %d\n", primeiroVinho->vinho.safra);
  printf("=========================\n");
}

void Print5Last(Estoque *estoque, Estoque *estoqueOrdenado) {
  Estoque newEstoque;
  newEstoque.qty = 0;
  Node *current = estoque->primeiro;
  while (current != NULL) {
    AddWine(current->vinho, &newEstoque);
    Order(&newEstoque);
    current = current->next;
  }

  current = estoqueOrdenado->primeiro;
  while (current != NULL) {
    AddWine(current->vinho, &newEstoque);
    Order(&newEstoque);
    current = current->next;
  }
  current = newEstoque.primeiro;

  for (int i = 0; i < 5; i++) {
    if (current == NULL)
      break;
    printf("=========================\n");
    printf("nome: %s\n", current->vinho.nome);
    printf("pais: %s\n", current->vinho.pais);
    printf("tipo da uva: %s\n", current->vinho.tipoUva);
    printf("safra: %d\n", current->vinho.safra);
    printf("=========================\n");
    current = current->next;
  }
}

void Print5Lasts(Estoque *estoque, Estoque *estoqueOrdenado) {
  Estoque newEstoque;
  newEstoque.qty = 0;
  Node *current = estoque->primeiro;
  while (current != NULL) {
    AddWine(current->vinho, &newEstoque);
    Order(&newEstoque);
    current = current->next;
  }

  current = estoqueOrdenado->primeiro;
  while (current != NULL) {
    AddWine(current->vinho, &newEstoque);
    Order(&newEstoque);
    current = current->next;
  }

  current = newEstoque.ultimo;
  for (int i = 0; i < 5; i++) {
    if (current == NULL)
      break;
    
    printf("=========================\n");
    printf("nome: %s\n", current->vinho.nome);
    printf("pais: %s\n", current->vinho.pais);
    printf("tipo de uva: %s\n", current->vinho.tipoUva);
    printf("safra: %d\n", current->vinho.safra);
    printf("=========================\n");
    current = current->previous;
  }
}
int main(void) {
  __fpurge(stdin);
  Estoque Estoque, EstoqueOrdenado;
  int opt;
  Estoque.qty = 0;
  EstoqueOrdenado.qty = 0;

  while (1) {
    printf("1 - Adicionar um vinho\n");
    printf("2 - Retirar vinho s/ ocasiao especial\n");
    printf("3 - Retirar vinho p/ ocasioes especiais com safra mais "
           "recente \n");
    printf("4 - Mostrar 5 aquisições mais antigas\n");
    printf("5 - Mostrar 5 aquisições mais recentes\n");
    scanf("%d", &opt);
    __fpurge(stdin);
    switch (opt) {
    case 1:
      saveWine(&Estoque, &EstoqueOrdenado);
      break;

    case 2:
      popWine(&Estoque);
      break;

    case 3:
      popWine(&EstoqueOrdenado);
      break;
    case 4:
      Print5Last(&Estoque, &EstoqueOrdenado);
      break;
    case 5:
      Print5Lasts(&Estoque, &EstoqueOrdenado);
      break;
    }
  }
}
