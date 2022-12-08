#include "queue.h"

int size = 0;

void start_queue(queue **fila)
{
  *fila = (queue *)malloc(sizeof(queue));

  (*fila)->next = NULL;

  if (*fila == NULL)
  {
    perror("Nao foi possivel alocar espaco na fila");
  }
}

void add_queue(int value, queue *fila)
{
  queue *aux;
  start_queue(&aux);
  aux->value = value;
  (fila[size - 1]).next = aux;
  size++;
}