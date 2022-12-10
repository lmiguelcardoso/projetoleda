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
} Node;

typedef struct Adega {
  Node *primeiro;
  Node *ultimo;
  int qty;
} Adega;

void Order(Adega *adega) {
  Node *x = adega->primeiro;
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

void AddVine(Vinho novoVinho, Adega *Adega) {
  // primeira insercao
  if (Adega->qty == 0) {
    Node *primeiroVinho = malloc(sizeof(Node));
    primeiroVinho->vinho = novoVinho;
    Adega->primeiro = primeiroVinho;
    Adega->ultimo = primeiroVinho;
    Adega->qty++;
  } else {
    Node *newNode = malloc(sizeof(Node));
    newNode->vinho = novoVinho;
    newNode->next = NULL;
    Adega->ultimo->next = newNode;
    Adega->ultimo = newNode;
    Adega->qty++;
  }
}

void saveVine(Adega *adega, Adega *adegaOrdenada) {
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
    AddVine(novoVinho, adegaOrdenada);
    Order(adegaOrdenada);
  } else {
    AddVine(novoVinho, adega);
  }
}

void NoOcasionWine(Adega *adega) {
  Node *primeiroVinho = adega->primeiro;
  adega->primeiro = primeiroVinho->next;

  printf("=========================\n");
  printf("nome do vinho: %s\n", primeiroVinho->vinho.nome);
  printf("pais de origem: %s\n", primeiroVinho->vinho.pais);
  printf("tipo de uva: %s\n", primeiroVinho->vinho.tipoUva);
  printf("safra: %d\n", primeiroVinho->vinho.safra);
  printf("=========================\n");
}

void Print(Adega *adega) {
  Node *x;
  for (x = adega->primeiro; x != NULL; x = x->next) {
    printf("=========================\n");
    printf("nome do vinho: %s\n", x->vinho.nome);
    printf("pais de origem: %s\n", x->vinho.pais);
    printf("tipo de uva: %s\n", x->vinho.tipoUva);
    printf("safra: %d\n", x->vinho.safra);
    printf("=========================\n");
  }
}

void Print5Last(Adega *adega, Adega *adegaOrdenada) {
  Adega newAdega;
  newAdega.qty = 0;
  Node *current = adega->primeiro;
  while (current != NULL) {
    AddVine(current->vinho, &newAdega);
    Order(&newAdega);
    current = current->next;
  }

  current = adegaOrdenada->primeiro;
  while (current != NULL) {
    AddVine(current->vinho, &newAdega);
    Order(&newAdega);
    current = current->next;
  }
  current = newAdega.primeiro;
  for(int i = 0; i<5; i++){
    printf("=========================\n");
    printf("nome do vinho: %s\n", current->vinho.nome);
    printf("pais de origem: %s\n", current->vinho.pais);
    printf("tipo de uva: %s\n", current->vinho.tipoUva);
    printf("safra: %d\n", current->vinho.safra);
    printf("=========================\n");
    current = current->next;
  }
}

void Print5Lasts(Adega *adega, Adega *adegaOrdenada) {
  Adega newAdega;
  newAdega.qty = 0;
  Node *current = adega->primeiro;
  while (current != NULL) {
    AddVine(current->vinho, &newAdega);
    Order(&newAdega);
    current = current->next;
  }

  current = adegaOrdenada->primeiro;
  while (current != NULL) {
    AddVine(current->vinho, &newAdega);
    Order(&newAdega);
    current = current->next;
  }
  current = newAdega.primeiro;
  int size = newAdega.qty;
  
  for(int i = 0; i< size-5 ;i++)
    current = current->next;
  
  for(int i = 0; i<5; i++){
    printf("=========================\n");
    printf("nome do vinho: %s\n", current->vinho.nome);
    printf("pais de origem: %s\n", current->vinho.pais);
    printf("tipo de uva: %s\n", current->vinho.tipoUva);
    printf("safra: %d\n", current->vinho.safra);
    printf("=========================\n");
    current = current->next;
  }
}

int main(void) {
  __fpurge(stdin);
  Adega Adega, AdegaOrdenada;
  int opt;
  Adega.qty = 0;
  AdegaOrdenada.qty = 0;

  while (1) {
    printf("1 - Adicionar um vinho\n");
    printf("2 - Retirar vinho\n");
    printf("3 - Consultar todos os vinhos s/ ocasiao especial\n");
    printf("4 - Consultar todos os vinhos para ocasioes especiais\n");
    printf("5 - Mostrar e retirar vinho p/ ocasioes especiais com safra mais "
           "recente \n");
    printf("6 - Mostrar 5 aquisições mais antigas\n");
    printf("7 - Mostrar 5 aquisições mais recentes\n");
    scanf("%d", &opt);
    __fpurge(stdin);
    switch (opt) {
    case 1:
      saveVine(&Adega, &AdegaOrdenada);
      break;

    case 2:
      NoOcasionWine(&Adega);
      break;

    case 3:
      Print(&Adega);
      break;

    case 4:
      Print(&AdegaOrdenada);
      break;
    case 5:
      NoOcasionWine(&AdegaOrdenada);
      break;
    case 6:
      Print5Last(&Adega, &AdegaOrdenada);
      break;
    case 7:
      Print5Lasts(&Adega,&AdegaOrdenada);
      break;
    }
  }
}
