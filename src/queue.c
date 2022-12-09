#include "queue.h"

void start_queue(queue *fila)
{
  fila->head = NULL;
  fila->tail = NULL;
}

void add_queue(int value, queue *fila)
{
  node *new_node = (node *)malloc(sizeof(new_node));
  if (new_node == NULL)
  {
    perror("Nao foi possivel alocar memoria");
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
  return result;
}