#include "queue.h"

node *aux = NULL;
node **head = NULL;

static int size = 0;

void start_queue(queue *fila)
{
  fila->head = NULL;
  fila->tail = NULL;
}

void add_queue(int value, queue *fila)
{
  node *new_node = (node *)malloc(sizeof(node));
  if (new_node == NULL)
  {
    perror("Nao foi possivel alocar memoria");
    return;
  }
  new_node->value = value;
  new_node->next = NULL;
  if (fila->tail != NULL)
  {
    fila->tail->next = new_node;
  }
  fila->tail = new_node;
  if (fila->head == NULL)
  {
    fila->head = new_node;
  }
  // size++;
}

int erase_queue(queue *fila)
{
  if (fila->head == NULL)
    return QUEUE_EMPTY;
  node *tmp = fila->head;
  int result = tmp->value;
  fila->head = fila->head->next;
  if (fila->head == NULL)
  {
    fila->tail = NULL;
  }
  free(tmp);
  size--;
  return result;
}

void print_queue(queue *fila)
{
  aux = fila->head;
  head = &(fila->head);
  while ((*head) != NULL)
  {
    printf("%d ", (*head)->value);
    *head = fila->head->next;
  }
  puts("");
  *head = aux;
}

int retorna_tamanho_fila(void)
{
  return size;
}

int retorna(int a, int b)
{
  return a + b;
}